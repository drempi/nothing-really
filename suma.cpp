#include <iostream>
using namespace std;

main(){
	long long kombi[20];
	for(int n = 3; n < 20; n++){
		long long wart = 1;
		for(int i = 3; i < n; i++){
			wart += kombi[i] * kombi[n - i + 2];
		}
		for(int k = 2; k <= n - 2; k++){
			wart += kombi[n - k + 1];
			for(int i = k + 2; i < n; i++){
				wart += 2 * kombi[i - k + 1] * kombi[n - i + 2];
			}
		}
		kombi[n] = wart;
		cout << n << ".   " << wart << endl;
	}
}