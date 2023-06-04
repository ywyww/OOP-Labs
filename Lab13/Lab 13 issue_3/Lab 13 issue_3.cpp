#include "Pair.h"
#include <iostream>
#include <list>
#include <queue>
#include <numeric>
#include <algorithm>
#include <map>
using namespace std;


int main()
{
	setlocale(0, "");
	map <int, int> myMap = { {1, 2}, {2, 4}, {3, 6} };
	cout << "task 1:\n";
	int sum = 0;
	for (auto& p : myMap) {
		sum += p.second;
	}
	int avg = sum / myMap.size();
	myMap[0] = avg;
	for (auto& p : myMap) {
		cout << p.first << ": " << p.second << endl;
	}

	cout << "task 2:\n";
	myMap.erase(2); // удалить элемент с ключом 2


	cout << "task 3:\n";
	auto maxIt = std::max_element(myMap.begin(), myMap.end(),
		[](const auto& p1, const auto& p2) { return p1.second < p2.second; });
	auto minIt = std::min_element(myMap.begin(), myMap.end(),
		[](const auto& p1, const auto& p2) { return p1.second < p2.second; });
	int maxVal = maxIt->second;
	int minVal = minIt->second;

	// добавить максимальное и минимальное значение ко всем элементам
	for (auto& p : myMap) {
		p.second += maxVal + minVal;
		cout << p.first << " : " << p.second << endl;
	}
}
