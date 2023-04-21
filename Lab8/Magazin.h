#pragma once
#include "Print.h"
class Magazin :
    public Print
{
    int pages;
public:
    
    Magazin();
    Magazin(string, string, int);
    Magazin(const Magazin&);

    void setPages(int);
    int getPages();

    void output() override {
        Print::output();
        cout << "pages: " << pages << endl;
    }
    void input() override {
        Print::input();
        cin >> pages;
    }

    Magazin& operator=(const Magazin&);
    friend ostream& operator<<(ostream&, const Magazin&);
    friend istream& operator>>(istream&, Magazin&);
};