#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

main(){
    cout << "Elo elo!" << endl;
    int n;
    srand(time(NULL));
    int tablica[10];
    for(int i = 0; i < 10; i++){
        n = rand()%100;
        if(n > 50){
            cout << "pyklo" << endl;
        } else {
            cout << "nie pyklo" << endl;
        }
        tablica[i] = n;
    }
    n = 0;
    for(int i = 0; i < 10; i++){
        n += tablica[i];
    }
    cout << "suma:" << n;
}
