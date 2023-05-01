#include <iostream>
#include <queue>
using namespace std;

priority_queue<double> pushArithmeticMean(const priority_queue<double>& f_queue);
priority_queue<double> eraseRange(const priority_queue<double>& f_queue, const double lowerBound, const double upperBound);
bool isInRange(const double value, const double lowerBound, const double upperBound);
priority_queue<double> increaseOnMinMax(const priority_queue<double>& f_queue);

template <typename T>
void print(const priority_queue<T>& p_queue);

int main() {

	std::cout << "task 1:" << endl;
	priority_queue<double> a;
	a.push(1);
	a.push(2);
	a.push(3);
	priority_queue<double> b = pushArithmeticMean(a);
	print(a);
	print(b);
	
	cout << "task 2:" << endl;
	priority_queue<double> a1;
	a1.push(1);
	a1.push(2);
	a1.push(3);
	a1.push(4);
	priority_queue<double> b1 = eraseRange(a1, 2, 3);
	print(a1);
	print(b1);
	
	cout << "task 3:" << endl;
	priority_queue<double> a2;
	a2.push(1);
	a2.push(2);
	a2.push(3);
	a2.push(4);
	priority_queue<double> b2 = increaseOnMinMax(a2);
	print(a2);
	print(b2);
	return 0;
}

priority_queue<double> pushArithmeticMean(const priority_queue<double>& f_queue) {
	priority_queue<double> temp_queue = f_queue;
	priority_queue<double> r_queue = f_queue;
	
	double sum = 0;
	while (temp_queue.size() != 0) {
		double top = temp_queue.top();
		temp_queue.pop();
		sum += top;
	}

	double arithmeticMean = sum / f_queue.size();
	r_queue.push(arithmeticMean);
	return r_queue;
}

priority_queue<double> eraseRange(const priority_queue<double>& f_queue, const double lowerBound, const double upperBound) {
	priority_queue<double> temp_queue = f_queue;
	priority_queue<double> r_queue;
	while (temp_queue.size() != 0) {
		double top = temp_queue.top();
		if (!isInRange(top, lowerBound, upperBound)) {
			r_queue.push(top);
		}
		temp_queue.pop();
	}
	return r_queue;
}
bool isInRange(const double value, const double lowerBound, const double upperBound) {
	return (value >= lowerBound && value <= upperBound);
}

priority_queue<double> increaseOnMinMax(const priority_queue<double>& f_queue) {
	priority_queue<double> temp_queue = f_queue;
	priority_queue<double> r_queue;
	double maxListValue = DBL_MIN;
	double minListValue = DBL_MAX;

	while (temp_queue.size() != 0) {
		double top = temp_queue.top();
		if (top > maxListValue) maxListValue = top;
		if (top < minListValue) minListValue = top;
		temp_queue.pop();
	}
	temp_queue = f_queue;
	while (temp_queue.size() != 0) {
		double top = temp_queue.top();
		double value = top + minListValue + maxListValue;
		r_queue.push(value);
		temp_queue.pop();
	}
	return r_queue;
}


template <typename T>
void print(const priority_queue<T>& p_queue) {
	priority_queue<T> temp_queue = p_queue;
	while (temp_queue.size() != 0) {
		double top = temp_queue.top();
		temp_queue.pop();
		cout << top << " ";
	}
	cout << endl;
}