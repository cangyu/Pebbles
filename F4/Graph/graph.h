#pragma once

#include <iostream>
#include <iomanip>
#include <queue>
#include <stack>
#include <algorithm>
#include "../Disjoint Set/Disjoint Set.h"

template<typename EdgeTypeDef>
class graph
{
protected:
	int Vers, Edges;

public:
	virtual void _bound_check(int u) const
	{
		if (u < 0 || u >= Vers)
			throw "index out of bound!\n";
	}
	virtual bool insert(int u, int v, EdgeTypeDef w) = 0;
	virtual bool remove(int u, int v) = 0;
	virtual bool exist(int u, int v) const = 0;
	virtual int numOfVer() const { return Vers; }
	virtual int numOfEdge() const { return Edges; }
	virtual void print() const = 0;
};

template<typename VerTypeDef,typename EdgeTypeDef>
class adjMatrixGraph :public graph<EdgeTypeDef>
{
private:
	EdgeTypeDef **edge;
	VerTypeDef *ver;
	EdgeTypeDef noEdge;

public:
	adjMatrixGraph(int vSize, const VerTypeDef d[], const EdgeTypeDef noEdgeFlag)
	{
		Vers = vSize;
		Edges = 0;
		noEdge = noEdgeFlag;

		//初始化存放节点的数组
		ver = new VerTypeDef[vSize];
		for (int i = 0; i < vSize; i++)
			ver[i] = d[i];

		//初始化存放边上权值或连接关系的邻接矩阵
		edge = new EdgeTypeDef*[vSize];
		for (int i = 0; i < vSize; i++)
		{
			edge[i] = new EdgeTypeDef[vSize];
			for (int j = 0; j < vSize; j++)
				edge[i][j] = noEdge;
			edge[i][i] = 0;
		}
	}

	~adjMatrixGraph()
	{
		delete[] ver;
		for (int i = 0; i < Vers; i++)
			delete[] edge[i];
		delete[] edge;
	}

	bool insert(int u, int v, EdgeTypeDef w)
	{
		_bound_check(u);
		_bound_check(v);

		if (edge[u][v] != noEdge)
			return false;

		edge[u][v] = w;
		Edges++;
		return true;
	}

	bool remove(int u, int v)
	{
		_bound_check(u);
		_bound_check(v);

		if (edge[u][v] == noEdge)
			return false;

		edge[u][v] = noEdge;
		Edges--;
		return true;
	}

	bool exist(int u, int v) const
	{
		_bound_check(u);
		_bound_check(v);

		return edge[u][v] != noEdge;
	}

	void print() const
	{
		std::cout << "Currently,the graph described in adjecent matrix is:" << std::endl;
		for (int i = 0; i < Vers; i++)
		{
			for (int j = 0; j < Vers; j++)
				std::cout <<std::setw(4)<< edge[i][j];
			std:; cout << endl;
		}
	}

	void floyd() const
	{
		EdgeTypeDef **d = new EdgeTypeDef*[Vers];
		int **prev = new int*[Vers];

		//初始化
		for (int i = 0; i < Vers; i++)
		{
			d[i] = new EdgeTypeDef[Vers];
			prev[i] = new int[Vers];

			for (int j = 0; j < Vers; j++)
			{
				d[i][j] = edge[i][j];
				prev[i][j] = edge[i][j] != noEdge ? i : -1;
			}
		}

		//迭代过程
		for (int k = 0; k < Vers; k++)
		{
			for (int i = 0; i < Vers; i++)
			{
				for (int j = 0; j < Vers; j++)
				{
					if (d[i][k] + d[k][j] < d[i][j])
					{
						d[i][j] = d[i][k] + d[k][j];
						prev[i][j] = prev[k][j];
					}
				}
			}
		}

		//输出过程
		std::cout << "最短路径信息如下(Floyd)：" << std::endl;
		std::cout << "最短路径长度：" << std::endl;
		for (int i = 0; i < Vers; i++)
		{
			for (int j = 0; j < Vers; j++)
				std::cout << setw(4) << d[i][j];
			std::cout << std::endl;
		}

		std::cout << "最短路径：" << std::endl;
		for (int i = 0; i < Vers; i++)
		{
			for (int j = 0; j < Vers; j++)
				std::cout << setw(4) << prev[i][j];
			std::cout << std::endl;
		}
	}
};

