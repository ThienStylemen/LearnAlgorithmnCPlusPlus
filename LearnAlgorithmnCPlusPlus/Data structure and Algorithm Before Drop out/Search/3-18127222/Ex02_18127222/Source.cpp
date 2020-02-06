#include<iostream>
#include<cmath>
#include<ctime>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

// 9 hours for efforts

class Dictionary {
private:
	vector<string> words;
public:
	void AddAWords(string someword);
	void Sorts();
	unsigned int CountAllWords();
	int LinearSearch(string wheree);
	int LinearSearch_AddSentinel(string wheree);
	Dictionary();
	int BinarySearch(int left, int right, string wheree);
	int Interpolation_Binary_search(int left, int right, string wheree);

	void DisplayAGame(string word_guessing);

};
Dictionary::Dictionary() {
	this->words.clear();
}
bool stringcompare(string a, string b) {
	int size = max(a.size(), b.size());
	for (int i = 0; i < size; i++) {
		if (a[i] == b[i])
			continue;
		else if ((int)a[i] < (int)b[i]) {
			return a < b;
		}
		else return false;
	}
}

void Dictionary::AddAWords(string someword) {
	this->words.push_back(someword);
}

unsigned int Dictionary::CountAllWords() {
	return this->words.size();
}

void Dictionary::Sorts() {
	sort(this->words.begin(), this->words.end(), stringcompare);
}

int Dictionary::LinearSearch(string wheree) {
	for (int i = 0; i < this->words.size(); i++) {
		if (this->words[i] == wheree) {
			return i;
		}
	}
	return -1;
}

int Dictionary::LinearSearch_AddSentinel(string wheree) {
	this->words.push_back(wheree);
	int i = 0;
	while (this->words[i] != wheree) {
		i++;
	}
	if (i <= this->words.size() ) {
		this->words.pop_back();
		return i;
	}
	this->words.pop_back();
	return -1;
}

int Dictionary::BinarySearch(int left, int right, string wheree) {
	if (left <= right) {
		int mid = right + (left - right) / 2;
		if (wheree.compare(this->words[mid]) == 0) {
			return mid;
		}
		if (wheree.compare(this->words[mid]) < 0) {
			return BinarySearch(left, mid - 1, wheree);
		}
		if (wheree.compare(this->words[mid]) > 0) {
			return BinarySearch(mid + 1, right, wheree);
		}
	}
	return -1;
}

int Dictionary::Interpolation_Binary_search(int left, int right, string wheree) {
	if (left <= right) {
		int mid;
		if ((int)wheree[0] < 97) {
			mid = right + (2*left - right) / 2;
		}
		else if ((int)wheree[0] > 97) {
			mid = right + (left - right) / 2;
		}

		if (wheree.compare(this->words[mid]) == 0) {
			return mid;
		}
		if (wheree.compare(this->words[mid]) < 0) {
			return BinarySearch(left, mid - 1, wheree);
		}
		if (wheree.compare(this->words[mid]) > 0) {
			return BinarySearch(mid + 1, right, wheree);
		}
	}
	return -1;
}

void Dictionary::DisplayAGame(string word_guessing) {

}
int main() {
	Dictionary dtn;
	dtn.AddAWords("amember");
	unsigned int numbers = dtn.CountAllWords();

	int index1 = dtn.LinearSearch("someone");
	int index2 = dtn.LinearSearch_AddSentinel("someone2");

	dtn.Sorts();
	dtn.BinarySearch(0, dtn.CountAllWords() - 1, "somewhere");
	dtn.Interpolation_Binary_search(0, dtn.CountAllWords() - 1, "somewhere");
	

	
	system("pause");
	return 0;
}
