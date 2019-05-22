#include "Graph.hpp"
#include<iostream>

Graph::Graph(bool isDirected, std::vector<std::string> &nodeNames, std::vector<std::vector<std::string>> &edgeData)
{
    enum Edg
    {
        FROM,
        TO,
        WEIGHT
    };

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
        std::cout << edgeData[i][Edg::FROM] << " -> " << edgeData[i][Edg::TO] << " ... " << edgeData[i][Edg::WEIGHT] << std::endl;
        size_t fromNode = 0;
        size_t toNode = 0;
        // Find the nodes the edge connects
        while (nodes[fromNode].name != edgeData[i][Edg::FROM])
            ++fromNode;
        while (nodes[toNode].name != edgeData[i][Edg::TO])
            ++toNode;
        // Create edge and save in start node
        CreateEdge(fromNode, toNode, stoull(edgeData[i][Edg::WEIGHT]));
        // If undirected duplicate edge in opposite direction
        if (!directed)
            CreateEdge(toNode, fromNode, stoull(edgeData[i][Edg::WEIGHT]));
    }
}

void Graph::CreateEdge(size_t from, size_t to, size_t cost)
{
    Edge newEdge;
    newEdge.target = to;
    newEdge.weight = cost;
    nodes[from].edges.push_back(newEdge);
}

std::vector<std::string> Graph::getAllNodes() const
{
    std::vector<std::string> allNodes;
    for (auto &&node : nodes)
    {
        allNodes.push_back(node.name);
    }
    return allNodes;
}

std::vector<std::string> Graph::getNeighbors(const std::string &nodeName) const
{
    std::vector<std::string> neighbors;
    size_t index = nodes.size();
    while (nodes[--index].name != nodeName)
        ;
    for (auto &&i : nodes[index].edges)
        neighbors.push_back(nodes[i.target].name);
    return neighbors;
}

size_t Graph::getEdgeWeight(const std::string &startNode, const std::string &endNode) const
{
    size_t index1 = nodes.size();
    while (nodes[--index1].name != startNode);
    size_t index2 = nodes[index1].edges.size();
    while (nodes[nodes[index1].edges[--index2].target].name != endNode);
    return nodes[index1].edges[index2].weight;
}