template<typename VerTypeDef,typename EdgeTypeDef>
class adjListGraph :public graph<EdgeTypeDef>
{
private:
	struct edgeNode
	{
		int end;
		EdgeTypeDef weight;
		edgeNode *next;
		edgeNode(int e, EdgeTypeDef w, edgeNode *n = NULL) :end(e), weight(w), next(n) {}
	};

	struct verNode
	{
		VerTypeDef val;
		edgeNode *head;
		verNode(edgeNode *h = NULL) :head(h) {}
	};

	struct eulerNode
	{
		int nodeNum;
		eulerNode *next;
		eulerNode(int v) :nodeNum(v), next(NULL) {}
	};

	struct edge
	{
		int begin, end;
		EdgeTypeDef w;
		edge(int b, int e, EdgeTypeDef ew) :begin(b), end(e), w(ew) {}
		bool operator<(const edge &rhs) const { return rhs.w < w; }
	};

	verNode *verList;

	void dfs_noOutput(int start, bool visited[],verNode *verSet) const
	{
		visited[start] = true;
		edgeNode *p = verSet[start].head;
		while (p)
		{
			if (!visited[p->end])
				dfs_noOutput(p->end, visited, verSet);
			p = p->next;
		}
	}

	void dfs(int start, bool visited[]) const
	{
		edgeNode *p = verList[start].head;

		std::cout << verList[start].val << '\t';
		visited[start] = true;

		while (p)
		{
			if (!visited[p->end])
				dfs(p->end, visited);
			p = p->next;
		}
	}

	void dfs(int start, bool visited[], std::stack<int> &st) const //注意声明namespace
	{
		visited[start] = true;
		edgeNode *p = verList[start].head;
		while (p)
		{
			if (!visited[p->end])
				dfs(p->end, visited, st);
			p = p->next;
		}
		st.push(start);
	}

	void dfs(int start,  bool visited[], verNode *verSet) const
	{
		edgeNode *p = verSet[start].head;

		std::cout << verSet[start].val << '\t';
		visited[start] = true;

		while (p)
		{
			if (!visited[p->end])
				dfs(p->end, visited);
			p = p->next;
		}
	}

	verNode* clone() const
	{
		verNode *tmp = new verNode[Vers];

		for (int i = 0; i < Vers; i++)
		{
			tmp[i].val = verList[i].val;
			edgeNode *p = verList[i].head;
			while (p)
			{
				tmp[i].head = new edgeNode(p->end, p->weight, tmp[i].head);
				p = p->next;
			}
		}
		return tmp;
	}

	eulerNode* eulerCircuit(int start, eulerNode* &end)//单纯地dfs，不回溯
	{
		eulerNode *begin;
		begin = end = new eulerNode(start);

		while (verList[start].head)//最后能回去
		{
			int next = verList[start].head->end;
			remove(start, next);
			remove(next, start);
			start = next;
			end->next = new eulerNode(start);
			end = end->next;
		}
		return begin;
	}

	void printPath(int begin, int end, int prev[]) const
	{
		if (begin == end)
		{
			std::cout << begin << ":" << verList[begin].val;
			return;
		}

		printPath(begin, prev[end], prev);
		std::cout << " -> " << end << ":" << verList[end].val;
	}

