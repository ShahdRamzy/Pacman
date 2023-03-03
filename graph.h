#pragma once
#pragma once
#include<vector>
#include <iostream>
#include<list>
#include<SFML/Graphics.hpp>
#include <iostream>
#define INF 1000000
using namespace std;
typedef pair<int, int> vertex;
class node {
	public :list<vertex> list;
	        int distanceFromStrat=INF;
	        sf::Vector2i posnodes;
	        node* previous;
			string n;
};
typedef vector<node> AdjacencyListType;
const int nodes = 44;
class graph
{
public:
	graph();
	void inputAdjacencyList();
	void setcoordinates();
	//void setXY(int source, int dest, int weight);
	void copying(vector<node>& copy);
    void setname();
	vector<int> shortestPath(int start, int dest);
    AdjacencyListType adj;
};