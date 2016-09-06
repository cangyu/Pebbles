#pragma once
#include<iostream>
#include<algorithm>

template<typename T>
class AVL
{
private:
	struct avlNode
	{
		T data;
		avlNode *left;
		avlNode *right;
		int height;
		avlNode(const T &elem, avlNode *lt, avlNode *rt, int h = 0) :data(elem), left(lt), right(rt), height(h) {}
	};

	avlNode *root;

	void insert(const T &x, avlNode* &t);
	bool remove(const T &x, avlNode* &t);
	void makeEmpty(avlNode* &t);
	int height(avlNode* t) const { return t == nullptr ? -1 : t->height; }
	void LL(avlNode* &t);
	void LR(avlNode* &t);
	void RL(avlNode* &t);
	void RR(avlNode* &t);

public:
	AVL(avlNode *t = nullptr) :root(t) {}
	~AVL() { makeEmpty(root); }
	bool find(const T &x) const;
	void insert(const T &x) { insert(x, root); }
	void remove(const T &x) { remove(x, root); }
};

template<typename T>
bool AVL<T>::find(const T &x) const
{
	avlNode *t = root;
	while (t && t->data != x)
	{
		if (x < t->data)
			t = t->left;
		else
			t = t->right;
	}
	return t != nullptr;
}

//若要插入的元素已经存在，则退出
template<typename T>
void AVL<T>::insert(const T &x, avlNode* &t)
{
	if (!t)
		t = new avlNode(x, nullptr, nullptr);

	if (x < t->data)
	{
		insert(x, t->left);
		if (height(t->left) - height(t->right) == 2)
		{
			if (x < t->left->data)
				LL(t);
			else
				LR(t);
		}
	}
	else if (x>t->data)
	{
		insert(x, t->right);
		if (height(t->right) - height(t->left) == 2)
		{
			if (x > t->right->data)
				RR(t);
			else
				RL(t);
		}
	}

	t->height = max(height(t->left), height(t->right)) + 1;
}

template<typename T>
void AVL<T>::LL(avlNode* &t)
{
	avlNode *tl = t->left;
	t->left = tl->right;
	tl->right = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	tl->height = max(height(tl->left), height(tl->right)) + 1;
	t = tl;
}

template<typename T>
void AVL<T>::RR(avlNode* &t)
{
	avlNode *tr = t->right;
	t->right = tr->left;
	tr->left = t;
	t->height = max(height(t->left), height(t->right)) + 1;
	tr->height = max(height(tr->left), height(tr->right)) + 1;
	t = tr;
}

template<typename T>
void AVL<T>::LR(avlNode* &t)
{
	RR(t->left);
	LL(t);
}

template<typename T>
void AVL<T>::RL(avlNode* &t)
{
	LL(t->right);
	RR(t);
}

//删除操作分3类，主要是要调整
//若要删除的元素不存在，则程序仍为该元素已被删除，返回true
template<typename T>
bool AVL<T>::remove(const T &x, avlNode* &t)
{
	bool finish = false;
	bool deleteOnLeft;

	if (!t)
		return true;

	if (x < t->data)
	{
		finish = remove(x, t->left);
		deleteOnLeft = true;
	}
	else if (x>t->data)
	{
		finish = remove(x, t->right);
		deleteOnLeft = false;
	}
	else
	{
		if (t->left && t->right)//有两个孩子，处理方法类似于BST，找“替身”
		{
			avlNode *tmp = t->left;
			while (tmp->right)
				tmp = tmp->right;
			t->data = tmp->data;
			finish = remove(tmp->data, t->left);
			deleteOnLeft = true;
		}
		else
		{
			avlNode *old = t;
			t = t->left ? t->left : t->right;
			delete old;
			return false;//还要调整顺序
		}
	}

	if (finish)
		return true;

	if (deleteOnLeft)
	{
		int balance_factor = height(t->left) - height(t->right) + 1;//这里的height(t->left)是已经删掉了目标节点的左子树的高度，所以要加上一个1来compensate
		if (balance_factor == 0)// 原来子树是平衡的，不需要继续调整
			return true;
		if (balance_factor == 1)// 删除在较高的子树上
			return false;// Although the delete operation is performed on the heigher subtree, the effect will still pass up to it's parent, so the examination of balance should be continued.
		if (balance_factor == -1)// 删除在较矮的子树上
		{
			int bfr = height(t->right->left) - height(t->right->right);//较高的子树的平衡度，这里是右子树的，下面的旋转操作由它决定
			switch (bfr)
			{
			case 0:
				RR(t); return true; //此时高度不发生变化，可以finish
			case -1:
				RR(t); return false;
			case 1:
				RL(t); return false;
			default:
				std::cerr << "Fatal error!" << endl;
				return true;
			}
		}
	}
	else
	{
		int balance_factor = height(t->left) - height(t->right) - 1;
		if (balance_factor == 0)
			return true;
		if (balance_factor == -1)
			return false;
		if (balance_factor == 1)
		{
			int bfl = height(t->left->left) - height(t->left->right);
			switch (bfl)
			{
			case 0:
				LL(t); return true;//此时高度不发生变化，可以finish
			case 1:
				LL(t); return false;//此时高度发生变化，需要继续检查平衡性
			case -1:
				LR(t); return false;//此时高度发生变化，需要继续检查平衡性
			default:
				std::cerr << "Fatal error!" << endl;
				return true;
			}
		}
	}
}

template<typename T>
void AVL<T>::makeEmpty(avlNode* &r)
{
	if (!r)//有可能因为remove操作使得树为空！
		return;

	if (r->left)
		makeEmpty(r->left);
	if (r->right)
		makeEmpty(r->right);
	delete r;
}
