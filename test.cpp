#include <iostream>
#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include "simulator.hpp"

int main(int argc, char const *argv[])
{
    // Create Gates
    AND A, C;
    OR B(3);
    NOT D;
    XOR E;

    // Create Connections
    A.connect(&(B.getinputs().at(0))); // connect A's output to B's 1st Input
    C.connect(&(B.getinputs().at(1)));
    B.connect(&(D.getinputs().at(0)));
    D.connect(&(E.getinputs().at(0)));

    // Append Logic Gates to the Circuit
    Circuit c;
    c.append(&A);
    c.append(&C);
    c.append(&B);
    c.append(&D);
    c.append(&E);

    // Set Input nodes
    c.addInputNodes(&(A.getinputs().at(0)));
    c.addInputNodes(&(A.getinputs().at(1)));
    c.addInputNodes(&(C.getinputs().at(0)));
    c.addInputNodes(&(C.getinputs().at(1)));
    c.addInputNodes(&(B.getinputs().at(2)));
    c.addInputNodes(&(E.getinputs().at(1)));

    // Input Values
    std::vector<bool> inputValues = std::vector<bool>();
    inputValues.push_back(0);
    inputValues.push_back(1);
    inputValues.push_back(1);
    inputValues.push_back(1);
    inputValues.push_back(0);
    inputValues.push_back(1);

    // Execute the Circuit
    c.execute(inputValues);

    // Print outputs to the console
    std::cout << "[" << A.getinputs().at(0).getValue() << ", " << A.getinputs().at(1).getValue() << " ] A Output: " << A.getOutput() << std::endl;
    std::cout << "[" << B.getinputs().at(0).getValue() << ", " << B.getinputs().at(1).getValue() << ", " << B.getinputs().at(2).getValue() << " ]B Output: " << B.getOutput() << std::endl;
    std::cout << "[" << C.getinputs().at(0).getValue() << ", " << C.getinputs().at(1).getValue() << " ] C Output: " << C.getOutput() << std::endl;
    std::cout << "[" << D.getinputs().at(0).getValue() << "] D Output: " << D.getOutput() << std::endl;
    std::cout << "[" << E.getinputs().at(0).getValue() << ", " << E.getinputs().at(1).getValue() << " ] E Output: " << E.getOutput() << std::endl;
    return 0;
}
