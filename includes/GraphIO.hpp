#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "Graph.hpp"

/*GraphIO är uttänkt ska läsa filen den får in korrekt, 
skapa en vector med nodes och en vektor med edgedata/edgees.
Detta blir alltså ett gränssnitt mellan filskrivandet/läsandet
och den faktiska processeringen av graferna*/
class GraphIO
{
private:
    std::string inPath;
    std::string outPath;

public:
    GraphIO(std::string InputFilePath, std::string OutputFilePath);
    ~GraphIO();
    Graph CreateGraph() const;
    void WriteSolutionToFile(std::vector<std::string> shortPath) const;
};