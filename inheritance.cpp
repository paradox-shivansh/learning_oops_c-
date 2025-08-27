#include<iostream>
#include<cstring>
// #include "inheritance.h"
using namespace std;

class Human{
    public:
    int height;
    int weight;
    int age;

    // Height
    void setheight(int height){
       this->height = height;
    }
    int getheight(){
        return height;
    }

    // Age
    void setage(int age){
        this->age = age;
    }
    int getage(){
        return age;
    }
};

//male class inherited from human class
// ex. i inherited my genes from my parents
class Male: public Human{
    public:
    string color;
    

    void sleep(){
        cout << "the person is sleeping" << endl;
    }

    };

int main () {
    cout << "Hello World!" << endl;

    Male m1;
    m1.setage(20);

    cout << m1.getage() << endl;

    m1.sleep();

    return 0;
    }