#include <iostream>
using namespace std;

int n = 0;
int r = 0;
int tab[0][0];

int porownaj(int a, int x, int y){
    cout << r << "  " << a << "  " << x << "  " << y << endl;
    for(int i = a + 1; i < n; i++){
        if(tab[i][2] == r || tab[i][2] == r + 4){
            int w1 = porownaj(i, x, y);
            int w2 = porownaj(i, x + tab[i][0], y + tab[i][1]);
            if(w1 > w2){
                return w1;
            } else {
                return w2;
            }
        }
    }
    return x*x + y*y;
}

main(){
    cin>>n;
    int tab[n][3];
    int naj[8][3];
    for(int i = 0; i < 8; i++){
        naj[i][0] = 0;
        naj[i][1] = 0;
    }
    for(int k = 0; k < n; k++){
        cin >> tab[k][0];
        cin >> tab[k][1];
        if(tab[k][1] >= 0){
            if(tab[k][0] >= 0){
                if(tab[k][1] <= tab[k][0]){
                    tab[k][2] = 0;
                } else {
                    tab[k][2] = 1;
                }
            } else {
                if(tab[k][1] >= -tab[k][0]){
                    tab[k][2] = 2;
                } else {
                    tab[k][2] = 3;
                }
            }
        } else {
            if(tab[k][0] <= 0){
                if(-tab[k][1] <= -tab[k][0]){
                    tab[k][2] = 4;
                } else {
                    tab[k][2] = 5;
                }
            } else {
                if(-tab[k][1] >= tab[k][0]){
                    tab[k][2] = 6;
                } else {
                    tab[k][2] = 7;
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        r = tab[i][2];
        naj[r][0] += tab[i][0];
        naj[r][1] += tab[i][1];
        if(r > 0){
            naj[r - 1][0] += tab[i][0];
            naj[r - 1][1] += tab[i][1];
        } else {
            naj[7][0] += tab[i][0];
            naj[7][1] += tab[i][1];
        }
        if(r < 7){
            naj[r + 1][0] += tab[i][0];
            naj[r + 1][1] += tab[i][1];
        } else {
            naj[0][0] += tab[i][0];
            naj[0][1] += tab[i][1];
        }
    }
    int maks = 0;
    for(int i = 0; i < 8; i++){
        r = (i + 2) % 4;
        naj[i][2] = porownaj(-1, naj[i][0], naj[i][1]);
        if(naj[i][2] > maks){
            maks = naj[i][2];
        }
    }
    cout << maks << endl;
    //cout << tab[k][0] << endl;
    //cout << tab[k][1] << endl;
    //cout << tab[k][2] << endl;
    //cout << endl;
}
