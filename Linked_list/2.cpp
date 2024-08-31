#include<iostream>
#include<vector>
using namespace std;
//prefer class over struct
class node{
    public:
        int data;
        node* next;
    public:
        node(int data1,node* next1){
            data = data1;
            next=next1;
        }
    public:
        node(int data1){
            data = data1;
            next = nullptr;
        }
};

int main(){
    vector<int> arr ={1,2,3,4,5};
    node* y = new node(arr[0]);
    cout<<y<<endl;
    cout<<y->data<<endl;
    cout<<y->next<<endl;
}