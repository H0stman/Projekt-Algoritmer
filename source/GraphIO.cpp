#include "GraphIO.hpp"
#include <iostream>

GraphIO::GraphIO(std::string InputFilePath, std::string OutputFilePath) : inPath(InputFilePath), outPath(OutputFilePath) {}

GraphIO::~GraphIO() {}

Graph GraphIO::CreateGraph() const //bool directed, std::vector<std::string> nodes, std::vector<std::string> edges
{
    std::string line;
    std::vector<std::string> nodes;
    std::vector<std::vector<std::string>> edgesdata;
    bool directed;
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
            std::cout << line.find('\t') << std::endl;
            std::string temp = line.substr(edge[0].size() + 1, line.size() - edge[0].size());
            std::cout << temp << std::endl;
            edge.push_back(temp.substr(0, temp.find('\t')));
            edge.push_back(temp.substr(edge[1].size() + 1, temp.size() - edge[1].size()));
            edgesdata.push_back(edge);
        } while (!stream.eof());
    }
    stream.close();
    // for (auto &&i : nodes)
    // {
    //     // for (auto &&j : i)
    //     // {
    //     //     std::cout << j << "\t";
    //     // }
    //     std::cout << i << "\t";
    //     std::cout << std::endl;
    // }
    
    return Graph(directed, nodes, edgesdata);
}

void GraphIO::WriteGraphToFile(std::vector<std::string> shortPath) const //VECTOR 1st element total cost, second element is first node ... nth element is last node of the shortest path.
{
    std::fstream stream(outPath, std::fstream::in | std::fstream::out);
    if (stream.is_open())
    {
        stream << '0' << std::endl;
        stream << shortPath[0] << std::endl;
        for (size_t i = 1; i < shortPath.size(); i++)
        {
            stream << "->";
            stream << shortPath[i];
        }
    }
    stream.close();
}