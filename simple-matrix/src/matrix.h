#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstring>
#include <algorithm>
#include <istream>
#include <ostream>

class Matrix
{
	friend std::ostream& operator<<(std::ostream& os, const Matrix &mat);
	friend std::istream& operator>>(std::istream& is, Matrix &mat);
private:
	int r, c;
	int **data;

	void _row_bound_check(int i) const
	{
		if (i<1 || i>r)
			throw "row index out of bound";
	}

	void _col_bound_check(int j) const
	{
		if (j<1 || j>c)
			throw "colum index out of bound";
	}

	void _bound_check(int i, int j) const
	{
		_row_bound_check(i);
		_col_bound_check(j);
	}

	void _shape_check(int rows, int cols)
	{
		if (rows != r || cols != c)
			throw "shape doesn't match";
	}

	void swap(Matrix &rhs)
	{
		using std::swap;
		swap(r, rhs.r);
		swap(c, rhs.c);
		swap(data, rhs.data);
	}

public:

	//���캯��
	Matrix(const int n, const int m) :r(n), c(m), data(new int*[n])
	{
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[m];
			memset(data[i], 0, sizeof(int)*m);
		}
	}

	//�������캯��
	Matrix(const Matrix &src) :r(src.r), c(src.c), data(new int*[src.r])
	{
		for (int i = 0; i < r; i++)
		{
			data[i] = new int[c];
			memcpy(data[i], src.data[i], sizeof(int)*c);
		}
	}

	//��������
	~Matrix()
	{
		if (!data)
			return;
		else
		{
			for (int i = 0; i < r; i++)
				delete[] data[i];
			delete[] data;
			data = nullptr;// necessary or not? more safe?
		}
	}

	//�õ����������
	int nRow() const
	{
		return r;
	}

	//�õ����������
	int nCol() const
	{
		return c;
	}

	//���غ������������(),��ͨ��mat(i,j)��ʽ����Ԫ��
	int operator() (int i, int j) const //For const objects
	{
		_bound_check(i, j);
		return data[i - 1][j - 1];
	}

	int& operator() (int i, int j) //For non-const objects
	{
		_bound_check(i, j);
		return data[i - 1][j - 1];
	}

	//����C++û��[][]�����أ���Ҫһ�ֹ��ɵ��ֶ���ʵ��mat[i][j]��ʽ�ķ���
	class RowProxy
	{
		friend class Matrix;
		
	private:
		int *row_data;
		int c;

		RowProxy(int *_data, int _c) :row_data(_data), c(_c) {} //ֻϣ��RowProxy��Matrix�ഴ��
		RowProxy(const RowProxy &src) {}
		RowProxy& operator=(const RowProxy &src) {}

		void _col_bound_check_(int j) const
		{
			if (j<1 || j>c)
				throw "column index out of bound";
		}

	public:
		
		//�����±������[]�����const�����non-const����ֱ���һ���汾
		int operator[](int j) const //For const objects, no need to return reference
		{
			_col_bound_check_(j);
			return row_data[j - 1];
		}

		int& operator[](int j) //For non-const objects, need to return reference as left-value
		{
			_col_bound_check_(j);
			return row_data[j - 1];
		}
	};

	//�����±������[]����ͨ��mat[i][j]��ʽ����Ԫ��
	const RowProxy operator[](int i) const
	{
		_row_bound_check(i);
		return RowProxy(data[i - 1], c);
	}

	RowProxy operator[](int i)//�˴�ֻ����RowProxy��һ��temp copy����Ԫ�صĲ���������һ��
	{
		_row_bound_check(i);
		return RowProxy(data[i - 1], c);
	}

	//����+=�����
	Matrix& operator+=(const Matrix& rhs)
	{
		_shape_check(rhs.r, rhs.c);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				data[i][j] += rhs.data[i][j]; //consider += self

		return *this;
	}

	//���ظ�ֵ�����=���˴�����ʵ��һ�����硰Matrix& operator=(const Matrix &rhs)�������غ��������ʹ������puzzle
	Matrix& operator=(Matrix rhs)//��copying����������������׶Σ���ʱ��ʹ���������ɸ���Ч�Ĵ���
	{
		swap(rhs);//Ϊ�������Ҹ��ƣ�copy-and-swap����ʵ�ֲ�ͬ��С�ľ���ĸ�ֵ
		return *this;
	}
};

//����+�������Ϊ��ʹ�ø������Ծ���������������Ҽ���������һ���µĶ����������������Ϊȫ�ֺ���(���Զ��������)
Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
	Matrix tmp(lhs);
	tmp += rhs;
	return tmp;
}

//����==�����
bool operator==(const Matrix &lhs, const Matrix &rhs)
{
	const int n = lhs.nRow();
	const int m = lhs.nCol();

	if (rhs.nRow() != n || rhs.nCol() != m)
		return false;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (lhs(i, j) != rhs(i, j))
				return false;

	return true;
}

//���������������<<
std::ostream& operator<<(std::ostream& os, const Matrix &mat)//note:�����������<<������ȡ�����>>���뱻����Ϊȫ�ֺ�����һ�㽫��ȫ�ֺ�������Ϊ�����Ԫ��
{
	//Ϊ���ܹ������������ԭ�����أ���Ҫ���������Ϣ��e.g. ����������������������
	const int n = mat.nRow();
	const int m = mat.nCol();
	os << n << ' ' << m << std::endl;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j < m; j++)
			os << mat(i, j) << '\t';
		os << mat(i, m) << std::endl;
	}
	return os;
}

//��������ȡ�����>>
std::istream& operator>>(std::istream& is, Matrix &mat)
{
	int n, m;
	is >> n >> m;
	mat._shape_check(n, m);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			is >> mat(i, j);

	return is;
}

#endif
