#include<iostream>
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
void SortLinklist(LinkedList *ll) {
	for (Node* p = ll->pHead; p != ll->pTail; p = p->pNext) {
		for (Node * q = p->pNext; q != ll->pTail; q = q->pNext) {
			if (p->info > q->info) {
				int temp = q->info;
				q->info = p->info;
				p->info = temp;
			}
		}
	}
}

void Output(LinkedList* ll) {
	for (Node *p = ll->pHead; p != ll->pTail; p = p->pNext) {
		cout << p->info << "\t";
	}
}

void deleteLL(LinkedList* ll) {
	for (Node *p = ll->pHead; p != NULL; p = p->pNext) {
		delete p;
	}
}

void Mix_Sort(LinkedList* ll1, LinkedList* ll2, LinkedList* ll3) {
	Node *p1 = ll1->pHead;
	Node *p2 = ll2->pHead;
	while (!(p1 == nullptr || p2 == nullptr)) {
		if (p1->info <= p2->info) {
			AddNode(ll3, p1->info);
			p1 = p1->pNext;
			continue;
		}
		AddNode(ll3, p2->info);
		p2 = p2->pNext;
	}
	Node* p_remain;
	if (p1 != nullptr) {
		p_remain = p1;
	}
	else {
		p_remain = p2;
	}
	while (p_remain != nullptr) {
		AddNode(ll3, p_remain->info);
		p_remain = p_remain->pNext;
	}
}

int main() {
	LinkedList* ll1 = generateLinklist(5, 10, -1000, 2000);
	Output(ll1);
	cout << endl << "------------------------------" << endl;
	LinkedList* ll2 = generateLinklist(5, 10, -1000, 2000);
	Output(ll2);
	cout << endl << "------------------------------" << endl;
	SortLinklist(ll1);
	Output(ll1);
	cout << endl << "------------------------------" << endl;
	SortLinklist(ll2);
	Output(ll2);
	cout << endl << "------------------------------" << endl;

	LinkedList* ll3 = createLinklist();
	Mix_Sort(ll1, ll2, ll3);
	Output(ll3);

	deleteLL(ll1);
	deleteLL(ll2);
	deleteLL(ll3);
	delete ll1;
	delete ll2;
	delete ll3;
	system("pause");
	return 0;
}