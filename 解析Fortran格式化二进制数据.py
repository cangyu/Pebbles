import os
import time
import numpy as np
from matplotlib import pyplot as plt

data_filename = 'data'
grid_filename = 'grid'

float_size = 8
int_size = 4


def load_bin_fp_dat(fp):
    [cnt1] = np.fromfile(fp, '>i4', 1)
    elem_num = cnt1 // float_size
    t = np.fromfile(fp, '>f8', elem_num)
    [cnt2] = np.fromfile(fp, '>i4', 1)
    assert (cnt1 == cnt2)
    print('{} fp have been read'.format(elem_num))
    return t


def load_bin_int_dat(fp):
    [cnt1] = np.fromfile(fp, '>i4', 1)
    elem_num = cnt1 // int_size
    t = np.fromfile(fp, '>i4', elem_num)
    [cnt2] = np.fromfile(fp, '>i4', 1)
    assert (cnt1 == cnt2)
    print('{} int have been read'.format(elem_num))
    return t


def wrt_grid_coordinate(fp, c):
    for k in range(c.shape[0]):
        for j in range(c.shape[1]):
            for i in range(c.shape[2]):
                fp.write('{} '.format(c[k][j][i]))
            fp.write('\n')


if __name__ == '__main__':
    '''
        read data
    '''
    fin = open(data_filename, 'rb')
    [ni, nj, nk, n_var] = load_bin_int_dat(fin)
    print(ni, nj, nk, n_var)
    total_elem = ni * nj * nk
    print('Total num of elements for single var: {}'.format(total_elem))
    total_byte = float_size * total_elem
    print('Total num of bytes for single var: {}'.format(total_byte))
    rho_option = 1
    n_scalar = (n_var - 5 - 2 * rho_option) // 2

    [u, v, w, p, vt] = [load_bin_fp_dat(fin) for k in range(5)]
    at = [load_bin_fp_dat(fin) for k in range(n_scalar)]
    sc = [load_bin_fp_dat(fin) for k in range(n_scalar)]
    [rho, d_rho] = [load_bin_fp_dat(fin) for k in range(2)]

    assert (os.path.getsize(data_filename) == fin.tell())
    fin.close()

    '''
        read grid
    '''
    fin = open(grid_filename, 'rb')
    [nx, ny, nz] = load_bin_int_dat(fin)
    print(nx, ny, nz)
    [x, y, z] = [load_bin_fp_dat(fin) for k in range(3)]
    i_cyl = load_bin_int_dat(fin)

    assert (os.path.getsize(grid_filename) == fin.tell())
    fin.close()

    '''
        re-shape
    '''
    var_shape = (nk, nj, ni)
    u.shape = var_shape
    v.shape = var_shape
    w.shape = var_shape
    p.shape = var_shape
    vt.shape = var_shape
    for k in range(n_scalar):
        at[k].shape = var_shape
        sc[k].shape = var_shape
    rho.shape = var_shape
    d_rho = var_shape
    x.shape = var_shape
    y.shape = var_shape
    z.shape = var_shape
    i_cyl.shape = var_shape

    '''
        original grid output
    '''
    x_ghost_cnt = 1
    y_ghost_cnt = 1
    z_ghost_cnt = 2

    xr = np.array(x[:-z_ghost_cnt, :-y_ghost_cnt, :-x_ghost_cnt])
    yr = np.array(y[:-z_ghost_cnt, :-y_ghost_cnt, :-x_ghost_cnt])
    zr = np.array(z[:-z_ghost_cnt, :-y_ghost_cnt, :-x_ghost_cnt])

    print('x range: {:>8.3f} <--> {:>8.3f}'.format(xr.min(), xr.max()))
    print('y range: {:>8.3f} <--> {:>8.3f}'.format(yr.min(), yr.max()))
    print('z range: {:>8.3f} <--> {:>8.3f}'.format(zr.min(), zr.max()))

    xr_cnt = nx - x_ghost_cnt
    yr_cnt = ny - y_ghost_cnt
    zr_cnt = nz - z_ghost_cnt

    ts = time.clock()
    p3d = open('grid_original.xyz', 'w')
    p3d.write('{}\n'.format(1))
    p3d.write('{} {} {}\n'.format(xr_cnt, yr_cnt, zr_cnt))
    wrt_grid_coordinate(p3d, xr)
    wrt_grid_coordinate(p3d, yr)
    wrt_grid_coordinate(p3d, zr)
    p3d.close()
    print('Grid generation done, {:.3f}s'.format(time.clock() - ts))

    '''
        grid expand
    '''
    xL = 450.0
    xGrowth = 1.05
    xBaseStp = 5.0
    xN = 1 + int(np.log2(xL / xBaseStp * (xGrowth - 1) + 1) / np.log2(xGrowth))

    yL = 350
    yGrowth = 1.1
    yBaseStp = 30
    yN = int(np.log2(yL / yBaseStp * (yGrowth - 1) + 1) / np.log2(yGrowth))

    xn_dim = xr_cnt + xN
    yn_dim = yr_cnt + yN
    zn_dim = zr_cnt

    xnc = np.zeros(xn_dim)
    for i in range(xr_cnt):
        xnc[i] = xr[0][0][i]
    for i in range(xr_cnt, len(xnc)):
        xnc[i] = xnc[i - 1] + xBaseStp * xGrowth ** (i - xr_cnt)
    xnc[-1] = 900

    ync = np.zeros(yn_dim)
    for j in range(yr_cnt):
        ync[j] = yr[0][j][0]
    for j in range(yr_cnt, len(ync)):
        ync[j] = ync[j - 1] + yBaseStp * yGrowth ** (j - yr_cnt)
    ync[-1] = 700

    znc = np.linspace(0, 2 * np.pi, zn_dim, endpoint=False)

    # plt.plot(xnc)
    # plt.savefig('x_spacing.png')
    # plt.plot(ync)
    # plt.savefig('y_spacing.png')
    # plt.plot(znc)
    # plt.savefig('z_spacing.png')

    cn_shp = (zn_dim, yn_dim, xn_dim)
    xn = np.zeros(cn_shp, float)
    yn = np.zeros(cn_shp, float)
    zn = np.zeros(cn_shp, float)

    ts = time.clock()
    for k in range(zn_dim):
        for j in range(yn_dim):
            for i in range(xn_dim):
                xn[k][j][i] = xnc[i]
                yn[k][j][i] = ync[j] * np.cos(znc[k])
                zn[k][j][i] = ync[j] * np.sin(znc[k])
    print('Coordinate calculation done, {:.3f}s'.format(time.clock() - ts))

    ts = time.clock()
    p3d = open('grid_expand.xyz', 'w')
    p3d.write('{}\n'.format(1))
    p3d.write('{} {} {}\n'.format(xn_dim, yn_dim, zn_dim))
    wrt_grid_coordinate(p3d, xn)
    wrt_grid_coordinate(p3d, yn)
    wrt_grid_coordinate(p3d, zn)
    p3d.close()
    print('Grid generation done, {:.3f}s'.format(time.clock() - ts))

    ts = time.clock()
    assert np.isclose(xr, xn[:zr_cnt, :yr_cnt, :xr_cnt]).all()
    assert np.isclose(yr, yn[:zr_cnt, :yr_cnt, :xr_cnt]).all()
    assert np.isclose(zr, zn[:zr_cnt, :yr_cnt, :xr_cnt]).all()
    print('Compare done, {:.3f}s'.format(time.clock() - ts))

    '''
        data expand
    '''