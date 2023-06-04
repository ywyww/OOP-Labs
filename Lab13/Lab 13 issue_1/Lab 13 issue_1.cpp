#include <iostream>
#include <list>
#include "Pair.h"
#include <algorithm>
#include <functional>
#include <numeric>
using namespace std;

template <typename T>
void print(const list<T>&);

double leftBound = 3,
rightBound = 6;

bool removePred(Pair t) {
	return t.getFirst() >= leftBound && t.getFirst() <= rightBound && t.getSecond() >= leftBound && t.getSecond() <= rightBound;
}

struct comparator {
public:
	static bool cd(Pair pair1, Pair pair) {
		return pair1.getFirst() + pair1.getSecond() > pair.getFirst() + pair.getSecond();
	}
};


int main() {
	//1
	list<Pair> pairList;
	pairList.push_back(Pair(1, 2.5));
	pairList.push_back(Pair(4, 5.5));
	pairList.push_back(Pair(5, 7.5));

	Pair a = accumulate(pairList.begin(), pairList.end(), Pair(0, 0), [](Pair t1, Pair t2) {return t1 + t2.getFirst() + t2.getSecond(); });
	int arithmeticMeanInt = a.getFirst() / pairList.size();
	double arithmeticMeanDouble = a.getSecond() / pairList.size();
	pairList.push_back(Pair(arithmeticMeanInt, arithmeticMeanDouble));

	print(pairList);


	//2
	list<Pair> pairListSecond;
	remove_copy_if(pairList.begin(), pairList.end(), inserter(pairListSecond, pairListSecond.begin()), removePred);

	print(pairListSecond);


	//3 
	list<Pair> pairListThird = pairList;
	pairListThird.sort();
	print(pairListThird);
	return 0;
}

template <typename T>
void print(const list<T>& p_list) {
	for (auto itBegin = p_list.begin(); itBegin != p_list.end(); itBegin++) {
		cout << *itBegin << " ";
	}
	cout << endl;
}
