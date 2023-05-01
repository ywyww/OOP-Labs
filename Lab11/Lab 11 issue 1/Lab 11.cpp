#include <iostream>
#include <list>
using namespace std;

list<double> pushArithmeticMean(const list<double>& f_list);
list<double> eraseRange(const list<double>& f_list, const double lowerBound, const double upperBound);
bool isInRange(const double value, const double lowerBound, const double upperBound);
list<double> increaseOnMinMax(const list<double>& f_list);

template <typename T>
void print(const list<T>& p_list);

int main() {
	
	cout << "task 1:" << endl;
	list<double> a = { 1, 2, 3 };
	list<double> b = pushArithmeticMean(a);
	print(a);
	print(b);

	cout << "task 2:" << endl;
	list<double> a1 = { 1, 2, 3, 4 };
	list<double> b1 = eraseRange(a1, 2, 3);
	print(a1);
	print(b1);

	cout << "task 3:" << endl;
	list<double> a2 = { 1, 2, 3, 4 };
	list<double> b2 = increaseOnMinMax(a2);
	print(a2);
	print(b2);
	
	return 0;
}

list<double> pushArithmeticMean(const list<double>& f_list) {
	list<double> r_list = f_list;
	double sum = 0;
	for (auto it = f_list.begin(); it != f_list.end(); it++) {
		sum += *it;
	}

	double arithmeticMean = sum / f_list.size();
	r_list.push_back(arithmeticMean);
	return r_list;	
}

list<double> eraseRange(const list<double>& f_list, const double lowerBound, const double upperBound) {
	list<double> r_list = f_list;
	for (auto it = r_list.begin(); it != r_list.end(); it++) {
		if (isInRange(*it, lowerBound, upperBound)) {
			it = r_list.erase(it);
			it--;
		}
	}
	return r_list;
}
bool isInRange(const double value, const double lowerBound, const double upperBound) {
	return (value >= lowerBound && value <= upperBound);
}

list<double> increaseOnMinMax(const list<double>& f_list) {
	list<double> r_list = f_list;
	double maxListValue = DBL_MIN;
	double minListValue = DBL_MAX;

	for (auto it = r_list.begin(); it != r_list.end(); it++) {
		if (*it > maxListValue) maxListValue = *it;
		if (*it < minListValue) minListValue = *it;
	}

	for (auto it = r_list.begin(); it != r_list.end(); it++) {
		*it += maxListValue + minListValue;
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