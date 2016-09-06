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

	//构造函数
	Matrix(const int n, const int m) :r(n), c(m), data(new int*[n])
	{
		for (int i = 0; i < n; i++)
		{
			data[i] = new int[m];
			memset(data[i], 0, sizeof(int)*m);
		}
	}

	//拷贝构造函数
	Matrix(const Matrix &src) :r(src.r), c(src.c), data(new int*[src.r])
	{
		for (int i = 0; i < r; i++)
		{
			data[i] = new int[c];
			memcpy(data[i], src.data[i], sizeof(int)*c);
		}
	}

	//析构函数
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

	//得到矩阵的行数
	int nRow() const
	{
		return r;
	}

	//得到矩阵的列数
	int nCol() const
	{
		return c;
	}

	//重载函数调用运算符(),可通过mat(i,j)形式访问元素
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

	//由于C++没有[][]的重载，需要一种过渡的手段来实现mat[i][j]形式的访问
	class RowProxy
	{
		friend class Matrix;
		
	private:
		int *row_data;
		int c;

		RowProxy(int *_data, int _c) :row_data(_data), c(_c) {} //只希望RowProxy由Matrix类创建
		RowProxy(const RowProxy &src) {}
		RowProxy& operator=(const RowProxy &src) {}

		void _col_bound_check_(int j) const
		{
			if (j<1 || j>c)
				throw "column index out of bound";
		}

	public:
		
		//重载下标运算符[]，针对const对象和non-const对象分别有一个版本
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

	//重载下标运算符[]，可通过mat[i][j]形式访问元素
	const RowProxy operator[](int i) const
	{
		_row_bound_check(i);
		return RowProxy(data[i - 1], c);
	}

	RowProxy operator[](int i)//此处只返回RowProxy的一个temp copy，对元素的操作留待下一步
	{
		_row_bound_check(i);
		return RowProxy(data[i - 1], c);
	}

	//重载+=运算符
	Matrix& operator+=(const Matrix& rhs)
	{
		_shape_check(rhs.r, rhs.c);
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
				data[i][j] += rhs.data[i][j]; //consider += self

		return *this;
	}

	//重载赋值运算符=，此处若还实现一个形如“Matrix& operator=(const Matrix &rhs)”的重载函数，则会使编译器puzzle
	Matrix& operator=(Matrix rhs)//将copying动作移至参数构造阶段，有时能使编译器生成更高效的代码
	{
		swap(rhs);//为避免自我复制，copy-and-swap，可实现不同大小的矩阵的赋值
		return *this;
	}
};

//重载+运算符，为了使用更加灵活，对具有两个运算对象并且计算结果产生一个新的对象的运算符最好重载为全局函数(可自动构造对象)
Matrix operator+(const Matrix &lhs, const Matrix &rhs)
{
	Matrix tmp(lhs);
	tmp += rhs;
	return tmp;
}

//重载==运算符
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

//重载流插入运算符<<
std::ostream& operator<<(std::ostream& os, const Matrix &mat)//note:流插入运算符<<与流提取运算符>>必须被重载为全局函数，一般将此全局函数声明为类的友元。
{
	//为了能够将输出的数据原样读回，需要输出控制信息（e.g. 行数，列数）来引导程序
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

//重载流提取运算符>>
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
