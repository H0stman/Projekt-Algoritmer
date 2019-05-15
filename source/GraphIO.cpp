#include "GraphIO.hpp"

GraphIO::GraphIO(std::string InputFilePath, std::string OutputFilePath) : inPath(InputFilePath), outPath(OutputFilePath) {}

GraphIO::~GraphIO() {}

Graph GraphIO::CreateGraph() //bool directed, std::vector<std::string> nodes, std::vector<std::string> edges
{
    std::fstream stream(inPath, std::fstream::in | std::fstream::out);
    stream.get

}
    
void WriteGraphToFile()
{
    
}