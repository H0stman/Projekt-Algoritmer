/*
 *
 *     Kod: Oscar Milstein och Ove Ødegård
 *
 */

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

    if (argc == 3)
    {
        std::string voiage = argv[InParam::VOIAGE];
        // Separate voiage argument into two substrings, the "-" is the marker
        std::string from = voiage.substr(0, voiage.find("-"));
        std::string to = voiage.substr(from.size() + 1, voiage.size() - from.size() - 1);
        
        // Create input-output object, create graph and run algorithm
        GraphIO io = GraphIO(argv[InParam::GRAPHFILE], "Answer.txt");
        Graph theGraph = io.CreateGraph();
        io.WriteSolutionToFile(DijkstrasAlgo(theGraph, from, to));
    }
    else
        std::cout << "Wrong number of arguments" << std::endl << "Usage: " << argv[InParam::PROGRAMPATH] << " \"testfile\" \"start - end\"" << std::endl;

    return 0;
}
