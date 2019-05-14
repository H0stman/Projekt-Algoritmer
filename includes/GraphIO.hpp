#pragma once

#include <string>
#include <vector>
#include "Graph.hpp"

/*GraphIO är uttänkt ska läsa filen den får in korrekt och returnera en */


class GraphIO
{
private:
    
public:
    GraphIO(/* args */);
    ~GraphIO();
    Graph CreateGraph(); //bool directed, std::vector<std::string> nodes, std::vector<std::string> edges
};

GraphIO::GraphIO(/* args */)
{
}

GraphIO::~GraphIO()
{
}
