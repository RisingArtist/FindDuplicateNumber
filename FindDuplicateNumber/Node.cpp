#include "Node.h"
#include <iostream>


Node::Node(int _value, Node* n)
{
	value = _value;
	next = nullptr;
}

Node::~Node()
{
}
