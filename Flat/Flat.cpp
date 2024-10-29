// Flat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Flat {
    int plosh;
    char* addres;
    double price;
public:
    Flat() :price(0), addres(nullptr), plosh(0) {};
    Flat(const char*_addres,int _plosh,double _price) :price(_price), plosh(_plosh) {
        addres = new char[strlen(_addres) + 1];
        strcpy_s(addres, strlen(_addres) + 1, _addres);
    };
    ~Flat() {
        delete[]addres;
    }
    bool operator==(const Flat&obj) {
        if (plosh == obj.plosh) {
            return true;
        }
        return false;
    }
    Flat(const Flat&obj) {
        plosh = obj.plosh;
        price = obj.price;
        addres = new char[strlen(obj.addres) + 1];
        strcpy_s(addres, strlen(obj.addres) + 1, obj.addres);
    }
    Flat operator=(const Flat&obj) {  
        if (this == &obj) {
            return*this;
        }
        if (addres != nullptr) {
            delete[]addres;
        }
        plosh = obj.plosh;
        price = obj.price;
        addres = new char[strlen(obj.addres) + 1];
        strcpy_s(addres, strlen(obj.addres) + 1, obj.addres);
        return *this;
    }

    bool operator>(const Flat&obj) {
        if (price > obj.price) {
            return true;
        }
        return false;
    }

    void Print() {
        cout << addres << endl << price << endl << plosh << endl;
    }
};

int main()
{
    Flat a("123 adadad", 125, 1234);
    Flat b("456 ada", 200, 1500);
    Flat c = a;
    Flat d("789 adawdasgs", 100, 1100);
    d = b;           
    if (a == c) cout << "a and c have the same area" << endl;
    if (b > a) cout << "b is more expensive than a" << endl;

    a.Print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
