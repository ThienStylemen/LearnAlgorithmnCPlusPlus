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

bool AddNodeStackStyle(LinkedList* ll , const int& value) {
	Node* p = createNode(value);
	if (p == nullptr) return false;
	if (ll->pHead == nullptr) {
		ll->pHead = ll->pTail = p;
		return true;
	}
	p->pNext = ll->pHead;
	ll->pHead = p;
	return true;
}

LinkedList* generateLinklist(const int &numbers_min, const int & numbers_max, const int & min_value, const int & max_value) {
	LinkedList * create = new LinkedList;
	if (create != nullptr) {
		create->pHead = nullptr;
	}
	int numbers = numbers_min + rand() % (numbers_max - numbers_min + 1);
	for (int i = 0; i < numbers; i++) {
		AddNodeStackStyle(create, min_value + rand() % (max_value - min_value + 1));
	}
	return create;
}

void Output(LinkedList* ll) {
	Node *p = ll->pHead;
	for (p; p != ll->pTail; p = p->pNext) {
		cout << p->info << "\t";
	}
	cout << p->info;
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
int GetNode_value_and_pop_stack_style(LinkedList* ll) {
	Node* p = ll->pHead;
	ll->pHead = ll->pHead->pNext;
	p->pNext = nullptr;
	int temp = p->info;
	delete p;
	return temp;
}
bool isEmtpy_stack(LinkedList* ll) {
	return (ll->pHead == nullptr);
}

int main() {

	LinkedList* ll1 = createLinklist();
	AddNodeStackStyle(ll1, 5);
	AddNodeStackStyle(ll1, 6);
	Output(ll1);
	int a = GetNode_value_and_pop_stack_style(ll1);
	cout << a;
	a = GetNode_value_and_pop_stack_style(ll1);
	cout << a;

	cout << isEmtpy_stack(ll1);
	AddNodeStackStyle(ll1,5);
	AddNodeStackStyle(ll1, 6);
	deleteLL(ll1);
	//delete ll1;
	system("pause");
	return 0;
}