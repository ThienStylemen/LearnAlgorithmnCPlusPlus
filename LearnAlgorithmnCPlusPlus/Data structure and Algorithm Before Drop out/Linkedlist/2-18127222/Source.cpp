#include<iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
struct CircularLinkedList {
	Node* pHead;
};
Node* createNode(int value);
CircularLinkedList* CreateCircularLinkedList();
void AddNode(CircularLinkedList* cll, int value);
void DeleteNode(CircularLinkedList* cll, int value);
void printList(CircularLinkedList* cll);
void deleteLL(CircularLinkedList* cll);

int main() {
	CircularLinkedList* cirll;
	cirll = CreateCircularLinkedList();
	AddNode(cirll, 3);
	AddNode(cirll, 4);
	AddNode(cirll, 5);
	DeleteNode(cirll, 4);
	AddNode(cirll, 6);
	// now head is at 6;
	printList(cirll);
	cout << "OK" << endl;
	deleteLL(cirll);
	cout << "OK" << endl;
	
	system("pause");
	return 0;
}

Node* createNode(int value) {
	Node* create = new Node;
	if (create != nullptr) {
		create->data = value;
		create->next = nullptr;
	}
	return create;
}


CircularLinkedList* CreateCircularLinkedList() {
	CircularLinkedList* cll = new CircularLinkedList;
	if (cll->pHead != nullptr) {
		cll->pHead = nullptr;
	}
	return cll;
}

void AddNode(CircularLinkedList* cll, int value) {
	Node * create = createNode(value);
	if (cll->pHead == nullptr) {
		cll->pHead = create;
		create->next = cll->pHead;
	}
	else {
		create->next = cll->pHead->next;
		cll->pHead->next = create;
		cll->pHead = create;
	}
}
void DeleteNode(CircularLinkedList* cll, int value) {
	if (cll->pHead == nullptr)
		return;
	else {
		Node* saving = cll->pHead;
		while (cll->pHead->next != saving) {
			if (cll->pHead->next->data == value) {
				Node* temp = cll->pHead->next;
				cll->pHead->next = temp->next;
				delete temp;
				continue;
			}
			cll->pHead = cll->pHead->next;
		}
	}
}
void printList(CircularLinkedList* cll ) {
	Node* save = cll->pHead;
	while (cll->pHead->next != save) {
		cout << cll->pHead->data << "\t";
		cll->pHead = cll->pHead->next;
	}
	cout << cll->pHead->data;
}
void deleteLL(CircularLinkedList* cll) {
	Node* save = cll->pHead;
	while (cll->pHead->next != save) {
		Node* temp = cll->pHead->next;
		cll->pHead->next = temp->next;
		delete temp;
	}

}
