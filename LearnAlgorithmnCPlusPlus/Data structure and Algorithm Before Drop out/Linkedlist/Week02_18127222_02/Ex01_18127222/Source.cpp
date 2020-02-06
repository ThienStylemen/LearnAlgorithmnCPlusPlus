#include<iostream>
#include<cmath>
using namespace std;
template<class T>
struct Node {
	T info;
	Node *pNext, *pPrevious;
};
template<class T>
struct LinkedList {
	//dslk đơn chỉ cần giữ 2 node đầu và cuối  //thực tế chỉ cần giữ node đầu  //giữ node cuối là để tiện thao tác  
	Node<T> *pHead, *pTail;
};
template<class T>
Node<T>* createNode(const T& value) {
	Node<T> *create = new Node<T>;
	if (create != nullptr) {
		create->info = value;
		create->pNext = nullptr;
		create->pPrevious = nullptr;
	}
	return create;
}
template<class T>
LinkedList<T>* createLinklist() {
	LinkedList<T>* create = new LinkedList<T>;
	if (create != nullptr) {
		create->pHead = create->pTail = nullptr;
	}
	return create;
}

template<class T>
bool AddNodeToTheTail(LinkedList<T>* ll, const int& value) {
	Node<T>* p = createNode(value);
	if (p == nullptr) return false;
	if (ll->pHead == nullptr) {
		ll->pHead = ll->pTail = p;
		return true;
	}
	else {
		ll->pTail->pNext = p;
		p->pPrevious = ll->pTail;
		ll->pTail = p;
	}
	return true;
}
template<class T>
void DeleteFirstNode(LinkedList<T>* ll) {
	Node<T>* temp = ll->pHead;
	ll->pHead = ll->pHead->pNext;
	delete temp;
}
template<class T>
void DeleteFinalNode(LinkedList<T>* ll) {
	Node<T>* temp = ll->pTail;
	ll->pTail = ll->pTail->pPrevious;
	ll->pTail->pNext = nullptr;
	delete temp;
}
template<class T>
bool AddNodeToTheHead(LinkedList<T>* ll, const T& value) {
	Node<T>* p = createNode(value);
	if (p == nullptr) return false;
	if (ll->pHead == nullptr) {
		ll->pHead = ll->pTail = p;
		return true;
	}
	else {
		p->pNext = ll->pHead;
		ll->pHead->pPrevious = p;
		ll->pHead = p;
	}
	return true;
}
template<class T>
void OutLL(LinkedList<T>* dll) {
	Node<T>* p = dll->pHead;
	while (p != nullptr) {
		cout << p->info << "\t";
		p = p->pNext;
	}
}
template<class T>
bool find(LinkedList<T>* ll, const T& value) {
	Node<T>* p = ll->pHead;
	while (p != nullptr) {
		if (p->pNext->info == value) {
			return true;
		}
		p = p->pNext;
	}
	return false;
}
template<class T>
void DeleteANote(LinkedList<T>* ll, const T& value) {
	Node<T>* p = ll->pHead;
	while (p->pNext != nullptr) {
		if (p->pNext->info == value) {
			Node<T>* temp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete temp;
		}
		p = p->pNext;
	}
	if (ll->pHead->info == value)
		DeleteFirstNode(ll);
	if (ll->pTail->info == value)
		DeleteFinalNode(ll);
}
template<class T>
ostream & operator<<(ostream & os, const LinkedList<T> & dll)
{
	Node<T> * tmp = dll.pHead;
	while (tmp){
		os << tmp->data << " ";
		tmp = tmp->next;
	}
	return os;
}

template<class T>
void deleteLL(LinkedList<T>* ll) {
	Node<T>* p = ll->pHead;
	while (p != nullptr) {
		Node<T>* temp = p;
		p = p->pNext;
		delete temp;
	}
}

int main() {
	//LinkedList<int> *ll1 = createLinklist();
	LinkedList<int> *dll = new LinkedList<int>;
	if (dll != nullptr) {
		dll->pHead = nullptr;
		dll->pTail = nullptr;
	}

	AddNodeToTheHead(dll, 3);
	AddNodeToTheHead(dll, 4);
	AddNodeToTheHead(dll, 5);
	AddNodeToTheTail(dll, 6);
	AddNodeToTheTail(dll, 7);
	AddNodeToTheTail(dll, 8);
	AddNodeToTheTail(dll, 9);
	OutLL(dll);
	cout << endl;
	DeleteFirstNode(dll);
	DeleteFinalNode(dll);
	OutLL(dll);
	cout <<endl << find(dll, 6);
	DeleteANote(dll, 6);
	cout << endl; OutLL(dll);

	//cout << endl << "------------------------------" << endl;
	//Output(ll1);
	//deleteLL(ll1);
	//cout << endl << "------------------------------" << endl;
	//Output(ll1);
	deleteLL(dll);
	delete dll;

	system("pause");
	return 0;
}
