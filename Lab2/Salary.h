#pragma once
#include <string>
using namespace std;

class Salary {
	string name;
	double reward;
	int prcnt;

public:
	Salary();
	Salary(string, double, int);
	Salary(const Salary&);
	~Salary();
	
	// ������������
	void setName(string);
	void setReward(double);
	void setPrcnt(int);

	// ���������
	string getName();
	double getReward();
	int getPrcnt();
	
	void show();
};