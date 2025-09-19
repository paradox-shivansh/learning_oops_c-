#include <iostream>
using namespace std;

class Student {
protected:
    int rollNo;
    string name;
public:
    void GetDetails() {
        cout << "Enter student roll number: ";
        cin >> rollNo;
        cout << "Enter name of the student: ";
        cin >> name;
    }
    void DisplayDetails() {
        cout << "Roll No: " << rollNo << ", Name: " << name << endl;
    }
};

class Marks : public Student {
protected:
    int subject1, subject2;
public:
    void GetMarks() {
        cout << "Enter the marks of subject 1: ";
        cin >> subject1;
        cout << "Enter the marks of subject 2: ";
        cin >> subject2;
    }
    void DisplayMarks() {
        cout << "Subject 1: " << subject1 << ", Subject 2: " << subject2 << endl;
    }
};

class Result : public Marks {
    int totalMarks;
public:
    void CalculateResult() {
        totalMarks = subject1 + subject2;
    }
    void DisplayResult() {
        DisplayDetails();
        DisplayMarks();
        cout << "Total Marks = " << totalMarks << endl;
        if(totalMarks >= 50) cout << "Status: PASSED\n";
        else cout << "Status: FAILED\n";
        cout << "----------------------\n";
    }
};

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;

    Result r[n];

    for(int i=0; i<n; i++) {
        cout << "\nEntering details for student " << i+1 << ":\n";
        r[i].GetDetails();
        r[i].GetMarks();
        r[i].CalculateResult();
    }

    cout << "\n--- Results ---\n";
    for(int i=0; i<n; i++) {
        r[i].DisplayResult();
    }

    return 0;
}
