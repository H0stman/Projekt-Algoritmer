#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Graph.hpp"

/*GraphIO är uttänkt ska läsa filen den får in korrekt och skapa en vector med nodes och en vektor med edgedata/edgees.*/

class GraphIO
{
private:
    std::string inPath;
    std::string outPath;

public:
    GraphIO(std::string InputFilePath, std::string OutputFilePath);
    ~GraphIO();
    Graph CreateGraph() const; //bool directed, std::vector<std::string> nodes, std::vector<std::vector<std::string>> edgesdata
    void WriteGraphToFile(std::vector<std::string> shortPath) const;
};