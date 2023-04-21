#include <iostream>
#include <string>
#include "Salary.h"
using namespace std;

Salary::Salary() {
	cout << "����� ������������ ��� ����������" << endl;
	name = "";
	reward = 0;
	prcnt = 0;
}

Salary::Salary(string s, double d, int i) {
	cout << "����� ������������ � �����������" << endl;
	name = s; reward = d; prcnt = i;
}

Salary::Salary(const Salary& t) {
	cout << "����� ������������ �����������" << endl;
	name = t.name;
	reward = t.reward;
	prcnt = t.prcnt;
}

Salary::~Salary() {
	cout << "����� �����������" << endl;
	cout << name << endl;
}

void Salary::setName(string name) { 
	this->name = name; 
}

void Salary::setReward(double reward) {
	this->reward = reward;
}

void Salary::setPrcnt(int prcnt) {
	prcnt = prcnt;
}

string Salary::getName() {
	return name;
}

double Salary::getReward() {
	return reward;
}

int Salary::getPrcnt() {
	return prcnt;
}

void Salary::show() {
	cout << "Name: " << name << endl;
	cout << "Reward: " << reward << endl;
	cout << "Percent: " << prcnt << endl;
}