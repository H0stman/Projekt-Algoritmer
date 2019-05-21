#include"Graph.hpp"
#include"PriorityQueue.h"

struct Vertex
{
    const uint16_t INFINITY = UINT16_MAX;
    std::string name;
    std::string previous;
    uint16_t cost;

    Vertex();
    Vertex(std::string input);
    bool operator< (const Vertex &&other);
};

Vertex::Vertex() : name(""), previous(""), cost(Vertex::INFINITY) {}

Vertex::Vertex(std::string input) : name(input), previous(""), cost(Vertex::INFINITY) {}

bool Vertex::operator< (const Vertex &&other)
{
    return (cost < other.cost);
}


std::vector<std::string>& DijkstrasAlgo(const Graph::Graph& network, const std::string& initialNode, const std::string& targetNode)
{

    std::vector<std::string> unvisited = network.getAllNodes();
    size_t current = unvisited.begin()->find(initialNode);
    PriorityQueue<Vertex> nextVertex;

    std::vector<std::string> neighbors = network.getNeighbors(unvisited[current]);
    for (auto i = neighbors.begin(); i != neighbors.end(); i++)
    {
        nextVertex.enqueue(Vertex(*i));
    }
    
}