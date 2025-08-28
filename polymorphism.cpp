#include<iostream>
#include<cstring>   
using namespace std;

class A{
    public:
    void func1(){
        cout << "I am function 1 of class A" << endl;
    }

    // changing the functions signature is called function overloading
    // this is a type of compile time polymorphism
    void func1(string name){
        cout << "I am function 1 of class A" << name <<endl;
    }

    void func2(){
        cout << "I am function 2 of class A" << endl;
    }
};

int main () {
    cout << "Hello World!" << endl;
    A a1;
    a1.func1();
    a1.func1(" John");
    a1.func2();

    return 0;
    }