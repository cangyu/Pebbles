#ifndef _DISJOINT_SET_H
#define _DISJOINT_SET_H

class DisjointSet //This is zero-based.
{
private:
	int size;
	int *parent;
	
public:
	DisjointSet(int n) :size(n), parent(new int[n])
	{
		for (int i = 0; i < n; i++)//���ø�ֵ��Ϊ�������ۼ�
			parent[i] = -1;
	}
	~DisjointSet() { delete[] parent; }
	void Union(int root1, int root2)
	{
		if (root1 == root2)
			return;
		if (parent[root1] > parent[root2])//�������ٵ���ӵ������������
		{
			parent[root2] += parent[root1];
			parent[root1] = root2;
		}
		else
		{
			parent[root1] += parent[root2];
			parent[root2] = root1;
		}
	}
	int Find(int x)
	{
		if (parent[x] < 0)
			return x;
		else
			return parent[x] = Find(parent[x]);
	}
};

#endif
