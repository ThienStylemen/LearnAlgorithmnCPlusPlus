#include <iostream>
#include <string>
#include <stack>
using namespace std;
struct bo {
	int n;
	char a;
	char b;
	char c;
};

// Ham nay ko chay dc
void ThapHaNoi( int n, char A, char B, char C) {
	bo nhom{ n,A,B,C };

	stack<bo> stk;
	stk.push(nhom);
	while (!stk.empty()) {
		stk.pop();

		if (n == 1)
			cout << "\nChuyen " << nhom.a << " qua " << nhom.c;
		else {
			nhom.n = n - 1; nhom.a = A; nhom.b = C; nhom.c = B;
			stk.push(nhom);
			nhom.n = 1; nhom.a = A; nhom.b = B; nhom.c = C;
			stk.push(nhom);
			nhom.n = n - 1; nhom.a = B; nhom.b = A; nhom.c = C;
			stk.push(nhom);
		} 
	}
}

void chuyen(int n, char nguon, char trunggian, char dich) {
	if (n == 1) {
		cout << nguon << "--->" << dich << endl;
	}
	else {
		chuyen(n - 1, nguon, dich, trunggian);
		chuyen(1, nguon, trunggian, dich);
		chuyen(n - 1, trunggian, nguon, dich);
	}
}

int main() {
	int n;
	cout << "Nhap so dia n= ";
	cin >> n;
	chuyen(n, 'A', 'B', 'C');

	//ThapHaNoi(5,'A', 'B', 'C' );
	system("pause");
	return 0;
}