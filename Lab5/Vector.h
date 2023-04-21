#include "Person.h"
#include "Student.h"
#pragma once
class Vector
{
	int size;
	int curr;
	Object** beg;
public:
	Vector();
	Vector(int);
	~Vector();
	void add(Object*);
	friend ostream& operator<<(ostream& out, const Vector& vect);
};

