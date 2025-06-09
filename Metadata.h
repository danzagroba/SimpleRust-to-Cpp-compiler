#pragma once
#include <string>
#include <vector>

class Node{
	public:
	Node() = default;
	virtual ~Node() = default;
	virtual std::string getType() const = 0;
};

class ProgramNode : public Node {
	public:
	std::vector<Node*> statements;

	ProgramNode(){
		statements.clear();
	}
	~ProgramNode() {
		for (auto statement : statements) {
			delete statement;
		}
		statements.clear();
	}
};

