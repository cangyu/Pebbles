#include <iostream>
#include <ctime>
#include <cstdlib>
#include "Disjoint Set.h"

using namespace std;

void createPuzzle(int size);

int main(int argc, char **argv)
{
	createPuzzle(3);

	system("pause");
	return 0;
}

void createPuzzle(int size)
{
	int num1, num2;
	DisjointSet ds(size*size);

	srand((unsigned int)time(0));

	while (ds.Find(0) != ds.Find(size*size - 1)) //��ںͳ��ڲ���ͨ�����������
	{
		while (true)
		{
			num1 = rand()*size*size / (RAND_MAX + 1); //���ѡ��һ����Ԫ

			//������Ϸ��ĵ�Ԫ
			num2 = num1 - size;
			if (num2 >= 0)
			{
				if (ds.Find(num1) != ds.Find(num2))
					break;
			}

			//�������ߵĵ�Ԫ
			num2 = num1 - 1;
			if (num1%size != 0)
			{
				if (ds.Find(num1) != ds.Find(num2))
					break;
			}

			//������·���Ԫ
			num2 = num1 + size;
			if (num2 < size*size)
			{
				if (ds.Find(num1) != ds.Find(num2))
					break;
			}

			//������ҷ���Ԫ
			num2 = num1 + 1;
			if (num2%size != 0)
			{
				if (ds.Find(num1) != ds.Find(num2))
					break;
			}
		}
		ds.Union(ds.Find(num1), ds.Find(num2));
		cout << '<' << num1 << ',' << num2 << ">." << endl;
	}
}

