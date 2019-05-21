#include"Graph.hpp"
#include"PriorityQueue.h"

struct Vertex
{
    static const uint16_t INFINITY = UINT16_MAX;
    std::string name;
    std::string previous;
    uint16_t cost;

    Vertex();
    Vertex(std::string nodeName,uint16_t sumCost);
    Vertex(std::string nodeName, std::string previousNode, uint16_t sumCost);
    bool operator< (const Vertex &&other);
};

Vertex::Vertex() : name(""), previous(""), cost(Vertex::INFINITY) {}

Vertex::Vertex(std::string nodeName, uint16_t sumCost) : name(nodeName), previous(""), cost(sumCost) {}

Vertex::Vertex(std::string nodeName, std::string previousNode, uint16_t sumCost) : name(nodeName), previous(previousNode), cost(sumCost) {}

bool Vertex::operator< (const Vertex &&other)
{
    return (cost < other.cost);
}


std::vector<std::string>& DijkstrasAlgo(const Graph::Graph& network, const std::string& initialNode, const std::string& targetNode)
{
    std::vector<Vertex> unvisited;
    std::vector<Vertex> visited;
    auto current = unvisited.begin();
    for (auto &&node : network.getAllNodes())
    {
        uint16_t cost = Vertex::INFINITY;
        if (node == initialNode)
        {
            cost = 0;
            current = unvisited.end();
        }
        unvisited.push_back(Vertex(node, cost));
    }

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
        while (current == unvisited.end())
        {
            current = unvisited.begin();
            while ((current->name != nextVertex.peek().name) && (current != unvisited.end())) current++;
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
            ++retrace;
        }
        shortestPath.push_back(retrace->name);
        current = retrace;
    } while (current->name != initialNode);

    return shortestPath;
}