	adjListGraph<VerTypeDef, EdgeTypeDef>* transpose() const
	{
		VerTypeDef *v = new VerTypeDef[Vers];
		for (int i = 0; i < Vers; i++)
			v[i] = verList[i].val;

		adjListGraph<VerTypeDef, EdgeTypeDef> *res = new adjListGraph<VerTypeDef, EdgeTypeDef>(Vers, v);
		delete[] v;

		for (int i = 0; i < Vers; i++)
		{
			edgeNode *p = verList[i].head;
			while (p)
			{
				res->insert(p->end, i, p->weight);
				p = p->next;
			}
		}

		return res;
	}

	void tarjan(int u, bool inStack[],int &dfn_index,int dfn[], int low[],std::stack<int> &st) const
	{
		dfn[u] = low[u] = ++dfn_index;
		inStack[u] = true;
		st.push(u);

		edgeNode *p = verList[u].head;
		while (p)
		{
			if (dfn[p->end] == 0)
			{
				tarjan(p->end, inStack, dfn_index, dfn, low, st);
				low[u] = min(low[u], low[p->end]);
			}
			else if (inStack[p->end])
				low[u] = min(low[u], dfn[p->end]);

			p = p->next;
		}

		if (dfn[u] == low[u])
		{
			int v;
			do
			{
				v = st.top();
				st.pop();

				if (v != u)
					std::cout << v << ":" << verList[v].val << " <-> ";
				else
					std::cout << v << ":" << verList[v].val;

			} while (u != v);

			std::cout << std::endl;
		}
	}

public:

	adjListGraph(int vSize, const VerTypeDef d[])
	{
		Vers = vSize;
		Edges = 0;

		verList = new verNode[vSize];
		for (int i = 0; i < vSize; i++)
			verList[i].val = d[i];
	}

	~adjListGraph()
	{
		edgeNode *p;
		for (int i = 0; i < Vers; i++)
		{
			while (p = verList[i].head)
			{
				verList[i].head = p->next;
				delete p;
			}
		}
		delete[] verList;
	}

	bool insert(int u, int v, EdgeTypeDef w)
	{
		_bound_check(u);
		_bound_check(v);

		verList[u].head = new edgeNode(v, w, verList[u].head);
		Edges++;
		return true;
	}

	bool remove(int u, int v)
	{
		_bound_check(u);
		_bound_check(v);

		edgeNode *p = verList[u].head, *q;

		if (!p)
			return false;

		if (p->end == v)
		{
			verList[u].head = p->next;
			delete p;
			Edges--;
			return true;
		}

		while (p->next && p->next->end != v)
			p = p->next;

		if (!p->next)
			return false;
		else
		{
			q = p->next;
			p->next = q->next;
			delete q;
			Edges--;
			return true;
		}
	}

	bool exist(int u, int v) const
	{
		_bound_check(u);
		_bound_check(v);

		edgeNode *p = verList[u].head;

		while (p->next && p->next->end != v)
			p = p->next;

		return p->next != NULL;
	}

	void print() const
	{
		std::cout << "Currently,the graph described in adjecent list is:" << std::endl;
		edgeNode *p;
		for (int i = 0; i < Vers; i++)
		{
			std::cout << "顶点" << setw(3) << i << ": " << verList[i].val << " ";
			p = verList[i].head;
			while (p)
			{
				std::cout << "->" << setw(3) << p->end << ": " << verList[p->end].val << " ";
				p = p->next;
			}
			std:; cout << endl;
		}
	}

	void dfs() const
	{
		bool *visited = new bool[Vers];

		for (int i = 0; i < Vers; i++)
			visited[i] = false;

		std::cout << "当前图的深度优先遍历序列为：" << endl;

		for (int i = 0; i < Vers; i++)
		{
			if (!visited[i])
			{
				dfs(i, visited);
				std::cout << endl;
			}
		}

		delete[] visited;
	}

