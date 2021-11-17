//=================================================================
// @author:     Ana Macavei
// @version:   1.2
//
//  Demonstrates the creation and use of a function template
//   in C++ and how to implement it to an unordered linked list.
//
//=================================================================

#pragma once

#include <iostream>

//create node structure 
struct Node {
	int data;
	Node* next;
};

template<typename type>
class UnOrderedList
{
public:
	/*
	Default constructor - Initializes Member Variables
	*/
	UnOrderedList();

	/*
	Destructor - Deallocates any memory allocated by the class
	whenever a Linked List is destroyed
	*/
	~UnOrderedList();

	/*
	prepend - Adds a new node at the beginning of the list
	@param - int (the value to place in the new node)
	@return - void (none)
	*/
	void prepend(type item);

	/*
	append - Adds a new node at the end of the list
	@param - int (the value to place in the new node)
	@return - void (none)
	*/
	void append(type item);

	/*
	Function to output the data contained in each node
	Prints the list in order (all on one line, comma delimited;
	no comma at the end, newline instead.
	*/
	void print() const;

	//Returns a count of the number of items in the list
	int count() const;

	/*
	find - Returns the given int's position in the list and returns 0
	if not in the list.
	@param - int (the value to find)
	@return - 0 if not in the list
	*/
	int find(type item);

	/*
	Removes the given int from the list
	returns true if successful, false otherwise.
	*/
	bool remove(type itemRemoved);

	//Removes all ints from the list
	void removeAll();

	//finds duplicates
	bool findDuplicates(type insertItem);

private:

	Node* head; //keeps track of where the beginning of the list is.
	Node* tail; 


};



//====================================================================
//Demonstrates UnOrderedList class implementation

template <typename type>
UnOrderedList<type>::UnOrderedList() { //constructor
	//setting head and tail pointer to NULL means that head doesn't point to anything yet
	head = nullptr;
	tail = nullptr;
}

template<typename type>
UnOrderedList<type>:: ~UnOrderedList() { //destructor
//free up all the memory allocated for the nodes in the list

	// create a pointer to traverse the list and start it at the head
	Node* current = head;

	// create a pointer to delete nodes and start it at the head
	Node* nodeToDelete = head;

	// while current (the pointer) is not null
	while (current != NULL) {
		// move current to the next node
		current = current->next;

		// move the deletion pointer to delete the node
		delete nodeToDelete;

		// move the deletion pointer forward to catch up with current
		nodeToDelete = current;
	}
	// set head to nullptr since the list is empty now
	head = NULL;
}

template<typename type>
void UnOrderedList<type>::print() const {
	// create a Node pointer to traverse the list and start at the head
	Node* current = head;

	// while the pointer is not null
	while (current != NULL) {
		// print the data in the current node
		std::cout << current->data << std::endl;

		// move pointer forward
		current = current->next;
	}
}

template<typename type>
void UnOrderedList<type>::prepend(type item) {
	
		// create and initialize new node
	Node* newNode = new Node;

	// set the data of the new node
	newNode->data = item;

	//checks if list is empty
	if (head == NULL)
	{
		head = newNode;
		tail = newNode;
	}
	else {

		// make the new node point to whatever the head currently points to
		newNode->next = head;

		// make head point to the new node
		head = newNode;
	}

}

template<typename type>
void UnOrderedList<type>::append(type item) {
	
	// create and initialize new node
	Node* newNode = new Node;

	// set the data of the new node
	newNode->data = item;

	// set the newNode to NULL
	newNode->next = nullptr;

	if (head == NULL) {//if list is empty
		head = newNode;//newNode is both head and tail
		tail = newNode;
	}

	else {//if list is not empty

		// make newNode point to whatever tail currently points to
		tail->next = newNode;

		// inserting at the end of the list by making tail point to newNode
		tail = tail->next;

	}
}

template<typename type>
int UnOrderedList<type>::count() const {

	Node* current = head;
	int counting = 0;

	while (current != nullptr) {

		counting++;

		current = current->next;

	}

	return counting;
}

template<typename type>
int UnOrderedList<type>::find(type item)
{
	Node* current = head;
	int position = 1;
	while (current != nullptr) {
		if (item == current->data) {
			return position;
		}
		position++;
		current = current->next;
	}

	return 0;
}

template<typename type>
bool UnOrderedList<type>::remove(type itemRemoved) {
	//list empty?
	if (head == nullptr) {
		return false;
	}

	//removing first item
	if (head->data == itemRemoved) {
		Node* node2remove = head;
		head = head->next;
		delete node2remove;
		return true;
	}

	//removing item other than first item
	Node* current = head->next;
	Node* prev = head;


	if (tail->data == itemRemoved) { //I do not know why it's not removing 25 :(

		//count = how many nodes are in the list
		int counting = count();

		//create a node pointer and set it equal to head
		Node* secondToLastNode = head;

		//finding the second to last node (counting -1)
		for (int i = 0; i < counting - 1; i++) {

			secondToLastNode = secondToLastNode->next;
		}
		//tail is set to the secondToLastNode (which becomes the tail)
		tail = secondToLastNode;

		return true;
	}


	while (current != nullptr) {

		//removes item from list by deleting current 
		if (current->data == itemRemoved) {
			prev->next = current->next;
			delete current;
			return true;
		}
		prev = current;
		current = current->next;
	}
	//data wasn't in list
	return false;
}


template<typename type>
void UnOrderedList<type>::removeAll()
{
	Node* current = head;
	while (current != NULL) {
		Node* temp = current;
		current = current->next;
		delete temp;
	}
	head = NULL;
}

template<typename type>
bool UnOrderedList<type>::findDuplicates(type insertItem) {
	Node* printDuplicate = head;

	while (printDuplicate != nullptr) {
		if (printDuplicate->data == insertItem) {
			std::cout << insertItem << " can not be added\n";
			return true;
		}
		printDuplicate = printDuplicate->next;
	}
	return false;
}