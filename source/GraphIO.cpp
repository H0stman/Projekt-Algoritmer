#include "GraphIO.hpp"
#include <iostream>

GraphIO::GraphIO(std::string InputFilePath, std::string OutputFilePath) : inPath(InputFilePath), outPath(OutputFilePath) {}

GraphIO::~GraphIO() {}

Graph GraphIO::CreateGraph() const //bool directed, std::vector<std::string> nodes, std::vector<std::string> edges
{
    bool directed;
    std::string line;
    std::vector<std::string> nodes;
    std::vector<std::vector<std::string>> edgesdata;
    std::fstream stream;
    stream.open(inPath);
    if (stream.is_open())
    {
        std::getline(stream, line);
        directed = (line == "DIRECTED");
        std::getline(stream, line);
        while (line != "" && stream.good())
        {
            nodes.push_back(line);
            std::getline(stream, line);
        }
        do
        {
            std::getline(stream, line);
            std::vector<std::string> edge;
            edge.push_back(line.substr(0, line.find('\t')));
            std::string temp = line.substr(edge[0].size() + 1, line.size() - edge[0].size());
            edge.push_back(temp.substr(0, temp.find('\t')));
            edge.push_back(temp.substr(edge[1].size() + 1, temp.size() - edge[1].size()));
            edgesdata.push_back(edge);

        } while (!stream.eof());
    }
    stream.close();
    return Graph(directed, nodes, edgesdata);
}

//Writes 
void GraphIO::WriteSolutionToFile(std::vector<std::string> shortPath) const 
{
    std::ofstream myfile;
    myfile.open(outPath, std::fstream::in | std::fstream::out | std::fstream::trunc);
    myfile << '0' << std::endl;
    myfile << shortPath[0] << std::endl;
    for (size_t i = 1; i < shortPath.size(); i++)
    {
        myfile << shortPath[i];
        if (i != shortPath.size() - 1)
            myfile << " -> ";
    }
    myfile << std::endl;
    myfile.close();
}