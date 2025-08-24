#include <iostream>
#include "hero.cpp"
#include<cstring>
using namespace std;



int main () {
    cout << "Hello World!" << endl;

    // an object has been created
    Hero h1;
    cout << "size : " << sizeof(h1) << endl;


    Hero ramesh;
    ramesh.sethealth(70);
    ramesh.level= 'A';
    cout << "Health of Rames : " << ramesh.gethealth() << endl;
    cout << "Level of Rames : " << ramesh.level << endl;

    // Dynamically allocating 
    Hero *b = new Hero;

    b->sethealth(70);
    b->level = 'B';
    cout << "Health of Rames : " << (*b).gethealth() << endl;
    cout << "Level of Rames : " << (*b).level << endl;
    
    Hero shiva(90 , 'G');
    cout << "shiva level is " << shiva.level << endl;
    return 0;
}