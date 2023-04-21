#include <iostream>
#include "Pair.h"
using namespace std;

int main() {
	Pair a1(2, 5.6);
	a1.show();
	
	a1 + 5.5;
	
	a1.show();
	Pair a2;
	cin >> a2;
	a2 - a1;
	cout << a2;

	return 0;
}