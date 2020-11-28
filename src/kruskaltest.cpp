#include <iostream>
#include "Graph.h"
#include <functional>
#include <iomanip>
#include <exception>

class InvalidArgument : public std::exception {

};

size_t tryFind(std::string str, char ch);

int main() {
    std::string cmdLine;
    Graph *graph = nullptr;
    while (getline(std::cin, cmdLine)) {
//        Helper variable pos, indicating the position of the char ' ' or ';'.
        try {
            if (cmdLine == "clear") {
                if (graph == nullptr) {
                    throw InvalidArgument();
                }
                graph->init();
                std::cout << "success" << std::endl;
            } else if (cmdLine == "mst") {
                if (graph == nullptr) {
                    throw InvalidArgument();
                }
                double weight;
                if (graph->tryGetMSTWeight(weight)){
                    std::cout << "mst " << std::setprecision(2) << std::fixed << weight;
                }else{
                    std::cout << "not connected";
                }
                std::cout << std::endl;
            } else if (cmdLine == "edge_count") {
                if (graph == nullptr) {
                    throw InvalidArgument();
                }
                std::cout << "edge count is " << graph->getEdgeCount() << std::endl;
            } else if (cmdLine == "exit") {
                delete graph;
                return 0;
            } else {
                size_t pos = tryFind(cmdLine, ' ');
                std::string option = cmdLine.substr(0, pos);
                std::string parameters = cmdLine.substr(pos + 1);
                if (option == "n") {
                    int n = std::stoi(parameters);
                    if (n < 0 || graph != nullptr) {
                        throw InvalidArgument();
                    }
                    graph = new Graph(n);
                    std::cout << "success" << std::endl;
                } else if (option == "i") {
                    if (graph == nullptr) {
                        throw InvalidArgument();
                    }
                    pos = tryFind(parameters, ';');
                    int u = std::stoi(parameters.substr(0, pos));
                    parameters = parameters.substr(pos + 1);
                    pos = tryFind(parameters, ';');
                    int v = std::stoi(parameters.substr(0, pos));
                    double w = std::stod(parameters.substr(pos + 1));
                    unsigned int n = graph->getSize();
                    if (w < 0 || u >= n || v >= n || u < 0 || v < 0) {
                        throw InvalidArgument();
                    }
                    graph->insertEdge(u, v, w);
                    std::cout << "success" << std::endl;
                } else if (option == "d") {
                    if (graph == nullptr) {
                        throw InvalidArgument();
                    }
                    pos = tryFind(parameters, ';');
                    int u = std::stoi(parameters.substr(0, pos));
                    int v = std::stoi(parameters.substr(pos + 1));
                    unsigned int n = graph->getSize();
                    if (u > n || v >= n || u <= 0 || v < 0) {
                        throw InvalidArgument();
                    }
                    std::cout << (graph->rmEdge(u, v) ? "success" : "failure") << std::endl;
                } else if (option == "degree") {
                    if (graph == nullptr) {
                        throw InvalidArgument();
                    }
                    int u = std::stoi(parameters);
                    unsigned int n = graph->getSize();
                    if (u >= n) {
                        throw InvalidArgument();
                    }
                    std::cout << "degree of " + std::to_string(u) +" is " << graph->getDegreeOf(u) << std::endl;
                } else {
                    throw InvalidArgument();
                }
            }
        } catch (InvalidArgument &error) {
            std::cout << "invalid argument" << std::endl;
        } catch (std::exception &e) {
            // handle invalid conversion (stod/stoi failure)
            std::cout << "invalid argument" << std::endl;
        }
    }
    return 0;
}

size_t tryFind(std::string str, char ch) {
    size_t pos = str.find(ch);
    if (pos == -1) {
        throw InvalidArgument();
    }
    return pos;
}

