#include <iostream>
using namespace std;

const int n = 5;
const int silniam1 = 119;
int zmiany[silniam1];
int liczby[n];
int lacznie = 0;
int tablica[n];

int ilosc(int x){
	// tablica to poprzedni stan rzeczy, a liczby to obecny.
	/*for(int i = 0; i < x; i++){
		cout << "=";
	}
	cout << "  ";
	for(int i = 0; i < n; i++){
		cout << liczby[i] << "  ";
	}
	cout << endl;*/
	bool p;
	int index;
	int k;
	for(int j = 0; j < n - 1; j++){
		if(x == 0 || zmiany[x - 1] != j){
			k = liczby[j + 1];
			liczby[j + 1] = liczby[j];
			liczby[j] = k;
			for(int i = 0; i < n; i++){
				tablica[i] = i;
			}
			p = false;
			index = -1;
			for(int i = -1; i == -1 || (i < x && x != silniam1); i++){
				if(i > -1){
					k = tablica[zmiany[i] + 1];
					tablica[zmiany[i] + 1] = tablica[zmiany[i]];
					tablica[zmiany[i]] = k;
				}
				if(zmiany[i] == index + 1){
					for(int h = zmiany[i]; h < n; h++){
						if(liczby[h] == tablica[h]){
							index++;
						} else {
							break;
						}
					}
					if(index == n - 1){
						p = true;
						break;
					}
				} else if(zmiany[i] <= index){
					index = zmiany[i] - 1;
				}
			}
			if(!p){
				if(x != silniam1){
					zmiany[x] = j;
					ilosc(x + 1);
				}
			} else if(x == silniam1){
				lacznie++;
			}
			k = liczby[j + 1];
			liczby[j + 1] = liczby[j];
			liczby[j] = k;
		}
	}
}

/*
int ilosc(int x){
	// tablica to poprzedni stan rzeczy, a liczby to obecny.
	int tablica[n];
	bool czy[n - 1];
	for(int i = 0; i < n - 1; i++){
		tablica[i] = i;
		czy[i] = true;
	}
	tablica[n - 1] = n - 1;
	bool p;
	for(int i = -1; i == -1 || i < zmiany.size(); i++){
		if(i > -1 && x != silniam1){
			tablica[zmiany[i]].swap(tablica[zmiany[i] + 1]);
		}
		for(int g = 0; g < n - 1; g++){
			if(czy[g]){
				int k = liczby[g];
				liczby[g] = liczby[g + 1];
				liczby[g + 1] = k;
				p = false;
				for(int h = 0; h < n; h++){
					if(liczby[h] != tablica[h]){
						p = true;
						break;
					}
				}
				czy[g] = p;
				k = liczby[g];
				liczby[g] = liczby[g + 1];
				liczby[g + 1] = k;
			}
		}
	}
	for(int j = 0; j < n - 1; j++){
		if(czy[j]){
			if(x == silniam1){
				lacznie++;
			} else {
				zmiany[x] = j;
				int k = liczby[j];
				liczby[j] = liczby[j + 1];
				liczby[j + 1] = k;
				ilosc(x + 1);
				k = liczby[j];
				liczby[j] = liczby[j + 1];
				liczby[j + 1] = k;
				zmiany[x] = -1;
			}
		}
	}
}
*/

main(){
	for(int i = 0; i < n; i++){
		liczby[i] = i;
	}
	cout << "jest ok" << endl;
	ilosc(0);
	cout << lacznie << endl;
}