#include<iostream>
#include<fstream>
#include<vector>
#define MAXBUF 1000
using namespace std;
struct  Params{
	long l;	// chieu dai chuoi con
	long long p, m; // tham so cho hash
	long long hashed;// gia tri hash cua chuoi con (giu de ko phai tinh lai)
	long iCur;	// vi tri dang xet tren doc
	long min;	//gia tri de chuyen doi sao cho ky tu nho nhat tuong ung gia tri 1
	long long *sHashed;	// mang giu cac gia tri hash cua chuoi con tu doc
	long long *pHashed;	// mang giu  cac gia tri hash cua chuoi con 
};

void Search(const char*s, const char *SDoc, bool Compare(const char*, const char *, const Params &)) {
	int lS = strlen(s);
	int lDoc = strlen(SDoc);
	Params p;
	p.min = 0x2F;	// lay gia tri ky tu nho nhat giam 1
	p.l = lS;	
	p.m = 1000000007;// lay gia tri m co ban la 10^9+7, su dung trong pham vi int 32bit
	p.p = 79;	// thần tài
	p.pHashed = new long long[lDoc];
	p.sHashed = new long long[lDoc];
	// tinh truoc cac gia tri hash trong chuoi con va p^n;
	p.pHashed[0] = 1;
	p.sHashed[0] = SDoc[0] - p.min;
	for (int i = 0; i < lDoc; i++) {
		p.pHashed[i] = (p.pHashed[i - 1] * p.p) % p.m;
		p.sHashed[i] = p.sHashed[i - 1] + (SDoc[i] - p.min)* p.pHashed[i] % p.m;
	}
	p.hashed = 0;
	for (int i = 0; i < p.l; i++) {
		p.pHashed[i] = (p.pHashed[i - 1] * p.p) % p.m;
	}
	for (int i = 0; i < lDoc - lS; i++) {
		p.iCur = i;
		if (Compare(s, SDoc, p))
			cout << i << endl;
	}
}

bool CompareBruteForce(const char *s1, const char *s2, const Params &p) {
	for (int i = 0; i < p.l; i++) {
		if (s1[i] != s2[i + p.iCur])
			return false;
	}
	return true;
}

bool CompareHashing(const char* s1, const char* s2, const Params &p) {
	int hashed = 0;
	if (p.iCur > 0) {
		hashed = (p.sHashed[p.iCur + p.l - 1] - p.sHashed[p.iCur - 1] + p.m) % p.m;
	}
	else {
		hashed = p.sHashed[p.l - 1];
	}
}

int main() {
	// Load chuỗi và lấy kích thước file (chiều dài doc) 

	ifstream fDoc, fInput;
	fDoc.open("doc_1m.txt", ios::binary | ios::ate);

	int fl = (int)fDoc.tellg();
	char *sDoc = new char[fl + 1];
	fDoc.seekg(0);
	fDoc.get(sDoc, fl + 1);
	fDoc.close();

	fInput.open("input_str_1m.txt");
	int nS = 0, lBuf = 0;
	char *buf = new char[MAXBUF];
	fInput >> nS;
	fInput.getline(buf, MAXBUF);
	
	char* *arrStr = new char*[nS];
	for (int i = 0; i < nS; i++) {
		fInput.getline(buf, MAXBUF);
		lBuf = strlen(buf);
		arrStr[i] = new char[lBuf + 1];
		strcpy_s(arrStr[i], lBuf + 1, buf);
	}
	delete[] buf;
	fInput.close();

	system("pause");
	return 0;
}