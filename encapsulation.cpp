#include <iostream>
// #include <encapsulation.h>
#include<cstring>
using namespace std;

class Student{
    private:
    int age;
    int height;

    public:
    int getage(){
        return this->age;
    }
    void setage(int a){
        if(a<0){
            return;
        }
        this->age = a;
    }

    
};


int main () {
    cout << "Hello World!" << endl;

    Student s1;
    s1.setage(20);  
    cout << s1.getage() << endl;

    return 0;

    }