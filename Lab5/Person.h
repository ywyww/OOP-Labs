#pragma once
#include <iostream>
#include <string>
using namespace std;

class Object {
public:
	virtual void show() = 0;
};

class Person : public Object {
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	virtual ~Person();		//объ€вление виртуальным дл€ гарантии выполнени€ деструктора производного класса

	void setName(string);
	string getName();
	void setAge(int);
	int getAge();

	Person& operator=(const Person&);
	friend istream& operator>>(istream&, Person&);
	friend ostream& operator<<(ostream&, const Person&);
	
	void show() override;
};