	void bfs() const
	{
		bool *visited = new bool[Vers];
		for (int i = 0; i < Vers; i++)
			visited[i] = false;

		queue<int> q;

		std::cout << "当前图的广度优先遍历序列为：" << endl;

		for (int i = 0; i < Vers; i++)//有可能得到多棵树，是个森林
		{
			if (visited[i])
				continue;

			q.push(i);
			while (!q.empty())
			{
				int cur = q.front();
				q.pop();

				if (visited[cur])//有可能是排在前面的子树遍历后把后面的也visit了，避免重复
					continue;

				std::cout << verList[cur].val << '\t';
				visited[cur] = true;
				edgeNode *p = verList[cur].head;
				while (p)
				{
					if (!visited[p->end])
						q.push(p->end);
					p = p->next;
				}
			}
			std::cout << endl;
		}

		delete[] visited;
	}

	void eulerCircuit(VerTypeDef start)
	{
		if (Edges == 0)
		{
			std::cout << "不存在欧拉回路！" << std::endl;
			return;
		}

		for (int i = 0; i < Vers; i++)//根据是否存在欧拉回路的充要条件判断该图是否存在欧拉回路（即每个节点的度数要为偶数）
		{
			int numOfDegree = 0;
			edgeNode *r = verList[i].head;
			while (r)
			{
				++numOfDegree;
				r = r->next;
			}
			if (numOfDegree == 0 || numOfDegree % 2 == 1)
			{
				std::cout << "不存在欧拉回路！" << std::endl;
				return;
			}
		}

		int i = 0;
		while (i != Vers && verList[i].val != start) i++;
		if (i == Vers)
		{
			std::cout << "起始点不存在！" << std::endl;
			return;
		}

		verNode *tmp = clone();

		eulerNode *begin, *end;
		begin = eulerCircuit(i, end);//寻找从i出发的路径，起点和终点分别是begin和end

		while (true)
		{
			eulerNode *p = begin;

			while (p->next)//检查是否所有边都被访问过了
			{
				if (verList[p->next->nodeNum].head)
					break;
				else
					p = p->next;
			}

			if (!p->next)//若所有边都被访问过了，则跳出
				break;

			eulerNode *q = p->next;
			eulerNode *tb, *te;
			tb = eulerCircuit(q->nodeNum, te);
			te->next = q->next;
			p->next = tb;
			delete q;
		}

		delete[] verList;//恢复原图
		verList = tmp;

		std::cout << "欧拉回路是：" << std::endl;
		std::cout << std::setw(2) << verList[begin->nodeNum].val;
		begin = begin->next;
		while (begin)
		{
			std::cout <<" ->"<<std::setw(2)<< verList[begin->nodeNum].val;
			eulerNode *p = begin;
			begin = begin->next;
			delete p;
		}
		std::cout << std::endl;
	}

	void topSort() const
	{
		queue<int> q;
		int *inDegree = new int[Vers];
		for (int i = 0; i < Vers; i++)
			inDegree[i] = 0;

		//计算每个节点的入度
		for (int i = 0; i < Vers; i++)
		{
			edgeNode *p = verList[i].head;
			while (p)
			{
				inDegree[p->end]++;
				p = p->next;
			}
		}

		//从入度为0的节点开始
		for (int i = 0; i < Vers; i++)
			if (inDegree[i] == 0)
				q.push(i);

		if (q.empty())
			std::cout << "无法进行拓扑排序！" << std::endl;
		else
			std::cout << "拓扑排序为：" << std::endl;

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();
			std::cout << verList[cur].val << "  ";
			edgeNode *p = verList[cur].head;
			while (p)
			{
				if (--inDegree[p->end] == 0)
					q.push(p->end);
				p = p->next;
			}
		}
		std::cout << std::endl;

