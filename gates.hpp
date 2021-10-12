#ifndef GATES_HPP
#define GATES_HPP

#include <stdlib.h>
#include <stdbool.h>
#include <vector>
#include "node.hpp"

//================================================================
class Gate
{
public:
    virtual ~Gate(){};
    virtual void execute() = 0;
    virtual std::vector<InputNode> &getinputs() = 0;

    // Connects output Node to other Gate's input Node
    virtual bool connect(Node *other_inputNode) = 0;
    virtual bool getOutput() = 0;
    virtual void disconnect() = 0;
};

//================================================================
class AND : public Gate
{
public:
    AND() : _numInputs(2)
    {
        input = std::vector<InputNode>(2);
        output = new OutputNode();
    }
    AND(int numInputs) : _numInputs(numInputs)
    {
        input = std::vector<InputNode>(numInputs);
        output = new OutputNode();
    }
    std::vector<InputNode> &getinputs() override { return this->input; }
    bool getOutput() override { return this->output->getValue(); }
    bool connect(Node *other_inputNode) override
    {
        if (other_inputNode != nullptr)
        {
            output = (OutputNode *)other_inputNode;
            return true;
        }
        return false;
    }
    void disconnect() override
    { /*Not Implemented */
    }
    void execute() override
    {
        if (input.size() > 0)
        {
            if (output == nullptr)
            {
                output = new OutputNode();
            }
            bool out = input.at(0).getValue();
            for (int i = 1; i < input.size(); i++)
            {
                out = out && input.at(i).getValue();
            }
            output->setValue(out);
        }
    }

    ~AND()
    {
        if (output != nullptr)
        {
            //delete (output);
        }
    }

private:
    std::vector<InputNode> input;
    int _numInputs;
    OutputNode *output = nullptr;
};

//================================================================
class OR : public Gate
{
public:
    OR() : _numInputs(2)
    {
        input = std::vector<InputNode>(2);
        output = new OutputNode();
    }
    OR(int numInputs) : _numInputs(numInputs)
    {
        input = std::vector<InputNode>(numInputs);
        output = new OutputNode();
    }
    std::vector<InputNode> &getinputs() override { return this->input; }
    bool getOutput() override { return this->output->getValue(); }
    bool connect(Node *other_inputNode) override
    {
        if (other_inputNode != nullptr)
        {
            output = (OutputNode *)other_inputNode;
            return true;
        }
        return false;
    }
    void disconnect() override
    { /*Not Implemented */
    }
    void execute() override
    {
        if (input.size() > 0)
        {
            if (output == nullptr)
            {
                output = new OutputNode();
            }
            bool out = input.at(0).getValue();
            for (int i = 1; i < input.size(); i++)
            {
                out = out || input.at(i).getValue();
            }
            output->setValue(out);
        }
    }

    ~OR()
    {
        if (output != nullptr)
        {
            //delete (output);
        }
    }

private:
    std::vector<InputNode> input;
    int _numInputs;
    OutputNode *output = nullptr;
};

//================================================================
class NOT : public Gate
{
public:
    NOT() : _numInputs(1)
    {
        input = std::vector<InputNode>(1);
        output = new OutputNode();
    }

    std::vector<InputNode> &getinputs() override { return this->input; }
    bool getOutput() override { return this->output->getValue(); }
    bool connect(Node *other_inputNode) override
    {
        if (other_inputNode != nullptr)
        {
            output = (OutputNode *)other_inputNode;
            return true;
        }
        return false;
    }
    void disconnect() override
    { /*Not Implemented */
    }
    void execute() override
    {
        if (input.size() > 0)
        {
            if (output == nullptr)
            {
                output = new OutputNode();
            }
            output->setValue(!(input.at(0).getValue()));
        }
    }

    ~NOT()
    {
        if (output != nullptr)
        {
            //delete (output);
        }
    }

private:
    std::vector<InputNode> input;
    int _numInputs;
    OutputNode *output = nullptr;
};

//================================================================
class XOR : public Gate
{
public:
    XOR() : _numInputs(2)
    {
        input = std::vector<InputNode>(2);
        output = new OutputNode();
    }
    XOR(int numInputs) : _numInputs(numInputs)
    {
        input = std::vector<InputNode>(numInputs);
        output = new OutputNode();
    }
    std::vector<InputNode> &getinputs() override { return this->input; }
    bool getOutput() override { return this->output->getValue(); }
    bool connect(Node *other_inputNode) override
    {
        if (other_inputNode != nullptr)
        {
            output = (OutputNode *)other_inputNode;
            return true;
        }
        return false;
    }
    void disconnect() override
    { /*Not Implemented */
    }
    void execute() override
    {
        if (input.size() > 0)
        {
            if (output == nullptr)
            {
                output = new OutputNode();
            }
            bool out = input.at(0).getValue();
            for (int i = 1; i < input.size(); i++)
            {
                out = out ^ input.at(i).getValue();
            }
            output->setValue(out);
        }
    }

    ~XOR()
    {
        if (output != nullptr)
        {
            //delete (output);
        }
    }

private:
    std::vector<InputNode> input;
    int _numInputs;
    OutputNode *output = nullptr;
};
#endif