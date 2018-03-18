#include <iostream>
using namespace std;

const int size = 10;
bool czy[size + 1];
int wynik = 0;

bool pierwsze(int a, int b){
	while(a > 0 && b > 0){
		if(a > b){
			a = a % b;
		} else {
			b = b % a;
		}
	}
	if(a <= 1 && b <= 1){
		return true;
	} else {
		return false;
	}
}

void krok(int w, int x){
	for(int i = 2; i < size + 1; i++){
		if(!czy[i] && pierwsze(i, w)){
			if(x == size - 2){
				wynik++;
			} else {
				czy[i] = true;
				krok(i, x + 1);
				czy[i] = false;
			}
		}
	}
}

int main(){
	for(int i = 0; i < size; i++){
		czy[i] = false;
	}
	krok(1, 0);
	cout << size*wynik << endl;
}