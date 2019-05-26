/*
 *
 *     Kod: Oscar Milstein och Ove Ødegård
 *
 */

#include "DijkstrasAlgo.hpp"
#include <iostream>

Vertex::Vertex() : name(""), previous(""), cost(Vertex::INFINITE) {}

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

    for (auto &&node : network.getAllNodes())
    {
        size_t cost = Vertex::INFINITE;
        if (node == initialNode)
            cost = 0;
        unvisited.push_back(Vertex(node, cost));
    }

    // Find the element holding the initialNode
    auto current = unvisited.begin();
    while (current->name != initialNode)
        current++;
    PriorityQueue<Vertex> nextVertex;

    do
    {
        // Get all neighbors, set preceeding node and calculate total cost
        std::vector<std::string> neighbors = network.getNeighbors(current->name);
        for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++)
        {
            nextVertex.enqueue(Vertex(*neighbor, current->name, network.getEdgeWeight(current->name, *neighbor) + current->cost));
        }
        // Move current node from unvisited to visited
        visited.push_back(*current);
        unvisited.erase(current);

        // Go to next node (that is also part of the unvisited set)
        current = unvisited.end();
        while ((current == unvisited.end()) && (!nextVertex.isEmpty()))
        {
            current = unvisited.begin();
            while ((current->name != nextVertex.peek().name) && (current != unvisited.end()))
                current++;
            if (current != unvisited.end())     // Only consider this node if in set unvisited
                *current = nextVertex.peek();
            nextVertex.dequeue();
        }
    } while (current->name != targetNode);

    // Construct the retrace route - note: first element has the total cost of route
    std::vector<std::string> shortestPath;
    shortestPath.push_back(std::to_string(current->cost));
    while (current->name != initialNode)
    {
        auto retrace = visited.begin();
        while (retrace->name != current->previous)
            ++retrace;
        shortestPath.push_back(current->name);
        current = retrace;
    }
    shortestPath.push_back(current->name);

    // Invert retrace route to get the correct path
    size_t last = shortestPath.size() - 1;
    for (size_t first = 1; first < last; first++)
    {
        shortestPath[first].swap(shortestPath[last]);
        last--;
    }

    return shortestPath;
}