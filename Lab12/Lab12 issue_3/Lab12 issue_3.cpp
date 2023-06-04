#include <iostream>
#include <set>
#include <Windows.h>
#include "Pair.h"
using namespace std;


int main() {
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    multiset <Pair> mst;
    multiset <Pair> tmp;
    mst.insert(Pair(1, 5.5));
    mst.insert(Pair(2, 7.8));
    mst.insert(Pair(3, 4.3));
    Pair sr(0, 0);
    cout << "task 1:" << endl;
    for (auto it = mst.begin(); it != mst.end(); it++)
    {
        sr = sr + *it;
        cout << *it << endl;
    }

    //1
    sr.setFirst(sr.getFirst() / mst.size());
    sr.setSecond(sr.getSecond() / mst.size());
    mst.insert(sr);

    //2
    Pair max = *mst.begin();
    Pair min = *mst.begin();
    tmp = mst;
    mst.clear();
    int c = 0;
    int i = 2, j = 8;
    Pair res;
    cout << "task 2:" << endl;

    for (auto it = tmp.begin(); it != tmp.end(); it++, c++)
    {
        if ((c < i) || (c > j) || (res.getFirst() != (*it).getFirst() || res.getSecond() != (*it).getSecond()))
        {
            if (max < *it) max = *it;
            if (!(min < *it)) min = *it;
            mst.insert(*it);
            cout << *it << endl;
        }
    }
    cout << "task 3:" << endl;
    tmp = mst;
    mst.clear();
    for (auto it = tmp.begin(); it != tmp.end(); it++)
    {
        mst.insert(max + min + *it);
        cout << max + min + *it << endl;
    }
}