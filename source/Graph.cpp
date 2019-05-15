#include "Graph.hpp"

Graph::Graph(bool isDirected, std::vector<std::string> nodeNames, std::vector<std::vector<std::string>> edgeData)
{
    enum Edg {FROM, TO, WEIGHT};
    
    directed = isDirected;

    // Create the nodes
    for (size_t i = 0; i < nodeNames.size(); i++)
    {
        Node newNode;
        newNode.name = nodeNames[i];
        nodes.push_back(newNode);
    }

    // Create edges between nodes
    for (size_t i = 0; i < edgeData.size(); i++)
    {
        size_t fromNode = 0;
        size_t toNode = 0;
        // Find the nodes the edge connects
        while (nodes[fromNode].name != edgeData[i][Edg::FROM]) ++fromNode;
        while (nodes[toNode].name != edgeData[i][Edg::TO]) ++toNode;
        // Create edge and save in start node
        CreateEdge(fromNode, toNode, stoull(edgeData[i][Edg::WEIGHT]));
        // If undirected duplicate edge in opposite direction
        if (!directed) CreateEdge(toNode, fromNode, stoull(edgeData[i][Edg::WEIGHT]));
    }
}

void Graph::CreateEdge(size_t from, size_t to, uint16_t cost)
{
        Edge newEdge;
        newEdge.target = to;
        newEdge.weight = cost;
        nodes[from].edges.push_back(newEdge);
}
