#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
using namespace std;

struct Student {
	string name;
	int id;
	double gpa;
	bool operator ==(const Student & other) const {
		return this->id == id;
	}
};

struct Node{
	Student student;
	Node* pNext, *pPrevious;
};

Node* createNode(const Student& student) {
	Node *create = new Node;
	if (create != nullptr) {
		create->student = student;
		create->pNext = nullptr;
		create->pPrevious = nullptr;
	}
	return create;
}
struct LinkedList {
	//dslk đơn chỉ cần giữ 2 node đầu và cuối  //thực tế chỉ cần giữ node đầu  //giữ node cuối là để tiện thao tác  
	Node *pHead, *pTail;
};

void gen_random(string& s, const int len) {
	static const string alphanum =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";
	s = "123456789101112131415";
	for (int i = 0; i < len; ++i) {
		
		s[i] = (alphanum[rand() % (sizeof(alphanum) - 1)]) ;
	}
	s[len] = 0;
}

bool AddNode(LinkedList* ll, const Student& value) {
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

LinkedList* generateLinklist(const int &numbers_min, const int & numbers_max) {
	LinkedList * create = new LinkedList;
	if (create != nullptr) {
		create->pHead = nullptr;
	}
	int numbers = numbers_min + rand() % (numbers_max - numbers_min + 1);
	string name_student;
	for (int i = 0; i < numbers; i++) {
		gen_random(name_student, 20);
		srand(time(0));
		int id = rand() % (numbers_max-1);
		double gpa =( (double) rand() / 10000) ;
		AddNode(create, { name_student, id, gpa} );
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

void OutLL(LinkedList* dll) {
	Node* p = dll->pHead;
	while (p != nullptr) {
		cout << p->student.name << " " << p->student.id << " " << p->student.gpa << endl;
		p = p->pNext;
	}
}

void findStudentByAPartOfID(LinkedList* ll, int value) {
	Node* p = ll->pHead;
	while (p != nullptr) {
		if (p->student.id == value) {
			cout << p->student.name << " " << p->student.id << " " << p->student.gpa << endl;
		}
		p = p->pNext;
	}
}
void DeleteFirstNode(LinkedList* ll) {
	Node* temp = ll->pHead;
	ll->pHead = ll->pHead->pNext;
	delete temp;
}
void DeleteFinalNode(LinkedList* ll) {
	Node* temp = ll->pTail;
	ll->pTail = ll->pTail->pPrevious;
	ll->pTail->pNext = nullptr;
	delete temp;
}
void DeleteANote(LinkedList* ll, const Student& value) {
	Node* p = ll->pHead;
	while (p->pNext != nullptr) {
		if (p->pNext->student == value) {
			Node* temp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete temp;
		}
		p = p->pNext;
	}
	if (ll->pHead->student == value)
		DeleteFirstNode(ll);
	if (ll->pTail->student == value)
		DeleteFinalNode(ll);
}

void DeleteStudentGPALowerthan5(LinkedList* ll) {
	Node* p = ll->pHead;
	while (p->pNext != nullptr) {
		if (p->pNext->student.gpa < 5) {
			Node* temp = p->pNext;
			p->pNext = p->pNext->pNext;
			delete temp;
		}
		p = p->pNext;
	}
	if (ll->pHead->student.gpa < 5)
		DeleteFirstNode(ll);
	if (ll->pTail->student.gpa < 5)
		DeleteFinalNode(ll);
}

void deleteLL(LinkedList* ll) {
	Node* p = ll->pHead;
	while (p != nullptr) {
		Node* temp = p;
		p = p->pNext;
		delete temp;
	}
}

int main() {
	LinkedList *ll1 = createLinklist();
	ll1 = generateLinklist(10, 20);
	OutLL(ll1);
	DeleteStudentGPALowerthan5(ll1);
	findStudentByAPartOfID(ll1, 30);
	deleteLL(ll1);
	delete ll1;

	system("pause");
	return 0;
}
