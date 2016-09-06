#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

int main(int argc, char** argv)
{
	adjMatrixGraph<char, int> g1(10, "abcdefghij", -1);
	g1.print();

	g1.insert(0, 5, 9);
	g1.print();

	g1.remove(0, 5);
	g1.print();

	adjListGraph<char, int> g2(6, "abcdef");
	g2.print();

	g2.insert(5, 4, 1);
	g2.insert(4, 5, 1);
	g2.insert(5, 3, 2);
	g2.insert(3, 5, 2);
	g2.insert(3, 4, 6);
	g2.insert(4, 3, 6);
	g2.insert(1, 4, 9);
	g2.insert(4, 1, 9);
	g2.insert(2, 3, 8);
	g2.insert(3, 2, 8);
	g2.insert(2, 4, 8);
	g2.insert(4, 2, 8);
	g2.insert(1, 3, 3);
	g2.insert(3, 1, 3);
	g2.insert(1, 2, 1);
	g2.insert(2, 1, 1);
	g2.insert(1, 0, 0);
	g2.insert(0, 1, 0);
	g2.insert(0, 2, 7);
	g2.insert(2, 0, 7);
	g2.print();

	g2.dfs();
	g2.bfs();
	g2.eulerCircuit('a');
	g2.kruskal();
	g2.prim(65535);

	string courses[7] = { "数学", "程序设计", "离散数学", "软件工程", "数据结构", "数据库", "编译原理" };
	adjListGraph<string, int> g3(7, courses);

	g3.insert(0, 1, 1);
	g3.insert(0, 2, 1);
	g3.insert(1, 3, 1);
	g3.insert(1, 4, 1);
	g3.insert(1, 5, 1);
	g3.insert(2, 4, 1);
	g3.insert(2, 6, 1);
	g3.insert(4, 5, 1);
	g3.insert(4, 6, 1);
	g3.insert(5, 3, 1);

	g3.topSort();
	g3.unweightedShortestPath("数据结构", -1);

	adjListGraph<char, int> g4(7, "abcdefg");
	g4.insert(0, 1, 2);
	g4.insert(0, 3, 1);
	g4.insert(1, 3, 3);
	g4.insert(1, 4, 10);
	g4.insert(2, 0, 4);
	g4.insert(2, 5, 5);
	g4.insert(3, 2, 2);
	g4.insert(3, 4, 2);
	g4.insert(3, 5, 8);
	g4.insert(3, 6, 4);
	g4.insert(4, 6, 6);
	g4.insert(6, 5, 1);

	g4.dijkstra('d',-1);
	g4.spfa('d',65535);

	adjMatrixGraph<char, int> g5(3, "abc", 65535);
	g5.insert(0, 2, 5);
	g5.insert(2, 0, 6);
	g5.insert(0, 1, 8);
	g5.insert(1, 0, 3);
	g5.insert(2, 1, 2);

	g5.floyd();

	adjListGraph<char, int> g6(7, "abcdefg");
	g6.insert(0, 1, 2);
	g6.insert(0, 3, 1);
	g6.insert(1, 3, 3);
	g6.insert(1, 4, 10);
	g6.insert(2, 0, 4);
	g6.insert(2, 5, 3);
	g6.insert(3, 2, 2);
	g6.insert(3, 4, 2);
	g6.insert(3, 5, -8);
	g6.insert(3, 6, 4);
	g6.insert(4, 6, 6);
	g6.insert(6, 5, 1);

	g6.spfa('c', 65535);

	adjListGraph<char, int> g7(6, "abcdef");
	g7.insert(0, 1, 1);
	g7.insert(0, 2, 3);
	g7.insert(0, 3, 5);
	g7.insert(1, 2, 1);
	g7.insert(2, 3, 1);
	g7.insert(1, 4, 2);
	g7.insert(2, 5, 2);
	g7.insert(3, 5, 2);
	g7.insert(3, 4, 1);
	g7.insert(4, 5, 2);

	g7.aoe('a', -1);

	adjListGraph<char, int> g8(4, "ABCD");
	g8.insert(0, 1, 1);
	g8.insert(0, 2, 1);
	g8.insert(2, 0, 1);
	g8.insert(2, 3, 1);
	g8.insert(2, 3, 1);
	g8.insert(3, 0, 1);

	if (g8.isSCC_kosaraju())
		cout << "该图是强连通图！" << endl;
	else
		cout << "该图不是强连通图！" << endl;

	g8.kosaraju();

	g8.tarjan();


	//关于多态的测试
	graph<int> *g;

	g = &g1;
	g->print();

	g = &g2;
	g->print();

	g = &g3;
	g->print();

	g = &g4;
	g->print();

	g = &g5;
	g->print();

	system("pause");
	return 0;
}

