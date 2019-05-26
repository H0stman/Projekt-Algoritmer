/*
 *
 *     Kod: Oscar Milstein och Ove Ødegård
 *
 */

#include<string>
#include "Graph.hpp"
#include "PriorityQueue.hpp"

#pragma once

struct Vertex
{
    static const size_t INFINITE = ULLONG_MAX;
    std::string name;
    std::string previous;
    size_t cost;

    Vertex();
    Vertex(std::string nodeName, size_t sumCost);
    Vertex(std::string nodeName, std::string previousNode, size_t sumCost);
    bool operator<(const Vertex &other);
};

std::vector<std::string> DijkstrasAlgo(const Graph &network, const std::string &initialNode, const std::string &targetNode);