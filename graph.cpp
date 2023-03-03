#include "graph.h"
#include <list>
#include <utility>
#include <set>
#include <vector>
#include <iostream>
#include<queue>


graph::graph() :adj(nodes) {}

void setXY(vector<node>& adj, int source, int dest, int weight) {
    adj[source].list.push_back(make_pair(dest, weight));
    adj[dest].list.push_back(make_pair(source, weight));
}

void graph::inputAdjacencyList() {
    setXY(adj, 1, 2, 3);
    setXY(adj, 2, 35, 15);
    setXY(adj, 35, 0, 3);
    setXY(adj, 10, 11, 3);
    setXY(adj, 11, 32, 6);
    setXY(adj, 11, 32, 6);
    setXY(adj, 32, 33, 3);
    setXY(adj, 33, 40, 6);
    setXY(adj, 40, 41, 3);
    setXY(adj, 1, 3, 9);
    setXY(adj, 3, 7, 6);
    setXY(adj, 7, 8, 6);
    setXY(adj, 8, 10, 6);
    setXY(adj, 0, 28, 9);
    setXY(adj, 28, 43, 6);
    setXY(adj, 43, 42, 6);
    setXY(adj, 42, 41, 6);
    setXY(adj, 3, 4, 3);
    setXY(adj, 2, 4, 9);
    setXY(adj, 28, 36, 3);
    setXY(adj, 35, 36, 9);
    setXY(adj, 18, 19, 9);
    setXY(adj, 18, 17, 3);
    setXY(adj, 19, 20, 3);
    setXY(adj, 17, 20, 9);
    setXY(adj, 17, 16, 6);
    setXY(adj, 20, 21, 6);
    setXY(adj, 16, 21, 9);
    setXY(adj, 16, 15, 3);
    setXY(adj, 21, 22, 3);
    setXY(adj, 15, 26, 3);
    setXY(adj, 22, 23, 3);
    setXY(adj, 15, 6, 3);
    setXY(adj, 6, 5, 3);
    setXY(adj, 22, 38, 3);
    setXY(adj, 38, 37, 3);
    setXY(adj, 6, 7, 3);
    setXY(adj, 38, 43, 3);
    setXY(adj, 26, 25, 3);
    setXY(adj, 23, 24, 3);
    setXY(adj, 25, 14, 3);
    setXY(adj, 24, 27, 3);
    setXY(adj, 14, 13, 3);
    setXY(adj, 27, 29, 3);
    setXY(adj, 25, 24, 3);
    setXY(adj, 13, 29, 9);
    setXY(adj, 13, 9, 3);
    setXY(adj, 9, 8, 3);
    setXY(adj, 29, 39, 3);
    setXY(adj, 39, 42, 3);
    setXY(adj, 13, 12, 3);
    setXY(adj, 12, 30, 3);
    setXY(adj, 30, 32, 3);
    setXY(adj, 29, 34, 3);
    setXY(adj, 34, 31, 3);
    setXY(adj, 31, 33, 3);
    setXY(adj, 9, 11, 6);
    setXY(adj, 39, 40, 6);
    setXY(adj, 3, 28, 6);
    setXY(adj, 8, 42, 6);

}
void graph::setcoordinates() {
    adj[0].posnodes.x = 19;
    adj[0].posnodes.y = 1;
    adj[1].posnodes.x = 1;
    adj[1].posnodes.y = 1;
    adj[2].posnodes.x = 3;
    adj[2].posnodes.y = 1;
    adj[35].posnodes.x = 17;
    adj[35].posnodes.y = 1;
    adj[18].posnodes.x = 5;
    adj[18].posnodes.y = 3;
    adj[19].posnodes.x = 15;
    adj[19].posnodes.y = 3;
    adj[17].posnodes.x = 5;
    adj[17].posnodes.y = 5;
    adj[20].posnodes.x = 15;
    adj[20].posnodes.y = 5;
    adj[3].posnodes.x = 1;
    adj[3].posnodes.y = 7;
    adj[4].posnodes.y = 7;
    adj[4].posnodes.x = 3;
    adj[36].posnodes.x = 17;
    adj[36].posnodes.y = 7;
    adj[28].posnodes.x = 19;
    adj[28].posnodes.y = 7;
    adj[5].posnodes.x = 3;
    adj[5].posnodes.y = 9;
    adj[16].posnodes.x = 5;
    adj[16].posnodes.y = 9;
    adj[21].posnodes.x = 15;
    adj[21].posnodes.y = 9;
    adj[37].posnodes.x = 17;
    adj[37].posnodes.y = 9;
    adj[7].posnodes.x = 1;
    adj[7].posnodes.y = 11;
    adj[6].posnodes.x = 3;
    adj[6].posnodes.y = 11;
    adj[15].posnodes.x = 5;
    adj[15].posnodes.y = 11;
    adj[26].posnodes.x = 9;
    adj[26].posnodes.y = 11;
    adj[23].posnodes.x = 11;
    adj[23].posnodes.y = 11;
    adj[22].posnodes.x = 15;
    adj[22].posnodes.y = 11;
    adj[38].posnodes.x = 17;
    adj[38].posnodes.y = 11;
    adj[43].posnodes.x = 19;
    adj[43].posnodes.y = 11;
    adj[14].posnodes.x = 5;
    adj[14].posnodes.y = 13;
    adj[25].posnodes.x = 9;
    adj[25].posnodes.y = 13;
    adj[24].posnodes.x = 11;
    adj[24].posnodes.y = 13;
    adj[27].posnodes.x = 15;
    adj[27].posnodes.y = 13;
    adj[8].posnodes.x = 1;
    adj[8].posnodes.y = 15;
    adj[9].posnodes.x = 3;
    adj[9].posnodes.y = 15;
    adj[13].posnodes.x = 5;
    adj[13].posnodes.y = 15;
    adj[29].posnodes.x = 15;
    adj[29].posnodes.y = 15;
    adj[39].posnodes.x = 17;
    adj[39].posnodes.y = 15;
    adj[42].posnodes.x = 19;
    adj[42].posnodes.y = 15;
    adj[12].posnodes.x = 5;
    adj[12].posnodes.y = 17;
    adj[30].posnodes.x = 9;
    adj[30].posnodes.y = 17;
    adj[31].posnodes.x = 11;
    adj[31].posnodes.y = 17;
    adj[34].posnodes.x = 15;
    adj[34].posnodes.y = 17;
    adj[10].posnodes.x = 1;
    adj[10].posnodes.y = 19;
    adj[11].posnodes.x = 3;
    adj[11].posnodes.y = 19;
    adj[32].posnodes.x = 9;
    adj[32].posnodes.y = 19;
    adj[33].posnodes.x = 11;
    adj[33].posnodes.y = 19;
    adj[40].posnodes.x = 17;
    adj[40].posnodes.y = 19;
    adj[41].posnodes.x = 19;
    adj[41].posnodes.y = 19;

}

vector<int> graph::shortestPath(int start, int dest) {
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int>>> pq;
    vector<int>dist(nodes+1, 1e9), parent(nodes+1); 
    for (int i = 1; i < nodes; i++) parent[i] = i;
    dist[start] = 0; //start
    pq.push(make_pair(0, start));
    int c = 0;
    while (!pq.empty()) {
      //  sf::sleep(sf::milliseconds(80));
        auto it = pq.top();
        int node = it.second;
        int dis = it.first;
        pq.pop();
        for (auto it : adj[node].list) {
            int adjNode = it.first;
            int edW = it.second;
            if (dis + edW < dist[adjNode]) {
                dist[adjNode] = dis + edW;
                pq.push({ dis + edW,adjNode });
                parent[adjNode] = node;
            }
        }
    }

    if (dist[dest] == 1e9) return { -1 };
    vector<int> path;
    int node = dest;
    while (parent[node] != node) {
        path.push_back(node);
        node = parent[node];
    }
    reverse(path.begin(), path.end());
    cout << "path: " << endl;
    for (int i = 0; i < path.size(); i++)
        cout << path[i] << endl;
    cout << "_________________" << endl;
    return path;
};
