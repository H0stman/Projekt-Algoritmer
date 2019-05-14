#pragma once

#include<string>
#include<vector>

class Graph
{
    private:
        struct Edge
        {
            size_t target;
            uint16_t weight;
        };

        struct Node
        {
            std::string name;
            std::vector<Edge> edges;
        };
        
        bool directed;
        std::vector<Node> nodes;

    public:
        Graph();
        Graph(std::vector<std::string> graphData);
};