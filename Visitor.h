#pragma once
#include "AST.h"

class Visitor {
public:
    virtual void visit(class Node& node) = 0;
    virtual ~Visitor() = default;
};