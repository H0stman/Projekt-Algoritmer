#include "Graph.hpp"

Graph::Graph(bool isDirected, std::vector<std::string> nodeNames, std::vector<std::string> edgeData)
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