		delete[] inDegree;
	}

	void kruskal() const
	{
		priority_queue<edge> q;

		for (int i = 0; i < Vers; i++)
		{
			edgeNode *p = verList[i].head;
			while (p)
			{
				if (i < p->end)
					q.push(edge(i, p->end, p->weight));
				p = p->next;
			}
		}

		int edgesAccepted = 0;
		DisjointSet ds(Vers);

		std::cout << "由Kruskal算法得到的MST如下：" << std::endl;

		while (edgesAccepted < Vers - 1)
		{
			edge e = q.top();
			q.pop();
			int u = ds.Find(e.begin);
			int v = ds.Find(e.end);
			if (u != v)
			{
				edgesAccepted++;
				ds.Union(u, v);
				std::cout << '(' << verList[e.begin].val << ',' << verList[e.end].val << ')' << "  ";//u和v只是表征所述的集合，不是点的下标，所以不能用u，v来取点
			}
		}
		std::cout << std::endl;
	}

	void prim(EdgeTypeDef maxWeight) const
	{
		bool *hasTaken = new bool[Vers];
		EdgeTypeDef *lowCost = new EdgeTypeDef[Vers];//表示U中节点到节点i的最小值
		int *startNode = new int[Vers];//表示从U中的哪个节点到i取得最小值

		for (int i = 0; i < Vers; i++)
		{
			hasTaken[i] = false;
			lowCost[i] = maxWeight;
		}

		int start = 0;//此处将第一个节点作为首选节点
		std::cout << "由Prim算法得到的MST如下：" << std::endl;

		for (int i = 1; i < Vers; i++)//Only counting
		{
			//更新加入的顶点所产生的影响
			edgeNode *p = verList[start].head;
			while (p)
			{
				if (!hasTaken[p->end] && lowCost[p->end]>p->weight)
				{
					lowCost[p->end] = p->weight;
					startNode[p->end] = start;
				}
				p = p->next;
			}
			hasTaken[start] = true;

			//找到下一个节点
			EdgeTypeDef minEdgeWeight = maxWeight;
			for (int j = 0; j < Vers; j++)
			{
				if (lowCost[j] < minEdgeWeight)
				{
					minEdgeWeight = lowCost[j];
					start = j;
				}
			}
			std::cout << '(' << verList[startNode[start]].val << ',' << verList[start].val << ')' << "  ";
			lowCost[start] = maxWeight;//避免死循环
		}
		std::cout << std::endl;

		delete[] hasTaken;
		delete[] startNode;
		delete[] lowCost;
	}

	void unweightedShortestPath(VerTypeDef start, EdgeTypeDef notExist) const
	{
		EdgeTypeDef *distance = new EdgeTypeDef[Vers];
		int *prev = new int[Vers];

		for (int i = 0; i < Vers; i++)
			distance[i] = notExist;

		//找到起始点
		int start_index = 0;
		while (start_index < Vers && verList[start_index].val != start) start_index++;
		if (start_index == Vers)
		{
			std::cout << "起始点不存在！" << std::endl;
			return;
		}

		distance[start_index] = 0;
		prev[start_index] = start_index;

		queue<int> q;
		q.push(start_index);

		std::cout << "从" << start_index << ":" << verList[start_index].val << " 到每个节点的非带权路径如下：" << std::endl;

		//层次遍历，确定每一层距离源点的距离
		while (!q.empty())
		{
			int u = q.front();
			q.pop();
			edgeNode *p = verList[u].head;
			while (p)
			{
				if (distance[p->end] == notExist)
				{
					distance[p->end] = distance[u] + 1;
					prev[p->end] = u;
					q.push(p->end);
				}
				p = p->next;
			}
		}

		//输出最短路径,注意处理路径不存在的情况
		for (int i = 0; i < Vers; i++)
		{
			std::cout << "从" << start_index << ":" << verList[start_index].val << " 到 " << i << ":" << verList[i].val << " 的路径长为："<<distance[i]<<"，路径为：" << std::endl;
			if (distance[i] == notExist)
				std::cout << "不可到达！";
			else
				printPath(start_index, i, prev);
			std::cout << std::endl;
		}

		delete[] distance;
		delete[] prev;
	}

	void dijkstra(VerTypeDef start, EdgeTypeDef notExist) const
	{
		bool *known = new bool[Vers];
		EdgeTypeDef *distance = new EdgeTypeDef[Vers];
		int *prev = new int[Vers];

		for (int i = 0; i < Vers; i++)
		{
			known[i] = false;
			distance[i] = notExist;
		}

		int start_index = 0;
		while (start_index < Vers && verList[start_index].val != start) //若将++写在条件判断语句中，这在最后还会多加一次
			start_index++;
		if (start == Vers)
		{
			std::cout << "起始点不存在！" << std::endl;
			return;
		}

		distance[start_index] = 0;
		prev[start_index] = start_index;


		std::cout << "从" << start_index << ":" << verList[start_index].val << " 到每个节点的带权路径如下(Dijkstra)：" << std::endl;

		for (int i = 1; i < Vers; i++)
		{
			EdgeTypeDef minWeight = notExist;
			int u = 0;
			
			for (int j = 0; j < Vers; j++)//寻找具有最短距离的节点
			{
				if (!known[j] && distance[j]!=notExist)
				{
					if (minWeight == notExist || minWeight > distance[j])
					{
						minWeight = distance[j];
						u = j;
					}
				}
			}
			known[u] = true;

			edgeNode *p = verList[u].head;
			while (p)
			{
				if (!known[p->end] && (distance[p->end] == notExist || distance[p->end] > minWeight + p->weight))
				{
					distance[p->end] = minWeight + p->weight;
					prev[p->end] = u;
				}
				p = p->next;
			}
		}

		//输出最短路径,注意处理路径不存在的情况
		for (int i = 0; i < Vers; i++)
		{
			std::cout << "从" << start_index << ":" << verList[start_index].val << " 到 " << i << ":" << verList[i].val << " 的路径长为：" << distance[i] << "，路径为：" << std::endl;
			if (distance[i] == notExist)
				std::cout << "不可到达！";
			else
				printPath(start_index, i, prev);
			std::cout << std::endl;
		}

		delete[] known;
		delete[] distance;
		delete[] prev;
	}

	void spfa(VerTypeDef start, EdgeTypeDef maxWeight) const
	{
		EdgeTypeDef *distance = new EdgeTypeDef[Vers];
		int *prev = new int[Vers];

		for (int i = 0; i < Vers; i++)
			distance[i] = maxWeight;

		int start_index = 0;
		while (start_index < Vers && verList[start_index].val != start) start_index++;
		if (start_index == Vers)
		{
			std::cout << "起始点不存在！" << std::endl;
			return;
		}
		
		std::cout << "从" << start_index << ":" << verList[start_index].val << " 到每个节点的带权路径如下(SPFA)：" << std::endl;
		
		distance[start_index] = 0;
		prev[start_index] = start_index;

		queue<int> q;
		q.push(start_index);
		while (!q.empty())
		{
			int v = q.front();
			q.pop();

			edgeNode *p = verList[v].head;
			while (p)
			{
				if (distance[v] + p->weight < distance[p->end])
				{
					distance[p->end] = distance[v] + p->weight;
					prev[p->end] = v;
					q.push(p->end);
				}
				p = p->next;
			}
		}

		for (int i = 0; i < Vers; i++)
		{
			std::cout << "从" << start_index << ":" << verList[start_index].val << " 到 " << i << ":" << verList[i].val << " 的路径长为：" << distance[i] << "，路径为：" << std::endl;
			if (distance[i] == maxWeight)
				std::cout << "路径不存在！" << std::endl;
			else
				printPath(start_index, i, prev);
			std::cout << std::endl;
		}

		delete[] distance;
		delete[] prev;
	}

	void aoe(VerTypeDef start, EdgeTypeDef notExist) const
	{
		//确定每一点的入度
		int *inDegree = new int[Vers];
		for (int i = 0; i < Vers; i++)
			inDegree[i] = 0;

		for (int i = 0; i < Vers; i++)
		{
			edgeNode *p = verList[i].head;
			while (p)
			{
				inDegree[p->end]++;
				p = p->next;
			}
		}

		//找到起始点下标
		int start_index = 0;
		while (start_index < Vers && verList[start_index].val != start) start_index++;
		if (start_index == Vers || inDegree[start_index] != 0)
		{
			std::cout << "Invalid Start Point!" << std::endl;
			return;
		}

		//拓扑排序+Dijkstra
		EdgeTypeDef *distance = new EdgeTypeDef[Vers];
		int *prev = new int[Vers];
		queue<int> q;

		q.push(start_index);

		for (int i = 0; i < Vers; i++)//一个AOE可能有多个起始
		{
			if (inDegree[i] == 0)
			{
				distance[i] = 0;
				prev[i] = i;
				if (i != start_index)
					q.push(i);
			}
			else
				distance[i] = notExist;
		}

		while (!q.empty())
		{
			int u = q.front();
			q.pop();

			edgeNode *p = verList[u].head;
			while (p)
			{
				if (distance[p->end] == notExist || distance[u] + p->weight > distance[p->end]) //这里要找的是最大值而不是最小值！！！
				{
					distance[p->end] = distance[u] + p->weight;
					prev[p->end] = u;
				}	
				
				if (--inDegree[p->end] == 0)
					q.push(p->end);

				p = p->next;
			}
		}

		//Output
		int end_index = 0, longest_time = 0;
		for (int i = 0; i < Vers; i++)
		{
			if (distance[i] > longest_time)
			{
				longest_time = distance[i];
				end_index = i;
			}
		}

		std::cout << "该AOE的关键路径长为："<<longest_time<<"，关键路径如下：" << std::endl;
		printPath(start_index, end_index, prev);
		std::cout << std::endl;

		delete[] inDegree;
		delete[] distance;
		delete[] prev;
	}

	void kosaraju() const
	{
		std::stack<int> st;
		bool *visited = new bool[Vers];
		for (int i = 0; i < Vers; i++)
			visited[i] = false;

		adjListGraph<VerTypeDef, EdgeTypeDef> *r = transpose();

		std::cout << "该图由kosaraju算法得到的强连通分量（SCC）如下：" << std::endl;

		bool *flag = new bool[Vers];
		
		for (int i = 0; i < Vers; i++)
		{
			if (!visited[i])
			{
				dfs(i, visited, st);

				for (int i = 0; i < Vers; i++)
					flag[i] = false;

				while (!st.empty())
				{
					int u = st.top();
					st.pop();

					if (!flag[u])
					{
						dfs(u, flag, r->verList);
						std::cout << std::endl;
					}
				}
			}
		}

		delete r;
		delete[] flag;
		delete[] visited;
	}

	bool isSCC_kosaraju() const
	{
		bool *visited = new bool[Vers];
		for (int i = 0; i < Vers; i++)
			visited[i] = false;

		dfs_noOutput(0, visited, verList);
		for (int i = 0; i < Vers; i++)
		{
			if (!visited[i])
				return false;
		}

		adjListGraph<VerTypeDef, EdgeTypeDef> *r = transpose();
		for (int i = 0; i < Vers; i++)
			visited[i] = false;

		dfs_noOutput(0, visited, r->verList);
		for (int i = 0; i < Vers; i++)
		{
			if (!visited[i])
				return false;
		}

		delete[] visited;
		delete[] r;
		return true;
	}

	void tarjan() const
	{
		bool *inStack = new bool[Vers];
		int *dfn = new int[Vers];
		int *low = new int[Vers];

		for (int i = 0; i < Vers; i++)
		{
			inStack[i] = false;
			dfn[i] = 0;
		}

		int d_index = 0;
		stack<int> st;

		std::cout << "该图由tarjan算法得到的强连通分量（SCC）如下：" << std::endl;

		for (int i = 0; i < Vers; i++)
		{
			if (dfn[i] == 0)
				tarjan(i, inStack, d_index, dfn, low, st);
		}

		delete[] inStack;
		delete[] dfn;
		delete[] low;
	}
};
