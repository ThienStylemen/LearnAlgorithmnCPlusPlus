#include<iostream>
using namespace std;
class node { //define node to store data and next address
public:
	int data;
	node *next;
};
void display(class node* start) {
	node* p = start; // current node set to head
	while (p != NULL) { //traverse until current node isn't NULL
		cout << p->data << " ";
		p = p->next; // go to next node
	}
}
node* getNode(int d) {
	node* temp = new node;
	temp->data = d;
	temp->next = NULL;
	return temp;
}

node* mergeList(node* ll1, node* ll2) { //function for merging two sorted list
	node* newhead = NULL;
	if (ll1 == NULL)
		return ll2;
	if (ll2 == NULL)
		return ll1;
	//recursively merge the lists
	if (ll1->data <= ll2->data) {
		newhead = ll1;
		newhead->next = mergeList(ll1->next, ll2);
	}
	else {
		newhead = ll2;
		newhead->next = mergeList(ll1, ll2->next);
	}
	return newhead;
}

void splitList(node* start, node** ll1, node** ll2) {
	node* slow = start;
	node* fast = start->next;
	while (fast != NULL) {
		fast = fast->next;
		if (fast != NULL) {
			slow = slow->next;
			fast = fast->next;
		}
	}
	*ll1 = start;
	*ll2 = slow->next;
	//spliting
	slow->next = NULL;
}

void mergeSort(node** start) {
	node* head = *start;
	node* ll1, *ll2;
	//base case
	if (head == NULL || head->next == NULL) {
		return;
	}
	splitList(head, &ll1, &ll2);
	mergeSort(&ll1);
	mergeSort(&ll2);
	*start = mergeList(ll1, ll2);
	return;
}


void sortedInsert(node*, node*);

// function to sort a singly linked list using insertion sort 
void insertionSort(node *head)
{
	// Initialize sorted linked list 
	struct node *sorted = NULL;

	// Traverse the given linked list and insert every 
	// node to sorted 
	struct node *current = head;
	while (current != NULL) {
		// Store next for next iteration 
		node *next = current->next;

		// insert current in sorted linked list 
		sortedInsert(sorted, current);

		// Update current 
		current = next;
	}

	// Update head_ref to point to sorted linked list 
	head = sorted;
}

/* function to insert a new_node in a list. Note that this
  function expects a pointer to head_ref as this can modify the
  head of the input linked list (similar to push())*/
void sortedInsert(node* head, node* new_node)
{
	node* current;
	/* Special case for the head end */
	if (head == NULL || head->data >= new_node->data) {
		new_node->next = head;
		head = new_node;
	}
	else {
		/* Locate the node before the point of insertion */
		current = head;
		while (current->next != NULL && current->next->data < new_node->data) {
			current = current->next;
		}
		new_node->next = current->next;
		current->next = new_node;
	}
}
