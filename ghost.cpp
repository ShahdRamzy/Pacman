#include "ghost.h"
vector<int> ghost::moving(sf::Vector2i& gostpos, const sf::Vector2i pacpos, graph& gr) {

    int nghost=0;
    for (int i = 0; i < 44; i++) {
        if (gr.adj[i].posnodes.x == gostpos.x && gr.adj[i].posnodes.y == gostpos.y) {
            nghost = i;
            break;
        }
    }
    int npac = 0;
    for (int i = 0; i < 44; i++) {
        if (gr.adj[i].posnodes.x == pacpos.x && gr.adj[i].posnodes.y == pacpos.y) {
            npac = i;
            break;
        }
    }
   vector<int> path=gr.shortestPath(nghost, npac);
   return path;
    

}
