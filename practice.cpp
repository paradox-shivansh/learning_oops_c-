#include <iostream>
using namespace std;

class Rectangle {
    int *length;
    int *breath;
public:
    Rectangle(int length, int breath) {
        this->length = new int(length);
        this->breath = new int(breath);
        }
        
    Rectangle() {
        length = new int(0);
        breath = new int(0);
        }
    
    Rectangle(int n) {
        length = new int(n);
        breath = new int(n);
        }
    int area()
        { return (*length) * (*breath); }
        
    ~Rectangle() {
        cout << "Destructor called for Rectangle\n";
        }
};

int main() {
    Rectangle arr[3] = { Rectangle(), Rectangle(5), Rectangle(3,4) };

    for(int i=0; i<3; i++)
        cout << "Area of rectangle " << i+1 << " = " << arr[i].area() << endl;

    return 0;
}
