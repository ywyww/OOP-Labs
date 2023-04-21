#include "Person.h"
#include "Student.h"
#include "Vector.h"

int main() {
	
	Student a1;
	cin >> a1;

	Person a2;
	cin >> a2;

	Vector v1(2);
	v1.add(&a1);
	v1.add(&a2);

	cout << v1;

	return 0;
}