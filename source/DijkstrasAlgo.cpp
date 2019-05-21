#include"Graph.hpp"
#include"PriorityQueue.h"

struct Vertex
{
    const uint16_t INFINITY = -1;
    std::string name;
    std::string previous;
    uint16_t cost;

    Vertex(std::string input);
    bool operator< (const Vertex &&other);
};

Vertex::Vertex(std::string input) : name(input), cost(Vertex::INFINITY) {}

bool Vertex::operator< (const Vertex &&other)
{
    return (cost < other.cost);
}

std::vector<std::string>& DijkstrasAlgo(const Graph::Graph& network, const std::string& initialNode, const std::string& targetNode)
{

    std::vector<std::string> unvisited;
    PriorityQueue<Vertex> nextVertex;
}