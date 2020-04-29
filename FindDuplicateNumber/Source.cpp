#include "Node.h"
#include <iostream>

using namespace std;

void AddNode(Node** n, int _value);
Node* GetLast(Node** n);
void printList(Node* n);
Node* FindDuplicate(Node* head);

int main()
{
	// Create Head Node
	Node* head = new Node(0);

	// Add a few new nodes at the END. 
	AddNode(&head, 4);
	AddNode(&head, 4);
	AddNode(&head, 1);

	printList(head); // Results in: 0 4 4 1

	// Create a loop by setting the last node to the second one
	head->next->next->next = head->next;

	// Find the duplicate number. Answer: 4
	int dupNum = FindDuplicate(head)->value;
	if (dupNum == NULL)
	{
		std::cout << "There is NO CYCLE!" << std::endl;
	}
	else
	{
		std::cout << "Duplicate number is: " << dupNum << std::endl;
	}
	return 0;
}

// Using Floyd's Turtle and Hare Cycle Detection Algorithm
Node* FindDuplicate(Node* head)
{
	Node* turtle;
	Node* hare;

	if (head == NULL)
		return NULL;

	// Start Point
	turtle = head;
	hare = head;

	// Checks if the cycle loops
	while (hare->next != NULL && hare->next->next != NULL)
	{
		turtle = turtle->next; // ...One step at a time
		hare = hare->next->next; // ...Two steps at a time

		if (turtle == hare) // When they meet up...
		{
			turtle = head; // ...set the turtle back to start

			while (turtle != hare) // ...go around again to find the duplicate number
			{
				turtle = turtle->next; // ...one step at a time
				hare = hare->next;     // for both the turtle & hare...
			}
			return hare; // the duplicate number
		}
	}
	return NULL;

}

// Makes a new node to the END of the LinkedList
// Note: Commenting out the While loop would add node to START of the list
void AddNode(Node** head, int _value)
{
	while (*head != nullptr)
	{
		head = &(*head)->next;
	}
	Node* temp = new Node(_value);
	temp->next = *head;
	*head = temp;
}

// Display all the nodes' values
void printList(Node* n) {
	while (n != nullptr)
	{
		std::cout << n->value << " ";
		n = n->next;
	}
	std::cout << std::endl;
}

