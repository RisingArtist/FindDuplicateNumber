#pragma once

// Honestly, can be done with a STRUCT 
// Personally, I just got used to using Classes for a while now. 
class Node
{
public:
	int value;
	Node* next;

	Node();
	Node(int _value, Node* next = nullptr);

	~Node();
};

