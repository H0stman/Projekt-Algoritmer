#include "GraphIO.hpp"

GraphIO::GraphIO(std::string InputFilePath, std::string OutputFilePath) : inPath(InputFilePath), outPath(OutputFilePath) {}

GraphIO::~GraphIO() {}

Graph GraphIO::CreateGraph() //bool directed, std::vector<std::string> nodes, std::vector<std::string> edges
{
    std::string line;
    std::vector<std::string> nodes;
    std::vector<std::vector<std::string>> edgesdata;
    bool directed;
    std::fstream stream(inPath, std::fstream::in | std::fstream::out);
    if (stream.is_open())
    {
        int x = 0;
        int y = 0;
        std::string word;
        std::getline(stream, line);
        bool directed = (line == "UNDIRECTED" ? false : true);
        while (line != "" && stream.good())
        {
            std::getline(stream, line);
            nodes.push_back(line);
        }
        std::getline(stream, line);
        while (line != "" && stream.good())
        {
            for (decltype(line.size()) index = 0; index < line.size() && x < 3; ++index)
            {
                if (line[index] != '\t') 
                    word.push_back(line[index]);
                else
                {
                    edgesdata[y][x].push_back(word);
                    word = "";
                    x++;
                }
            }
            x = 0;
            y++;
        }
    }
    stream.close();
    return Graph(directed,nodes,edgesdata);
}

void WriteGraphToFile()
{
}