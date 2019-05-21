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
            std::string name; // Name of a node
            std::vector<Edge> edges; // Edges going out from a node.
        };
        
        bool directed;
        std::vector<Node> nodes;

        void CreateEdge(size_t from, size_t to, uint16_t cost);

    public:
        Graph() = default;
        Graph(bool isDirected, std::vector<std::string> &nodeNames, std::vector<std::vector<std::string>> &edgeData);
        ~Graph() = default;

        std::vector<std::string> getAllNodes() const;
        std::vector<std::string> getNeighbors(const std::string &nodeName) const;
        uint16_t getEdgeWeight(const std::string &startNode, const std::string &endNode) const;
};