#include <set>
#include <iostream>
#include "Pair.h"
using namespace std;

void pushPair(multiset<Pair>& f_mset);
multiset<Pair> pushArithmeticMean(const multiset<Pair>& f_mset);

multiset<Pair> eraseRange(const multiset<Pair>& f_mset, const double lowerBound, const double upperBound);
bool isInRange(const double value, const double lowerBound, const double upperBound);

multiset<Pair> increaseOnMinMax(const multiset<Pair>& f_mset);

template <typename T>
void print(const multiset<T>& p_mset);

int main() {

	cout << "task 1:" << endl;
	multiset<Pair> a;
	pushPair(a);
	multiset<Pair> b = pushArithmeticMean(a);
	print(a);
	print(b);

	
	cout << "task 2:" << endl;
	multiset<Pair> a1;
	pushPair(a1);
	multiset<Pair> b1 = eraseRange(a1, 2, 8);
	print(a1);
	print(b1);

	cout << "task 3:" << endl;
	multiset<Pair> a2;
	pushPair(a2);
	multiset<Pair> b2 = increaseOnMinMax(a2);
	print(a2);
	print(b2);
	
	return 0;
}

void pushPair(multiset<Pair>& f_mset) {
	f_mset.insert(Pair(1, 5.5));
	f_mset.insert(Pair(2, 7.8));
	f_mset.insert(Pair(3, 4.3));
}


multiset<Pair> pushArithmeticMean(const multiset<Pair>& f_mset) {
	multiset<Pair> r_mset = f_mset;
	int sumForInt = 0;
	double sumForDouble = 0;
	Pair tmp;

	for (auto it = f_mset.begin(); it != f_mset.end(); it++) {
		tmp = *it;
		sumForInt += tmp.getFirst();
		sumForDouble += tmp.getSecond();
	}

	int arithmeticMeanForInt = sumForInt / static_cast<int>(f_mset.size());
	double arithmeticMeanForDouble = sumForDouble / f_mset.size();
	r_mset.insert(Pair(arithmeticMeanForInt, arithmeticMeanForDouble));
	return r_mset;
}

multiset<Pair> eraseRange(const multiset<Pair>& f_mset, const double lowerBound, const double upperBound) {
	multiset<Pair> r_mset = f_mset;
	Pair tempPair;
	for (auto it = r_mset.begin(); it != r_mset.end();) {
		tempPair = *it;
		double sumFS = tempPair.getFirst() + tempPair.getSecond();
		if (isInRange(sumFS, lowerBound, upperBound)) {
			it = r_mset.erase(it);
		}
		else it++;
	}
	return r_mset;
}
bool isInRange(const double value, const double lowerBound, const double upperBound) {
	return (value >= lowerBound && value <= upperBound);
}

multiset<Pair> increaseOnMinMax(const multiset<Pair>& f_mset) {
	multiset<Pair> r_mset = f_mset;
	multiset<Pair> temp_mset;

	Pair tempPair;

	int maxListValueInt = INT_MIN;
	int minListValueInt = INT_MAX;
	double maxListValueDouble = DBL_MIN;
	double minListValueDouble = DBL_MAX;

	for (auto it = r_mset.begin(); it != r_mset.end(); it++) {
		tempPair = *it;
		if (tempPair.getFirst() < minListValueInt) minListValueInt = tempPair.getFirst();
		if (tempPair.getFirst() > maxListValueInt) maxListValueInt = tempPair.getFirst();
		if (tempPair.getSecond() < minListValueDouble) minListValueDouble = tempPair.getSecond();
		if (tempPair.getSecond() > maxListValueDouble) maxListValueDouble = tempPair.getSecond();
	}

	for (auto it = r_mset.begin(); it != r_mset.end(); it++) {
		tempPair = *it;
		tempPair = tempPair + minListValueInt + maxListValueInt + minListValueDouble + maxListValueDouble;
		temp_mset.insert(tempPair);
	}

	return temp_mset;
}

template <typename T>
void print(const multiset<T>& p_mset) {
	for (auto it = p_mset.begin(); it != p_mset.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
