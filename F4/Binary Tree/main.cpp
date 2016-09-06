#include<iostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char **argv)
{
	BinaryTree<char> bt, bt1('M'), bt2;

	bt.createTree('@');
	bt.setTraversalType(morris);
	cout << "�߶�Ϊ��" << bt.height() << endl;
	cout << "��ģΪ��" << bt.size() << endl;
	bt.preOrder();
	bt.midOrder();
	bt.postOrder();

	bt2.makeTree('Y', bt, bt1);
	bt2.setTraversalType(iterative);
	cout << endl;
	cout << "�߶�Ϊ��" << bt2.height() << endl;
	cout << "��ģΪ��" << bt2.size() << endl;
	bt2.preOrder();
	bt2.midOrder();
	bt2.postOrder();


	system("pause");
	return 0;
}