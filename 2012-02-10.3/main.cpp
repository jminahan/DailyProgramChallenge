#include <stdlib.h>
#include <iostream>
#include <string>
using namespace std;  

int main() {
	int lower_bound = 0;
	int upper_bound = 100;
	int found = 0;
	srand(time(NULL));
	while(!found) {
		string response;
		int randomInt = rand()%(upper_bound-lower_bound + 1) + lower_bound;
		cout << "Is it " + to_string(randomInt) + '?';
		cin >> response;
		if(response.compare("no")==0) {
			string high_or_low;
			cout << "Is your number higher or lower?";
			cin >> high_or_low;
			if(high_or_low.compare("lower")==0) {
				upper_bound = randomInt;
				if(lower_bound > upper_bound) {
					lower_bound = upper_bound;
				}
			} else {
				lower_bound = randomInt;
				if(upper_bound < lower_bound) {
					upper_bound = lower_bound;
				}
			}
		} else {
			return 0;
		}
	}
}