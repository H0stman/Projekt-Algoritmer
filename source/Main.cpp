#include <iostream>
#include "Graph.hpp"
#include "GraphIO.hpp"

int main(int argc, char const *argv[])
{
    enum InParam {PROGRAMPATH, GRAPHFILE, VOIAGE};

    std::cout << argc << std::endl << argv[InParam::PROGRAMPATH] << std::endl << argv[InParam::GRAPHFILE] << std::endl << argv[InParam::VOIAGE] << std::endl;
    return 0;
}
