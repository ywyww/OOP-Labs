#pragma once
#include <iostream>
#include <string>
using namespace std;

class Person{
protected:
	string name;
	int age;
public:
	Person();
	Person(string, int);
	Person(const Person&);
	virtual ~Person();		//���������� ����������� ��� �������� ���������� ����������� ������������ ������
	
	void setName(string);
	string getName();
	void setAge(int);
	int getAge();
	
	Person& operator=(const Person&);
	friend istream& operator>>(istream&, Person&);
	friend ostream& operator<<(ostream&, const Person&);
};
