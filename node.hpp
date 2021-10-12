#ifndef NODE_HPP
#define NODE_HPP

#include <stdlib.h>
#include <stdbool.h>
#include <vector>

class Node
{
public:
    virtual ~Node() {}
    virtual bool getValue() = 0;
    virtual void setValue(bool value) = 0;
};

class InputNode : public Node
{
public:
    InputNode() {}
    bool getValue() override
    {
        if (this->_value == nullptr)
        {
            printf("Error: Nullpointer!\n");
            return false;
        }
        return *(this->_value);
    }

    void setValue(bool value) override
    {
        if (this->_value == nullptr)
        {
            this->_value = new bool();
        }
        *(this->_value) = value;
    }
    ~InputNode()
    {
    }

private:
    bool *_value = nullptr;
};

class OutputNode : public Node
{
public:
    OutputNode() {}
    bool getValue() override
    {
        if (this->_value == nullptr)
        {
            printf("Error: Nullpointer!\n");
            return false;
        }
        return *(this->_value);
    }
    void setValue(bool value) override
    {
        if (this->_value == nullptr)
        {
            this->_value = new bool();
        }
        *(this->_value) = value;
    }
    ~OutputNode()
    {
        if (_value != nullptr)
        {
            delete (_value);
        }
    }

private:
    bool *_value = nullptr;
};

#endif