#include "DijkstrasAlgo.hpp"
#include <iostream>


Vertex::Vertex() : name(""), previous(""), cost(Vertex::INFINITY) {}

Vertex::Vertex(std::string nodeName, size_t sumCost) : name(nodeName), previous(""), cost(sumCost) {}

Vertex::Vertex(std::string nodeName, std::string previousNode, size_t sumCost) : name(nodeName), previous(previousNode), cost(sumCost) {}

bool Vertex::operator<(const Vertex &other)
{
    return (cost < other.cost);
}

std::vector<std::string> DijkstrasAlgo(const Graph &network, const std::string &initialNode, const std::string &targetNode)
{
    std::vector<Vertex> unvisited;
    std::vector<Vertex> visited;
    auto current = unvisited.begin();
    for (auto &&node : network.getAllNodes())
    {
        size_t cost = Vertex::INFINITY;
        if (node == initialNode)
        {
            cost = 0;
            current = unvisited.end();
        }
        unvisited.push_back(Vertex(node, cost));
    }
    std::cout << "targetNode" << std::endl;

    PriorityQueue<Vertex> nextVertex;

    do
    {
        std::vector<std::string> neighbors = network.getNeighbors(current->name);
        for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++)
        {
            nextVertex.enqueue(Vertex(*neighbor, current->name, network.getEdgeWeight(current->name, *neighbor) + current->cost));
        }
        visited.push_back(*current);
        unvisited.erase(current);
        current = unvisited.end();
        
        while ((current == unvisited.end()) && (!nextVertex.isEmpty()))
        {
            current = unvisited.begin();
            while ((current->name != nextVertex.peek().name) && (current != unvisited.end()))
                current++;
            if (current != unvisited.end())
            {
                *current = nextVertex.peek();
            }
            nextVertex.dequeue();
        }
    } while (current->name != targetNode);

    std::vector<std::string> shortestPath;
    shortestPath.push_back(std::to_string(current->cost));

    auto retrace = visited.begin();
    do
    {
        while (retrace->name != current->previous)
        {
            std::cout << retrace->name << "\t" << retrace->cost << "\t" << retrace->previous << std::endl;
            ++retrace;
        }
        shortestPath.push_back(retrace->name);
        current = retrace;
    } while (current->name != initialNode);
    // std::cout << shortestPath.size();
    // for (auto &&i : shortestPath)
    // {
    //     std::cout << i << " -> ";
    // }
    
    return shortestPath;
}