#include<iostream>
using namespace std;

class Hero {
    public:
    Hero(){
        cout << "Constructor is Called" << endl;
    }
    
    private:
        int health;
    
    public:
        char level;

        void print(){
            cout << level << endl;
        }

        int gethealth(){
            return health;
        }

        void sethealth(int h){
            health = h;
        }

        // Parameterized costructor 
        Hero(int health , char level){
            this->health = health;
            this->level = level;
        }
};