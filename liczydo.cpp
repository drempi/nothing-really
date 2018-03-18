#include <iostream>
#include <time.h>
#include <cstdlib>
#include <cmath>

using namespace std;

const int zasieg = 2147483645;

bool test(double x, double y, double z, double s){
	// czy LHS >= RHS
	//double RHS = sqrt(x*x + y*y + z*z + s*(x*y + y*z + z*x));
	//double RHS = x*x + y*y + z*z + sqrt((x*y + y*z + z*x)/2);
	//double LHS = sqrt(x*x + y*z) + sqrt(y*y + x*z) + sqrt(z*z + x*y);
	double RHS = 3*(x*y+y*z+z*x)/2 + (x + y + z)*sqrt((x*y + y*z + z*x)/2);
	double LHS = sqrt(x*y*(z+x)*(z+y)) + sqrt(x*z*(y + x)*(y+z)) + sqrt(y*z*(x+y)*(x+z));
	if(LHS >= RHS){
		return true;
	}
	return false;
}

bool przetestuj(double s){
	if(!test(1, 1, 1, s)){
		return false;
	} else if(!test(1, 1, 0, s)){
		return false;
	} else if(!test(1, 0, 0, s)){
		return false;
	} else if(!test(1, 1, 0.000000001, s)){
		return false;
	} else if(!test(1, 0.000000001, 0.000000001, s)){
		return false;
	} else if(!test(1, 0.000000001, 0, s)){
		return false;
	}
	cout << "tu jeszcze dziala" << endl;
	double x, y, z;
	for(int i = 0; i < 1000000; i++){
		x = (double) (rand()) / zasieg;
		y = (double) (rand()) / zasieg;
		z = (double) (rand()) / zasieg;
		if(!test(x, y, z, s)){
			return false;
		}
	}
	return true;
}

main(){
	bool pojedynczy = true;
	if(pojedynczy){
		cout << przetestuj(5) << endl;
	} else {
		srand(time(0));
		double min = 0;
		double max = 100;
		while(abs(max - min) > 0.000000001){
			double mid = (max + min)/2;
			if(przetestuj(mid)){
				min = mid;
			} else {
				max = mid; 
			}
		}
		cout << min << endl;
	}
}