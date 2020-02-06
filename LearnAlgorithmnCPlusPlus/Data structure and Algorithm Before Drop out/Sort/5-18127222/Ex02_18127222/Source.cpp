#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

class Array {
private:
	int *A;
	int N;
public:
	Array(int N);
	~Array();
	void BubleSort();
	void SelectionSort();
	void InsertionSort();
	void MergerSort(int l, int r);
	void Merge_Elements_or_Arrays(int left, int mid, int right);
	void QuickSort( int left, int right);
	int GetN();
	void Display();
};
int Array::GetN() {
	return this->N;
}
void Array::Display() {
	for (int i = 0; i < this->N; i++) {
		cout << this->A[i] << "\t";
	}
}
void Array::BubleSort() {
	for (int i = 0; i < this->N; i++) {
		bool swap = false;
		for (int j = 0; j < this->N - 1; j++) {
			if (this->A[j] > this->A[j + 1]) {
				int temp = this->A[j];
				this->A[j + 1] = this->A[j];
				this->A[j] = temp;
				swap = true;
			}
		}
		if (!swap) break;
	}
}
void Array::SelectionSort() {
	for (int i = 0; i < this->N; i++) {
		int min_index = i;
		for (int j = i + 1; j < this->N; j++) {
			if (this->A[j] < this->A[min_index]) {
				min_index = j;
			}
		}
		int temp = this->A[i];
		this->A[i] = this->A[min_index];
		this->A[min_index] = temp;
	}
}

void Array::InsertionSort() {
	int x, pos;
	// gia su A[0] da dc sap xep
	for (int i = 1; i < this->N; i++) {
		x = this->A[i]; // #(swap)
		for (pos = i; pos >0 && x < this->A[pos - 1] ; pos--)
			this->A[pos] = this->A[pos - 1];
		this->A[pos] = x;	// #(swap)
	}
}

void Array::Merge_Elements_or_Arrays(int left, int mid, int right) {
	int i, j, k;
	int n1 = mid - left + 1;
	int n2 = right - mid;
	/* create temp arrays */
	vector<int> L(n1);
	vector<int> R(n2);
	
	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = this->A[left + i];
	for (i = 0; i < n2; i++)
		R[i] = this->A[mid + 1 + i];
	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = left; // Initial index of merged subarray 
	while (i < n1 && j < n2){
		if (L[i] <= R[j]) 
			this->A[k++] = L[i++];
		else 
			this->A[k++] = R[j++];
	}
	/* Copy the remaining elements of L[], if there are any */
	while (i < n1){
		this->A[k++] = L[i++];
	}
	/* Copy the remaining elements of R[], if there are any */
	while (j < n2){
		this->A[k++] = R[j++];
	}
}
void Array::MergerSort(int l, int r) {
	if (l >= r) return;	// split util one, then return (l==r)
	int mid = (l + r) / 2;
	MergerSort(l, mid);
	MergerSort(mid + 1, r);
	Merge_Elements_or_Arrays( l, mid, r);
}
void Array::QuickSort(int left, int right) {
	if (left > right)
		return;
	
	int pivot = this->A [ (left + right)/2 ];
	int i = left; 
	int j = right;
	
	do{
		while (this->A[i] < pivot) i++;
		while (this->A[j] > pivot) j--;
		if (i <= j) {
			int temp = this->A[i];
			this->A[i] = this->A[j];
			this->A[j] = temp;
			i++;
			j--;
		}
	}
	while ( i < j );

	QuickSort(left, j);	
	QuickSort(i, right);
}
Array::Array(int N) {
	this->N = N;
	this->A = new int[N];
	for (int i = 0; i < N; i++){
		this->A[i] = rand() % 100;
	}
}
Array::~Array() {
	delete[] this->A;
}
int main() {
	Array Arr(30);
	//Arr.BubleSort();
	//Arr.SelectionSort();
	//Arr.InsertionSort();
	// Arr.MergerSort(0,Arr.GetN()-1);

	Arr.QuickSort(0, Arr.GetN() -1 );
	
	Arr.Display();
	system("pause");
	return 0;
}