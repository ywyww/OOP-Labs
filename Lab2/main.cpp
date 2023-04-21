#include <iostream>
#include <Windows.h>
#include <string>
#include "Salary.h"
using namespace std;

Salary makeStaff();
void print(Salary);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Salary s1;		// ����������� ��� ����������
	s1.show();

	Salary s2("�������� ���� ����������", 200000, 34);	// ����������� � �����������
	s2.show();

	Salary s3 = s2;			// ����������� �����������
	print(s3);				// ����������� ����������� 
							// ����� ����������� (��� ��� � ���-��� ������� �� ������)
	Salary s4 = makeStaff();
	s4.show();
	
	// ���������� ���������� ��� ������� �������

	return 0;
}

Salary makeStaff() {
	string name; double r; int i;
	cout << "������� ���?" << endl;
	getline(cin, name);
	cout << "��������?" << endl;
	cin >> r;
	cout << "������ (%)?" << endl;
	cin >> i;

	Salary t(name, r, i);			// ����������� � �����������
	return t;						// ����������� �����������, ����� ����������, ��� ��� ������������� ����� �����
}

void print(Salary t) {
	t.show();
}