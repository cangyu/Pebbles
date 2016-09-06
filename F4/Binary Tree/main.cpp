#include<iostream>
#include "BinaryTree.h"

using namespace std;

int main(int argc, char **argv)
{
	BinaryTree<char> bt, bt1('M'), bt2;

	bt.createTree('@');
	bt.setTraversalType(morris);
	cout << "高度为：" << bt.height() << endl;
	cout << "规模为：" << bt.size() << endl;
	bt.preOrder();
	bt.midOrder();
	bt.postOrder();

	bt2.makeTree('Y', bt, bt1);
	bt2.setTraversalType(iterative);
	cout << endl;
	cout << "高度为：" << bt2.height() << endl;
	cout << "规模为：" << bt2.size() << endl;
	bt2.preOrder();
	bt2.midOrder();
	bt2.postOrder();


	system("pause");
	return 0;
}