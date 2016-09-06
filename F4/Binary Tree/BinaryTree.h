#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <utility>

enum TraversalType {recursive,iterative,morris};

//主要是学习3种不同的遍历方法，每种遍历方法又有3种不同的实现方式：
//递归最简洁明了，迭代要注意理解其中invariant，结点出栈的次数是有意义的
//morris遍历核心是要让结点在遍历完子树后能找回来，前序和中序还好，后序略麻烦

template<typename T>
class BinaryTree
{
private:
	struct Node
	{
		Node *left, *right;
		T data;
		Node() :left(nullptr), right(nullptr) {}
		Node(T item, Node *l = nullptr, Node *r = nullptr) :data(item), left(l), right(r) {}
		~Node() {}
	};

	Node *root;
	TraversalType type;
public:
	BinaryTree() :root(nullptr),type(recursive) {}
	BinaryTree(const T &val) :root(new Node(val)), type(recursive){}
	~BinaryTree() { clear(); }

	T getRoot() const { return root->data; }
	T getLeft() const { return root->left->data; }
	T getRight() const { return root->right->data; }

	void makeTree(const T &x, BinaryTree &lt, BinaryTree &rt)
	{
		root = new Node(x, lt.root, rt.root);
		lt.root = nullptr;
		rt.root = nullptr;
	}

	void delLeft()
	{
		BinaryTree tmp = root->left;// acceptable?
		root->left = nullptr;
		tmp.clear();
	}

	void delRight()
	{
		BinaryTree tmp = root->right;
		root->right = nullptr;
		tmp.clear();
	}

	bool isEmpty() const { return root == nullptr; }

	void clear()
	{
		if (root)
			clear(root);
		root = nullptr;
	}

	int size() const {	return size(root);	}

	int height() const { return height(root); }

	TraversalType getTraversalType() const { return type; }

	void setTraversalType(TraversalType t) { type = t; }

	void preOrder() const;

	void midOrder() const;

	void postOrder();

	void createTree(T flag);

private:

	int height(Node *t) const { return t ? 1 + max(height(t->left), height(t->right)) : 0; }

	void clear(Node *t)
	{
		if (t->left)
			clear(t->left);
		if (t->right)
			clear(t->right);
		delete t;
	}

	int size(Node *t) const { return t ? 1 + size(t->left) + size(t->right) : 0; }

	void visit(Node *t) const { std::cout << t->data << ' '; }

	void reverseVisit(Node *src, Node *dest);

	void reverseRight(Node *start, Node *end);

	void preOrder_recursive(Node *root) const;

	void midOrder_recursive(Node *root) const;

	void postOrder_recursive(Node *root) const;


	void preOrder_iterative(Node *root) const;

	void midOrder_iterative(Node *root) const;

	void postOrder_iterative(Node *root) const;


	void preOrder_morris(Node *root) const;

	void midOrder_morris(Node *root) const;

	void postOrder_morris(Node *root);
};


template<typename T>
void BinaryTree<T>::preOrder() const
{
	if (root)
	{
		cout << endl << "preorder traversal:" << endl;
		switch (type)
		{
		case recursive:
			preOrder_recursive(root);
			break;
		case iterative:
			preOrder_iterative(root);
			break;
		case morris:
			preOrder_morris(root);
			break;
		default:
			std::cout << "Invalid configuration of traversal type!" << endl;
			break;
		}
	}
}

template<typename T>
void BinaryTree<T>::midOrder() const
{
	if (root)
	{
		std::cout << endl << "midorder traversal:" << endl;
		switch (type)
		{
		case recursive:
			midOrder_recursive(root);
			break;
		case iterative:
			midOrder_iterative(root);
			break;
		case morris:
			midOrder_morris(root);
			break;
		default:
			std::cout << "Invalid configuration of traversal type!" << endl;
			break;
		}
	}
}

template<typename T>
void BinaryTree<T>::postOrder()
{
	if (root)
	{
		std::cout << endl << "postorder traversal:" << endl;
		switch (type)
		{
		case recursive:
			postOrder_recursive(root);
			break;
		case iterative:
			postOrder_iterative(root);
			break;
		case morris:
			postOrder_morris(root);
			break;
		default:
			std::cout << "Invalid configuration of traversal type!" << endl;
			break;
		}
	}
}

template<typename T>
void BinaryTree<T>::preOrder_recursive(Node *root) const
{
	if (root)
	{
		visit(root);
		preOrder_recursive(root->left);
		preOrder_recursive(root->right);
	}
}

template<typename T>
void BinaryTree<T>::midOrder_recursive(Node *root) const
{
	if (root)
	{
		midOrder_recursive(root->left);
		visit(root);
		midOrder_recursive(root->right);
	}
}

