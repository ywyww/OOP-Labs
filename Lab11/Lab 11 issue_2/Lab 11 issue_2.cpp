#include <iostream>
#include "Pair.h"
#include <list>
using namespace std;

void pushPair(list<Pair>& f_list);
list<Pair> pushArithmeticMean(const list<Pair>& f_list);

list<Pair> eraseRange(const list<Pair>& f_list, const double lowerBound, const double upperBound);
bool isInRange(const double value, const double lowerBound, const double upperBound);

list<Pair> increaseOnMinMax(const list<Pair>& f_list);

template <typename T>
void print(const list<T>& p_list);

int main() {

	cout << "task 1:" << endl;
	list<Pair> a;
	pushPair(a);
	list<Pair> b = pushArithmeticMean(a);
	print(a);
	print(b);
	
	cout << "task 2:" << endl;
	list<Pair> a1;
	pushPair(a1);
	list<Pair> b1 = eraseRange(a1, 2, 8);
	print(a1);
	print(b1);

	cout << "task 3:" << endl;
	list<Pair> a2;
	pushPair(a2);
	list<Pair> b2 = increaseOnMinMax(a2);
	print(a2);
	print(b2);

	return 0;
}

void pushPair(list<Pair>& f_list) {
	f_list.push_back(Pair(1, 5.5));
	f_list.push_back(Pair(2, 7.8));
	f_list.push_back(Pair(3, 4.3));
}


list<Pair> pushArithmeticMean(const list<Pair>& f_list) {
	list<Pair> r_list = f_list;
	int sumForInt = 0;
	double sumForDouble = 0;
	Pair tmp;

	for (auto it = f_list.begin(); it != f_list.end(); it++) {
		tmp = *it;
		sumForInt += tmp.getFirst();
		sumForDouble += tmp.getSecond();
	}

	int arithmeticMeanForInt = sumForInt / static_cast<int>(f_list.size());
	double arithmeticMeanForDouble = sumForDouble / f_list.size();
	r_list.push_back(Pair(arithmeticMeanForInt, arithmeticMeanForDouble));
	return r_list;
}

list<Pair> eraseRange(const list<Pair>& f_list, const double lowerBound, const double upperBound) {
	list<Pair> r_list = f_list;
	Pair tempPair;
	for (auto it = r_list.begin(); it != r_list.end();) {
		tempPair = *it;
		double sumFS = tempPair.getFirst() + tempPair.getSecond();
		if (isInRange(sumFS, lowerBound, upperBound)) {
			it = r_list.erase(it);
		}
		else it++;
	}
	return r_list;
}
bool isInRange(const double value, const double lowerBound, const double upperBound) {
	return (value >= lowerBound && value <= upperBound);
}

list<Pair> increaseOnMinMax(const list<Pair>& f_list) {
	list<Pair> r_list = f_list;
	Pair tempPair;

	int maxListValueInt = INT_MIN;
	int minListValueInt = INT_MAX;
	double maxListValueDouble = DBL_MIN;
	double minListValueDouble = DBL_MAX;

	for (auto it = r_list.begin(); it != r_list.end(); it++) {
		tempPair = *it;
		if (tempPair.getFirst() < minListValueInt) minListValueInt = tempPair.getFirst();
		if (tempPair.getFirst() > maxListValueInt) maxListValueInt = tempPair.getFirst();
		if (tempPair.getSecond() < minListValueDouble) minListValueDouble = tempPair.getSecond();
		if (tempPair.getSecond() > maxListValueDouble) maxListValueDouble = tempPair.getSecond();
	}

	for (auto it = r_list.begin(); it != r_list.end(); it++) {
		tempPair = *it;
		*it = tempPair + minListValueInt + maxListValueInt + minListValueDouble + maxListValueDouble;
	}

	return r_list;
}

template <typename T>
void print(const list<T>& p_list) {
	for (auto it = p_list.begin(); it != p_list.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
