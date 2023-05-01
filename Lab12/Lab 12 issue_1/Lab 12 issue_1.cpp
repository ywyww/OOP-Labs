#include <iostream>
#include <set>
using namespace std;

multiset<double> pushArithmeticMean(const multiset<double>& f_mset);
multiset<double> eraseRange(const multiset<double>& f_mset, const double lowerBound, const double upperBound);
bool isInRange(const double value, const double lowerBound, const double upperBound);
multiset<double> increaseOnMinMax(const multiset<double>& f_mset);

template <typename T>
void print(const multiset<T>& p_list);

int main() {

	cout << "task 1:" << endl;
	multiset<double> a = { 1, 2, 3 };
	multiset<double> b = pushArithmeticMean(a);
	print(a);
	print(b);

	cout << "task 2:" << endl;
	multiset<double> a1 = { 1, 2, 3, 4 };
	multiset<double> b1 = eraseRange(a1, 2, 3);
	print(a1);
	print(b1);

	cout << "task 3:" << endl;
	multiset<double> a2 = { 1, 2, 3, 4 };
	multiset<double> b2 = increaseOnMinMax(a2);
	print(a2);
	print(b2);

	return 0;
}

multiset<double> pushArithmeticMean(const multiset<double>& f_mset) {
	multiset<double> r_mset = f_mset;
	double sum = 0;
	for (auto it = f_mset.begin(); it != f_mset.end(); it++) {
		sum += *it;
	}

	double arithmeticMean = sum / f_mset.size();
	r_mset.insert(arithmeticMean);
	return r_mset;
}

multiset<double> eraseRange(const multiset<double>& f_mset, const double lowerBound, const double upperBound) {
	multiset<double> r_mset = f_mset;
	for (auto it = r_mset.begin(); it != r_mset.end(); it++) {
		if (isInRange(*it, lowerBound, upperBound)) {
			it = r_mset.erase(it);
			it--;
		}
	}
	return r_mset;
}
bool isInRange(const double value, const double lowerBound, const double upperBound) {
	return (value >= lowerBound && value <= upperBound);
}

multiset<double> increaseOnMinMax(const multiset<double>& f_mset) {
	multiset<double> temp_mset = f_mset;
	multiset<double> r_mset;

	double maxListValue = DBL_MIN;
	double minListValue = DBL_MAX;

	for (auto it = temp_mset.begin(); it != temp_mset.end(); it++) {
		if (*it > maxListValue) maxListValue = *it;
		if (*it < minListValue) minListValue = *it;
	}

	for (auto it = temp_mset.begin(); it != temp_mset.end(); it++) {
		double value = *it + maxListValue + minListValue;
		r_mset.insert(value);
	}

	return r_mset;
}

template <typename T>
void print(const multiset<T>& p_list) {
	for (auto it = p_list.begin(); it != p_list.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}