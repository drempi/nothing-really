#include <bits/stdc++.h>
using namespace std;

int main(){
	int ilosc;
	cin >> ilosc;
	int pokoje[ilosc];
	for(int i = 0; i < ilosc; i++){
		cin >> pokoje[i];
		pokoje[i]--;
	}
	int wyniki[ilosc];
	int grafy[ilosc];
	int numer = 1;
	for(int i = 0; i < ilosc; i++){
		grafy[i] = 0;
	}
	assert(0);
	for(int i = 0; i < ilosc; i++){
		int kolejny = i;
		while(grafy[kolejny] == 0){
			grafy[kolejny] = numer;
			kolejny = pokoje[kolejny];
		}
		if(grafy[kolejny] != numer){
			int x = grafy[kolejny];
			kolejny = pokoje[i];
			while(grafy[kolejny] == numer){
				grafy[kolejny] = x;
				kolejny = pokoje[kolejny];
			}
		} else {
			numer++;
		}
	}
	bool czygrafy[numer];
	for(int i = 0; i < numer; i++){
		czygrafy[i] = false;
	}
	int droga[ilosc];
	for(int i = 0; i < ilosc; i++){
		wyniki[i] = 0;
		droga[i] = 0;
	}
	cout << "egfegfytet" << ilosc << endl;
	for(int i = 0; i < ilosc; i++){
		cout << "---   " << grafy[i] << endl;
	}
	for(int i = 0; i < ilosc; i++){
		if(!czygrafy[grafy[i]]){
			czygrafy[grafy[i]] = true;
			int dl = 1;
			int kolejne = i;
			while(droga[kolejne] == 0){
				droga[kolejne] = dl;
				dl++;
				kolejne = pokoje[kolejne];
			}
			int wartosc = dl - droga[kolejne];
			while(wyniki[kolejne] == 0){
				wyniki[kolejne] = wartosc;
				kolejne = pokoje[kolejne];
			}
		}
	}
	for(int i = 0; i < ilosc; i++){
		if(wyniki[i] == 0){
			cout << "inf" << endl;
		} else {
			cout << wyniki[i] << endl;
		}
	}
}