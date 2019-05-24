#include <iostream>
#include "Graph.hpp"
#include "GraphIO.hpp"
#include "DijkstrasAlgo.hpp"

int main(int argc, char const *argv[])
{
    enum InParam
    {
        PROGRAMPATH,
        GRAPHFILE,
        VOIAGE
    };

/*
    std::cout << argc << std::endl
              << argv[InParam::PROGRAMPATH] << std::endl
              << argv[InParam::GRAPHFILE] << std::endl
              << argv[InParam::VOIAGE] << std::endl;
*/
    if (argc == 3)
    {
        std::string voiage = argv[InParam::VOIAGE];
        std::string from = voiage.substr(0, voiage.find("-"));
        std::string to = voiage.substr(from.size() + 1, voiage.size() - from.size() - 1);
        // std::cout << from << " -> " << to << std::endl;
        // std::cout << argv[InParam::GRAPHFILE] << " -> " << "output.txt" << std::endl;
        GraphIO io = GraphIO(argv[InParam::GRAPHFILE], "output.txt");
        Graph theGraph = io.CreateGraph();

        io.WriteGraphToFile(DijkstrasAlgo(theGraph, from, to));
    } else
    {
        std::cout << "Wrong number of arguments" << std::endl << "Usage: " << argv[InParam::PROGRAMPATH] << " \"testfile\" \"start - end\"" << std::endl;
    }
    
    return 0;
}
