#include <iostream>
using namespace std;

int main(){
	int ilosc;
	cin >> ilosc;
	int pokoje[ilosc];
	for(int i = 0; i < ilosc; i++){
		cin >> pokoje[i];
		pokoje[i]--;
	}
	for(int i = 0; i < ilosc; i++){
		int index = 1;
		int kolejne = pokoje[i];
		while(kolejne != i){
			kolejne = pokoje[kolejne];
			index++;
			if(index > ilosc + 10){
				break;
			}
		}
		if(kolejne == i){
			cout << index << endl;
		} else {
			cout << "inf" << endl;
		}
	}
}