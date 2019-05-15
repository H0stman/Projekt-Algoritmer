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

        void CreateEdge(size_t from, size_t to, uint16_t cost);

    public:
        Graph() = default;
        Graph(bool isDirected, std::vector<std::string> nodeNames, std::vector<std::vector<std::string>> edgeData);
        ~Graph() = default;
};