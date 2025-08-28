#include<iostream>
#include<cstring>

using namespace std;

class A{
    public:
    int a;
    int b;

    public:
    int add(){
        return a + b;
    }

    // A type ka obj and using refrence insted of value
    // to avoid copying the entire object
    // overloading the + operator
    void operator + (A &obj){
        int value1 = this->a; // current obj is pointed by this pointer
        int value2 = obj.a;   // 2nd obj is passed as argument
        cout << "Output: " << value2 - value1 << endl;
    }
};

int main () {
    cout << "Hello World!" << endl;

    A a1, a2;
    a1.a = 4;
    a2.a = 6;
    a1 + a2; // a1.operator+(a2)
    return 0;
    }   