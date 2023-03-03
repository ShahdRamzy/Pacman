#include "pacman.h"
#include<SFML/Graphics.hpp>
#include <iostream>
int Pacman::moveUP(sf::Vector2i& pos, graph& gr, int n)
{
    int Y = gr.adj[n].posnodes.y;
    auto l_front = gr.adj[n].list.begin();
    for (int i = 0; i < gr.adj[n].list.size(); i++)
    {


        int adjnode = l_front->first;
        int yadjnode = gr.adj[adjnode].posnodes.y;
        int xadjnode = gr.adj[adjnode].posnodes.x;

        if (Y > yadjnode)
        {
            pos.y = yadjnode;
            pos.x = xadjnode;
            return adjnode;

        }
        else {
            advance(l_front, 1);
            continue;
        }
    }
}

int Pacman::moveDOWN(sf::Vector2i& position, graph& gr, int n)
{
    int Y = gr.adj[n].posnodes.y;
    auto l_front = gr.adj[n].list.begin();
    for (int i = 0; i < gr.adj[n].list.size(); i++)
    {
        int adjnode = l_front->first;
        int yadjnode = gr.adj[adjnode].posnodes.y;
        int xadjnode = gr.adj[adjnode].posnodes.x;

        if (Y < yadjnode)
        {
            position.y = yadjnode;
            position.x = xadjnode;
            return adjnode;
        }
        else {

            advance(l_front, 1);
        }
    }
}
int Pacman::moveLEFT(sf::Vector2i& pos, graph& gr, int n)
{

    int x = gr.adj[n].posnodes.x;
    auto l_front = gr.adj[n].list.begin();
    for (int i = 0; i < gr.adj[n].list.size(); i++)
    {


        int adjnode = l_front->first;
        int yadjnode = gr.adj[adjnode].posnodes.y;
        int xadjnode = gr.adj[adjnode].posnodes.x;

        if (x > xadjnode)
        {
            pos.y = yadjnode;
            pos.x = xadjnode;
            return adjnode;

        }
        else {
            advance(l_front, 1);
            continue;
        }

    }



}



int Pacman::moveRIGHT(sf::Vector2i& pos, graph& gr, int n)
{

    int x = gr.adj[n].posnodes.x;
    auto l_front = gr.adj[n].list.begin();
    for (int i = 0; i < gr.adj[n].list.size(); i++)
    {


        int adjnode = l_front->first;
        int yadjnode = gr.adj[adjnode].posnodes.y;
        int xadjnode = gr.adj[adjnode].posnodes.x;

        if (x < xadjnode)
        {
            pos.y = yadjnode;
            pos.x = xadjnode;
            return adjnode;


        }

        else {

            advance(l_front, 1);
        }

    }
}