#include<iostream>
#include<fstream>
#include<chrono>
#include<ratio>
#include<ctime>
#include<vector>
using namespace std;
using namespace std::chrono;

bool binarySearch(int arr[], int l, int r, int x){
	if (r >= l) {
		int mid = (l + r) / 2;
		if (arr[mid] == x)
			return true;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return false;
}
int main() {
	int n;
	int x;
	int arr[100000];
	ifstream fIn_bin4;
	fIn_bin4.open("100000nSorted.bin", ios::binary);
	//ofstream fOut_txt4;
	//fOut_txt2.open("10000n.txt");
	if ( fIn_bin4.is_open() ) {
		for (int i = 0; i < 100000; i++) {
			fIn_bin4.read((char*)&n, 4);
			arr[i] = n;
		}
	}
	fIn_bin4.close();

	ofstream fOut_txt;
	fOut_txt.open("ResultBS.txt");
	if (fOut_txt.is_open()){
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		cout << binarySearch(arr, 0, 99999, 1511) << endl;
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double, std::milli> time_span = t2 - t1;
		fOut_txt << time_span.count() << endl;

		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		cout << binarySearch(arr, 0, 99999, 4979495) << endl;
		high_resolution_clock::time_point t4 = high_resolution_clock::now();
		duration<double, std::milli> time_span1 = t4 - t3;
		fOut_txt << time_span1.count() << endl;

		high_resolution_clock::time_point t5 = high_resolution_clock::now();
		cout << binarySearch(arr, 0, 99999, 9999843) << endl;
		high_resolution_clock::time_point t6 = high_resolution_clock::now();
		duration<double, std::milli> time_span2 = t6 - t5;
		fOut_txt << time_span2.count() << endl;

		high_resolution_clock::time_point t7 = high_resolution_clock::now();
		cout << binarySearch(arr, 0, 99999, 5503353) << endl;
		high_resolution_clock::time_point t8 = high_resolution_clock::now();
		duration<double, std::milli> time_span3 = t8 - t7;
		fOut_txt << time_span3.count() << endl;

	}

	system("pause");
	return 0;
}