template<typename T>
void BinaryTree<T>::postOrder_recursive(Node *root) const
{
	if (root)
	{
		postOrder_recursive(root->left);
		postOrder_recursive(root->right);
		visit(root);
	}
}

template<typename T>
void BinaryTree<T>::createTree(T flag)
{
	queue<Node*> q;
	Node *tmp;
	T x, ldata, rdata;

	std::cout << "\n输入根节点：";
	std::cin >> x;
	root = new Node(x);
	q.push(root);

	while (!q.empty())
	{
		tmp = q.front();
		q.pop();
		std::cout << "\n输入" << tmp->data << "的两个儿子（" << flag << "表示空节点）：";
		std::cin >> ldata >> rdata;
		if (ldata != flag)
			q.push(tmp->left = new Node(ldata));
		if (rdata != flag)
			q.push(tmp->right = new Node(rdata));
	}

	std::cout << "\ncreate completed!\n";
}

template<typename T>
void BinaryTree<T>::preOrder_iterative(Node *r) const
{
	stack<Node*> st;
	Node *cur;

	st.push(r);
	while (!st.empty())
	{
		cur = st.top(); st.pop();
		visit(cur);
		if (cur->right)
			st.push(cur->right);
		if (cur->left)
			st.push(cur->left);
	}
}

template<typename T>
void BinaryTree<T>::midOrder_iterative(Node *r) const //每次push一个进去，代表要visit这个子树
{
	stack<pair<Node*, int> > st;
	pair<Node*, int> cur;

	st.push(make_pair(r, 0));
	while (!st.empty())
	{
		cur = st.top(); st.pop();
		++cur.second;
		if (cur.second == 1)
		{
			st.push(cur);
			if (cur.first->left)
				st.push(make_pair(cur.first->left, 0));
		}
		else if (cur.second == 2)
		{
			visit(cur.first);
			if (cur.first->right)
				st.push(make_pair(cur.first->right,0));
		}
	}

}

template<typename T>
void BinaryTree<T>::postOrder_iterative(Node *r) const
{
	stack<pair<Node*, int> > st;
	pair<Node*, int> cur;

	st.push(make_pair(r, 0));
	while (!st.empty())
	{
		cur = st.top(); st.pop();
		++cur.second;

		if (cur.second == 1)
		{
			st.push(cur);
			if (cur.first->left)
				st.push(make_pair(cur.first->left, 0));
		}
		else if (cur.second == 2)
		{
			st.push(cur);
			if (cur.first->right)
				st.push(make_pair(cur.first->right, 0));
		}
		else if (cur.second == 3)
			visit(cur.first);
	}
}

template<typename T>
void BinaryTree<T>::preOrder_morris(Node *r) const
{
	Node *cur = r, *pre = nullptr;
	while (cur)
	{
		if (cur->left == nullptr)
		{
			visit(cur);
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right && pre->right != cur)
				pre = pre->right;
			if (pre->right == nullptr)
			{
				visit(cur);
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = nullptr;
				cur = cur->right;
			}
		}

	}
}

template<typename T>
void BinaryTree<T>::midOrder_morris(Node *r) const
{
	Node *cur = r, *pre = nullptr;
	while (cur)
	{
		if (cur->left == nullptr)
		{
			visit(cur);
			cur = cur->right;
		}
		else
		{
			pre = cur->left;
			while (pre->right && pre->right != cur)
				pre = pre->right;

			if (pre->right == nullptr)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				pre->right = nullptr;
				visit(cur);
				cur = cur->right;
			}
		}
	}
}

template<typename T>
void BinaryTree<T>::postOrder_morris(Node *r)
{
	Node dump; 
	dump.left = r;
	Node *cur = &dump, *pre = nullptr;

	while (cur)
	{
		if (cur->left == nullptr)
			cur = cur->right;
		else
		{
			pre = cur->left;
			while (pre->right && pre->right != cur)
				pre = pre->right;

			if (pre->right == nullptr)
			{
				pre->right = cur;
				cur = cur->left;
			}
			else
			{
				reverseVisit(cur->left, pre);
				pre->right = nullptr;
				cur = cur->right;
			}
		}
	}
}

template<typename T>
void BinaryTree<T>::reverseVisit(Node *src, Node *dest)
{
	reverseRight(src, dest);
	Node *p = dest;
	while (p != src)
	{
		visit(p);
		p = p->right;
	}
	visit(p);
	reverseRight(dest, src);
}

template<typename T>
void BinaryTree<T>::reverseRight(Node *start, Node *end)
{
	Node *x = start, *y = start->right, *z;
	while (x != end)
	{
		z = y->right;
		y->right = x;
		x = y;
		y = z;
	}
}