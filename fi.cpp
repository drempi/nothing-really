#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> dzielniki;

void dziel(long long n){
	int prime = 2;
	int potega = 0;
	while(n % 2 == 0){
		n /= 2;
		potega++;
	}
	long long iloczyn = 1;
	for(int i = 0; i < potega + 1; i++){
		dzielniki.push_back(iloczyn);
		iloczyn *= 2;
	}
	for(long long prime = 3; prime * prime <= n; prime += 2){
		if(n % prime == 0){
			potega = 0;
			while(n % prime == 0){
				n /= prime;
				potega++;
			}
			int size = dzielniki.size();
			long long liczby[potega];
			liczby[0] = prime;
			for(int j = 1; j < potega; j++){
				liczby[j] = prime * liczby[j - 1];
			}
			for(int j = 0; j < size; j++){
				for(int i = 0; i < potega; i++){
					dzielniki.push_back(dzielniki[j] * liczby[i]);
				}
			}
		}
	}
	if(n > 1){
		int size = dzielniki.size();
		for(int j = 0; j < size; j++){
			dzielniki.push_back(dzielniki[j] * n);
		}
	}
	sort(dzielniki.begin(), dzielniki.end());
}

int fi(long long n){
	dzielniki.clear();
	if(n % 2 == 1){
		return 0;
	}
	dziel(n);
	int rozmiar = dzielniki.size();
	int ilosc = 0;
	long long nowy;
	int p;
	int k;
	for(int i = 0; i < rozmiar; i++){
		int p = i;
		int k = rozmiar - i;
		nowy = 2*dzielniki[i];
		// od elementu p do elementu p + k - 1 wlacznie
		// p to wynik koncowy.
		while(k > 1){
			int h = k / 2;
			if(dzielniki[p + h] <= nowy){
				p += h;
				k -= h;
			} else {
				k = h;
			}
		}
		for(int j = i; j < rozmiar; j++){
			nowy = dzielniki[i] + dzielniki[j];
			while(p < rozmiar && dzielniki[p] < nowy){
				p++;
			}
			if(dzielniki[p] == nowy){
				//cout << dzielniki[i] << "   " << dzielniki[j] << endl;
				if(j == i){
					ilosc++;
				} else {
					ilosc += 2;
				}
			}
		}
	}
	return ilosc;
}

int main(){
	/*double suma = 0;
	bool czy = false;
	int potega = 1;
	for(int n = 2; n < 1000; n += 2){
		if(czy){
			//cout << ", " << fi(n);
		} else {
			//suma += sqrt(fi(n));
			if(n == potega){
				//cout << n << ".\t" << fi(n) << endl;
				//potega *= 2;
			}
		}
	}*/
	long long w = 1;
	int size = 13;
	int dzielniki_pierwsze = 3;
	dzielniki_pierwsze += 2;
	int potega = 30;
	int tablica[size][dzielniki_pierwsze];
	for(int i = 0; i < dzielniki_pierwsze; i++){
		for(int j = 0; j < size; j++){
			tablica[j][i] = 0;
		}
	} 
	for(int j = 0; j < size; j++){
		tablica[j][0] = fi(2*w);
		cout << "i = 0   j = " << j << "\t" << tablica[j][0] << endl;
		w *= potega;
	}
	for(int i = 1; i < dzielniki_pierwsze; i++){
		cout << "====================================" << endl;
		for(int j = i; j < size; j++){
			//cout << tablica[j][i - 1] << endl;
			//cout << tablica[j - 1][i - 1] << endl;
			tablica[j][i] = (tablica[j][i - 1] - tablica[j - 1][i - 1]) / i;
			cout << "i = " << i << "   j = " << j << "\t" << tablica[j][i] << endl;
		}
	}
}