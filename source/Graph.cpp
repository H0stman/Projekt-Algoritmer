#include "Graph.hpp"

Graph::Graph(std::vector<std::string> graphData)
{
    directed = (graphData[0] == "DIRECTED");
    size_t i = 1;
    while (graphData[i] != "")
    {
        // create node
        ++i;
    }

    while (i  < graphData.size())
    {
        // create edge
        ++i;
    }
}