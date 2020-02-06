#include<iostream>
#include<fstream>
#include<chrono>
#include<ratio>
#include<ctime>
#include<vector>
using namespace std;
using namespace std::chrono;

bool InterpolationSearch(int arr[], int l, int r, int x){
	while (l <= r && x >= arr[l] && x <= arr[r]) {
		if (l == r) {
			if (arr[l] == x)
				return true;
			return false;
		}
		int pos = l + (((double)(r - l) /
			(arr[r] - arr[l])) * (x - arr[l]));
		if (arr[pos] == x)
			return true;
		if (arr[pos] < x)
			l = pos + 1;
		else
			l = pos - 1;
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
	fOut_txt.open("ResultIS.txt");
	if (fOut_txt.is_open()){
		high_resolution_clock::time_point t1 = high_resolution_clock::now();
		cout << InterpolationSearch(arr, 0, 99999, 1511) << endl;
		high_resolution_clock::time_point t2 = high_resolution_clock::now();
		duration<double, std::milli> time_span = t2 - t1;
		fOut_txt << time_span.count() << endl;

		high_resolution_clock::time_point t3 = high_resolution_clock::now();
		cout << InterpolationSearch(arr, 0, 99999, 4979495) << endl;
		high_resolution_clock::time_point t4 = high_resolution_clock::now();
		duration<double, std::milli> time_span1 = t4 - t3;
		fOut_txt << time_span1.count() << endl;

		high_resolution_clock::time_point t5 = high_resolution_clock::now();
		cout << InterpolationSearch(arr, 0, 99999, 9999843) << endl;
		high_resolution_clock::time_point t6 = high_resolution_clock::now();
		duration<double, std::milli> time_span2 = t6 - t5;
		fOut_txt << time_span2.count() << endl;

		high_resolution_clock::time_point t7 = high_resolution_clock::now();
		cout << InterpolationSearch(arr, 0, 99999, 5503353) << endl;
		high_resolution_clock::time_point t8 = high_resolution_clock::now();
		duration<double, std::milli> time_span3 = t8 - t7;
		fOut_txt << time_span3.count() << endl;
	}

	system("pause");
	return 0;
}
