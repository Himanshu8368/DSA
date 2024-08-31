#include<iostream>
using namespace std;

int main(){
    int x=2;
    int* y=&x; // y reference x
    cout<<y<<'\n';
    cout<<*y<<endl;
}