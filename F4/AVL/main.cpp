#include<iostream>
#include<cstdlib>
#include<ctime>
#include "AVL.h"

using namespace std;

const int test_num = 10;

//AVL树中的元素不重复
int main(int argc, char **argv)
{
	AVL<int> a1;
	int test[test_num];
	srand((int)time(0));

	for (int i = 0; i < test_num; i++)
	{
		test[i] = rand() % test_num;
		a1.insert(test[i]);
	}

	for (int i = 0; i < test_num; i++)
	{
		cout << "find "<<i<<" is: " << (a1.find(i) ? "true" : "false") << endl;
		a1.remove(i);
		cout << "after delete "<<i<<" ,find "<<i<<" is: " << (a1.find(i) ? "true" : "false") << endl;
	}

	system("pause");
	return 0;
}