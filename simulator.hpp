#ifndef LOGIC_SIMULATOR_HPP
#define LOGIC_SIMULATOR_HPP

#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include "node.hpp"
#include "gates.hpp"

class Circuit
{
public:
    Circuit()
    {
    }
    // Append all the gates to execute in order
    void append(Gate *gate)
    {
        this->elements.emplace_back(gate);
    }

    // Add pointers for input nodes
    void addInputNodes(InputNode *Node)
    {
        inputs.push_back(Node);
    }

    // Traverse and Execute each Gate
    void execute(std::vector<bool> inputVector)
    {
        // Set provided input values for input Nodes
        for (int i = 0; i < inputs.size(); i++)
        {
            inputs.at(i)->setValue(inputVector.at(i));
        }
        // Execute each gate
        for (int i = 0; i < elements.size(); i++)
        {
            Gate *g = elements.at(i);
            g->execute();
        }
    }

private:
    std::vector<InputNode *> inputs = std::vector<InputNode *>();
    std::vector<Gate *> elements;
};

#endif