#include <iostream>
#include "Magazin.h"
#include "Print.h"
#include "Dialog.h"
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	cout << "m + ����� - ������� ������" << endl;
	cout << "+ �������� ������� � ������" << endl;
	cout << "- ������� ������� �� ������" << endl;
	cout << "s ������� ���������� �� ��������� ������" << endl;
	cout << "z ������� ���������� �� ��������� ������" << endl;
	cout << "q �����" << endl;



	Dialog D;
	D.execute();

	return 0;
}