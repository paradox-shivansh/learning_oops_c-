#include<iostream>
#include<cstring>

using namespace std;

class Animal {
    public:
    int age;
    int weight;

    public:
    void bark() {
        cout << "Woof Woof" << endl;
    }
};

class Human {
    public:
    string color;

    public:
    void speak() {
        cout << "Hello there!" << endl;
    }
};

class Hybrid: public Animal, public Human {
    public:
    void show() {
        cout << "I am a hybrid of animal and human." << endl;
    }
};

int main () {
    cout << "Hello World!" << endl;

    Hybrid h1;
    h1.bark();
    h1.speak();

    return 0;
    }