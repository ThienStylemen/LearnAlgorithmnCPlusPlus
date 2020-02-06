﻿#include<iostream>
#include<cmath>
using namespace std;
struct Node { 
	int info; 
	Node *pNext; 
};
struct LinkedList { 
	//dslk đơn chỉ cần giữ 2 node đầu và cuối  //thực tế chỉ cần giữ node đầu  //giữ node cuối là để tiện thao tác  
	Node *pHead, *pTail;
};
Node* createNode(const int& value) {
	Node * create = new Node;
	if (create != nullptr){
		create->info = value;
		create->pNext = nullptr;

	}
	return create;
}

LinkedList* createLinklist() {
	LinkedList* create = new LinkedList;
	if (create != nullptr) {
		create->pHead = create->pTail = nullptr;
	}
	return create;
}

bool AddNode(LinkedList* ll , const int& value) {
	Node* p = createNode(value);
	if (p == nullptr) return false;
	if (ll->pHead == nullptr) {
		ll->pHead = ll->pTail = p;
		return true;
	}
	ll->pTail->pNext = p;
	ll->pTail = p;
	return true;
}

LinkedList* generateLinklist(const int &numbers_min, const int & numbers_max, const int & min_value, const int & max_value) {
	LinkedList * create = new LinkedList;
	if (create != nullptr) {
		create->pHead = nullptr;
	}
	int numbers = numbers_min + rand() % (numbers_max - numbers_min + 1);
	for (int i = 0; i < numbers; i++) {
		AddNode(create, min_value + rand() % (max_value - min_value + 1));
	}
	return create;
}

void Output(LinkedList* ll) {
	for (Node *p = ll->pHead; p != ll->pTail; p = p->pNext) {
		cout << p->info << "\t";
	}
}

void deleteLL(LinkedList* ll) {
	Node* p = ll->pHead;
	while (p->pNext != nullptr) {
		Node* temp = p;
		p=p->pNext;
		delete temp;
	}
	delete ll->pTail;
}
LinkedList* SplitElementsLowerThanX(LinkedList* ll, int x) {
	LinkedList* create = createLinklist();
	Node* p = ll->pHead;
	while (p->pNext != ll->pTail){
		if (p->pNext->info < x) {
			AddNode(create, p->info);

			Node* temp = p->pNext;
			p->pNext = p->pNext->pNext;
			temp->pNext = nullptr;
			delete temp;
		}
		else {
			p = p->pNext;
		}
	}
	return create;
}

int main() {
	LinkedList* ll1 = generateLinklist(10, 100, -50, 50);
	Output(ll1);
	cout << endl << "------------------------------" << endl;
	
	LinkedList* ll2 = createLinklist();
	ll2 = SplitElementsLowerThanX(ll1, 4);
	Output(ll2);
	cout << endl << "------------------------------" << endl;
	Output(ll1);
	deleteLL(ll1);
	deleteLL(ll2);
	delete ll1;
	delete ll2;
	system("pause");
	return 0;
}