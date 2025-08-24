#include<iostream>
using namespace std;
#include<cstring>

class Hero {
    public:
    Hero(){
        cout << "Constructor is Called a bitch" << endl;
    }
    
    private:
        int health;
    
    public:
        char *name;
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

        // Disructor 
        ~Hero(){
            cout << "Destructor is called" <<endl;
        }

        //copying a constructor

        Hero (Hero &temp){
            char *ch = new char[strlen(temp.name)+1];
            strcpy(ch , temp.name);
            
            cout << "copy" << endl;
            this->name= ch;
            this->health = temp.health;
            this->level = temp.level;
        }
};