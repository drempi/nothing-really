#include <iostream>
#include <cmath>
using namespace std;

int NWD(int a, int b){
	while(true){
		if(a > b){
			a = a%b;
			if(a == 0){
				return b;
			}
		} else {
			b = b%a;
			if(b == 0){
				return a;
			}
		}
	}
}

int NWW(int a, int b){
	return a*b / NWD(a, b);
}

int main(){
	int n = 8;
	int reszty[n];
	int modulo[n];
	reszty[0] = 0;
	reszty[1] = 2;
	reszty[2] = 0;
	reszty[3] = 3;
	reszty[4] = 4;
	reszty[5] = 45;
	reszty[6] = 36;
	reszty[7] = 175;
	reszty[7] = 288;
	modulo[0] = 9;
	modulo[1] = 8;
	modulo[2] = 7;
	modulo[3] = 6;
	modulo[4] = 5;
	modulo[5] = 4;
	modulo[6] = 3;
	modulo[7] = 2;
	modulo[8] = 1;
	for(int i = 0; i < n; i++){
		reszty[i] = reszty[i] % modulo[i];
	}
	int reszta = 0;
	int obecne = 1;
	bool czy = true;
	for(int i = 0; i < n; i++){
		int nwd = NWD(obecne, modulo[i]);
		if(reszta % nwd != reszty[i] % nwd){
			cout << "BLAD!!" << endl;
			czy = false;
			break;
		} else {
			while(reszta % modulo[i] != reszty[i]){
				reszta += obecne;
			}
			obecne *= modulo[i] / nwd;
		}
	}
	if(czy){
		cout << "x = " << reszta << "  (mod " << obecne << ")" << endl;
	}
}