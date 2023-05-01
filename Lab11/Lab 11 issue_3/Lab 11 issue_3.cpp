#include <iostream>
#include "List.h"
using namespace std;

List<double> pushArithmeticMean(List<double>& f_list);
List<double> eraseRange(List<double>& f_list, const double lowerBound, const double upperBound);
bool isInRange(const double value, const double lowerBound, const double upperBound);
List<double> increaseOnMinMax(List<double>& f_list);

int main() {

	cout << "task 1:" << endl;
	List<double> a;
	a.push(1);
	a.push(2);
	a.push(3);
	List<double> b = pushArithmeticMean(a);
	cout << a << endl;
	cout << b << endl;
	
	cout << "task 2:" << endl;
	List<double> a1;
	a1.push(1);
	a1.push(2);
	a1.push(3);
	a1.push(4);

	List<double> b1 = eraseRange(a1, 2, 3);
	cout << a1 << endl;
	cout << b1 << endl;

	cout << "task 3:" << endl;
	List<double> a2;
	a2.push(1);
	a2.push(2);
	a2.push(3);
	a2.push(4);
	List<double> b2 = increaseOnMinMax(a2);
	cout << a2 << endl;
	cout << b2;
	
	return 0;
}

List<double> pushArithmeticMean(List<double>& f_list) {
	List<double> r_list = f_list;
	double sum = 0;
	for (Node<double>* nodePtr = f_list.getHead(); nodePtr != nullptr; nodePtr = nodePtr->getPtr()) {
		sum += nodePtr->getData();
	}

	double arithmeticMean = sum / f_list();
	r_list.push(arithmeticMean);
	return r_list;
}

List<double> eraseRange(List<double>& f_list, const double lowerBound, const double upperBound) {
	List<double> r_list = f_list;
	int i = 1;
	for (Node<double>* nodePtr = f_list.getHead(); nodePtr != nullptr; nodePtr = nodePtr->getPtr()) {
		if (isInRange(nodePtr->getData(), lowerBound, upperBound)) {
			r_list.erase(i);
		}
		else {
			i++;
		}
	}
	return r_list;
}
bool isInRange(const double value, const double lowerBound, const double upperBound) {
	return (value >= lowerBound && value <= upperBound);
}

List<double> increaseOnMinMax(List<double>& f_list) {
	List<double> r_list = f_list;
	double maxListValue = DBL_MIN;
	double minListValue = DBL_MAX;

	for (Node<double>* nodePtr = r_list.getHead(); nodePtr != nullptr; nodePtr = nodePtr->getPtr()) {
		if (nodePtr->getData() > maxListValue) maxListValue = nodePtr->getData();
		if (nodePtr->getData() < minListValue) minListValue = nodePtr->getData();
	}

	for (Node<double>* nodePtr = r_list.getHead(); nodePtr != nullptr; nodePtr = nodePtr->getPtr()) {
		double value = nodePtr->getData() + maxListValue + minListValue;
		nodePtr->setData(value);
	}

	return r_list;
}