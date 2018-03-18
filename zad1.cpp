#include <iostream>
using namespace std;

int X, Y, R, Z;
bool wybory[20][20];
int const P = 1048580;
int rzad1[P][200];
int rzad2[P][200];
int index = 0;
int ilosc = 0;
bool mapa[20];
int potegi[20]; 

int k;
int dwadox = 0;
int maxxd = 0;
int liczba = 0;

void wygeneruj(int obecne){
	if(obecne <= X - 2){
		// 1
		mapa[obecne] = true;
		mapa[obecne + 1] = true;
		if(wybory[0][obecne] && wybory[0][obecne + 1]){
			ilosc++;
		}
		index += potegi[obecne];
		index += potegi[obecne + 1];
		obecne += 2;
		wygeneruj(obecne);
		obecne -= 2;
		index -= potegi[obecne];
		index -= potegi[obecne + 1];
		mapa[obecne] = false;
		mapa[obecne + 1] = false;
		if(wybory[0][obecne] && wybory[0][obecne + 1]){
			ilosc--;
		}
		// 2
		obecne++;
		wygeneruj(obecne);
		obecne--;
	} else {
		rzad1[index][ilosc] = 1;
	}
}

void nowe(int obecne){
	if(obecne <= X - 2){
		// 1
		if(!mapa[obecne] && !mapa[obecne + 1]){
			mapa[obecne] = true;
			mapa[obecne + 1] = true;
			if(wybory[k][obecne] && wybory[k][obecne + 1]){
				ilosc++;
			}
			index += potegi[obecne];
			index += potegi[obecne + 1];
			obecne += 2;
			nowe(obecne);
			obecne -= 2;
			index -= potegi[obecne];
			index -= potegi[obecne + 1];
			mapa[obecne] = false;
			mapa[obecne + 1] = false;
			if(wybory[k][obecne] && wybory[k][obecne + 1]){
				ilosc--;
			}
		}
		// 2
		obecne++;
		nowe(obecne);
		obecne--;
	} else {
		for(int i = ilosc; i < maxxd; i++){
			if(rzad1[liczba][i - ilosc] != 0){
				rzad2[index][i] = (rzad2[index][i] + rzad1[liczba][i - ilosc]) % R;
			}
		}
	}
}

int main(){
	for(int i = 0; i < 20; i++){
		potegi[i] = 1 << i;
	}
	int maks;
	cin >> maks;
	for(int v = 0; v < maks; v++){
		//cout << "========================================================" << endl;
		//cout << "========================================================" << endl;
		cin >> X >> Y >> Z >> R;
		// M - koordynat x
		// N - koordynat y
		// Z - ilosc zwyciestw
		// R - reszta z dzielenia
		string s;
		for(int y = 0; y < Y; y++){
			cin >> s;
			for(int j = 0; j < X; j++){
				if(s[j] == 'A'){
					wybory[y][j] = true;
				} else {
					wybory[y][j] = false;
				}
			}
		}
		int min = 0;
		maxxd = 0;
		for(int i = 0; i < Y; i++){
			for(int j = 0; j < X; j++){
				if(wybory[i][j]){
					bool czy = true;
					maxxd++;
					if(i > 0){
						if(!wybory[i - 1][j]){
							czy = false;
						}
					}
					if(i < Y){
						if(!wybory[i + 1][j]){
							czy = false;
						}
					}
					if(j > 0){
						if(!wybory[i][j - 1]){
							czy = false;
						}
					}
					if(j < X){
						if(!wybory[i][j + 1]){
							czy = false;
						}
					}
					if(czy){
						min++;
					}
				}
			}
		}
		maxxd /= 2;
		maxxd++;
		if(R == 1 || (X % 2 == 1 && Y % 2 == 1) || Z < (min + 1) / 2 || Z > maxxd){
			cout << 0 << endl;
		} else {
			//cout << "dziala!!" << endl;
			dwadox = 1 << X;
			for(int i = 0; i < P; i++){
				for(int j = 0; j < 200; j++){
					rzad1[i][j] = 0;
					rzad2[i][j] = 0;
				}
			}
			for(int i = 0; i < 20; i++){
				mapa[i] = false;
			}
			ilosc = 0;
			wygeneruj(0);
			//for(int i = 0; i < dwadox; i++){
			//	for(int j = 0; j < 200; j++){
			//		if(rzad1[i][j] != 0){
			//			cout << "i = " << i << "   j = " << j << "    w = " << rzad1[i][j] << endl; 
			//		}
			//	}
			//}
			//cout << "---------------------------" << endl;
			// chyba tyle
			for(k = 1; k < Y; k++){
				for(int i = 0; i < dwadox; i++){
					liczba = i;
					index = i^(dwadox - 1);
					ilosc = 0;
					for(int j = 0; j < X; j++){
						mapa[j] = false;
					}
					for(int z = 0; z < X; z++){
						if((index & (1 << z)) > 0){
							if(wybory[k][z] && wybory[k - 1][z]){
								ilosc++;
							}
							mapa[z] = true;
						} else {
							mapa[z] = false;
						}
					}
					nowe(0);
				}
				//for(int i = 0; i < dwadox; i++){
				//	for(int j = 0; j < 200; j++){
				//		if(rzad2[i][j] != 0){
				//			cout << "i = " << i << "   j = " << j << "    w = " << rzad2[i][j] << endl; 
				//		}
				//	}
				//}
				//cout << "--------------------------------------" << endl;
				for(int g = 0; g < P; g++){
					for(int h = 0; h < maxxd; h++){
						rzad1[g][h] = rzad2[g][h];
					}
				}
				for(int i = 0; i < P; i++){
					for(int j = 0; j < maxxd; j++){
						rzad2[i][j] = 0;
					}
				}
			}
			cout << rzad1[dwadox - 1][Z] << endl;
		}
	}
}