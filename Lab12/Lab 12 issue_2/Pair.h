#pragma once
#include <iostream>

class Pair {
private:
	int first;
	double second;
public:
	Pair();
	Pair(int, double);
	Pair(const Pair&);
	~Pair() {};

	int getFirst() const;
	void setFirst(int);
	double getSecond() const;
	void setSecond(double);

	void show();

	template <typename T>
	Pair& operator+(const T);

	Pair& operator-(const Pair&);
	Pair& operator=(const Pair&);
	friend bool operator<(const Pair&, const Pair&);
	bool operator() (const Pair* comp1, const Pair* pair) {
		return (comp1->first + comp1->second < pair->first + pair->second);
	}
	friend std::istream& operator>>(std::istream&, Pair&);
	friend std::ostream& operator<<(std::ostream&, const Pair&);
};

template <typename T>
Pair& Pair::operator+(const T p) {
	if (p != (int)p) {
		second += p;
	}
	else {
		first += p;
	}
	return *this;
}
