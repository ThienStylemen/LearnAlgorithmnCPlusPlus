#include<iostream>
#include<fstream>
#include<ctime>
#include<vector>
using namespace std;

int main() {
	ifstream fIn_txt;
	ofstream fOut_bin;
	// doc txt -> bin
	fIn_txt.open("1000n.txt");
	int n;
	int x;
	if (fIn_txt.is_open()) {
		fIn_txt >> n;
		fOut_bin.open("1000n.bin", ios::binary);
		if (fOut_bin.is_open()) {
			for (int i = 0; i < 1000; i++) {
				fIn_txt >> x;
				fIn_txt.seekg(1, ios::cur);	// move cursor one more
				fOut_bin.write((char*)&x, sizeof(x));
			}
		}
		fOut_bin.close();
		fIn_txt.close();
	}

	// doc bin --> txt
	ifstream fIn_bin2;
	fIn_bin2.open("10000n.bin", ios::binary);
	ofstream fOut_txt2;
	fOut_txt2.open("10000n.txt"); 
	if (fIn_bin2.is_open() && fOut_txt2.is_open()) {
		for (int i = 0; i < 10000; i++) {
			fIn_bin2.read((char*)&n, 4);
			fOut_txt2 << n << " ";
		}
	}
	fIn_bin2.close();
	fOut_txt2.close();
	
	// 100000nSorted.txt --> bin
	ifstream fIn_txt3;
	ofstream fOut_bin3;
	fIn_txt3.open("100000nSorted.txt");
	if (fIn_txt3.is_open()) {
		fIn_txt3 >> n ;
		fOut_bin3.open("100000nSorted.bin", ios::binary);
		if (fOut_bin3.is_open()) {
			for (int i = 0; i < 100000; i++) {
				fIn_txt3 >> x;
				fIn_txt3.seekg(1, ios::cur);	// move cursor one more
				fOut_bin3.write((char*)&x, sizeof(x));
			}
		}
	}
	fIn_txt3.close();
	fOut_bin3.close();

	//ofstream fout;
	//ifstream f;	// mo chi de doc
	////ostream a;	// mo chi de ghi
	//ifstream fIn;
	//ofstream fOut;
	//fIn.open("100n.txt");
	//fOut.open("1000n.txt");	// neu file chua co thi tao moi
	//fOut.close();
	//int n, x;
	//fIn >> n;
	//if (fIn.is_open()) fIn.close();
	//if (fOut.is_open()) fOut.close();
	//fOut.write((const char*)&n, sizeof(n));
	///* ghi lai thoi gian chay */
	//clock_t t = clock();	// ham clock() tra ve thoi gian luc ogi clock()
	////goi lan nua lay hieu, (milisecond)


	system("pause");
	return 0;
}
