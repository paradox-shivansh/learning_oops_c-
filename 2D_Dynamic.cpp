#include<iostream>
using namespace std;


int main(){

    int row,col;
    cout<<"Enter the rows"<<endl;
    cin>>row;
    cout<<"Enter the cols"<<endl;
    cin>>col;

    //Creating new 2D array
    cout<<"Creating the values of array"<<endl;
    int **arr = new int* [row];
    for(int i=0;i<row;i++){
        arr[i] = new int [col];
    }

    //Getting in the values 
    cout<<"Creating the values of array"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>arr[i][j];
        }
    }
    
    //Displaying in the values 
    cout<<"Displaying the values of array"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    //Deleting in the values 
    for(int i=0;i<row;i++){
        delete [] arr[i];
    }
    delete []arr;

    return 0;
}