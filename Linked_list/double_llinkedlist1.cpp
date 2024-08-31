#include<iostream>
#include<vector>
using namespace std;
//prefer class over struct
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
    public:
        Node(){
            data = 0;
            next=nullptr;
            prev =nullptr;
        }
    public:
        Node(int x){
            data = x;
            next=nullptr;
            prev = nullptr;
        }
    public:
        Node(int x,Node* next1 ,Node* prev1){
            data = x;
            next = next1;
            prev = prev1;
        }
};



Node* constructDLL(vector<int>& arr) {
    
    if(arr.size()==0){
        return nullptr;
    }
    Node * head = new Node(arr[0]);
    Node* temp =head;
    int count =1;
    for(int i=1;i<arr.size();i++){
        Node* newnode = new Node(arr[i],nullptr,temp);
        temp->next = newnode;
        temp = newnode;
    }
    return head;   
}

Node * deleteHead(Node *head) {
    if (head ==NULL){
        return NULL;

    }
    if (head->next ==NULL){
        return NULL;

    }
    
    head = head->next ;
    head->prev = NULL;
    return head;
}

Node * deleteLastNode(Node *head) {
    Node * temp = head;
    if(temp ==nullptr){
        return nullptr;
    }
    if(temp->next ==nullptr){
        temp = nullptr;
        return temp;       

    }
    while(temp->next !=nullptr){
        temp =temp->next;
    }
    temp = temp->prev;
    temp ->next = nullptr;

    
    // temp =nullptr;
    return head;
}

Node *deleteNode(Node *head, int k){
    Node* temp =head;
    int count=0;
    if(temp ==nullptr){
        return nullptr;
    }
    if(temp->next ==nullptr && k==1){
        return nullptr;
    }
    while(temp !=nullptr){
        count++;
        if(count == k){
            if(temp->next ==nullptr){
                temp = temp->prev;
                temp->next = nullptr;
                return head;     
            }
            if(temp->prev ==nullptr){
                temp = temp->next;
                temp->prev = nullptr;
                return temp;     
            }
            Node * newnode = temp->next;
            
            temp = temp->prev;
            temp->next = newnode;
            newnode-> prev = temp;
            return head;
        }
        
        temp =temp->next;
    }
    if(k>count){
        return head;
    }
}

Node* insertAtFront(Node *head, int k) {
    Node * newnode = new Node(k);
    if(head ==nullptr){
        return newnode;
    }
    newnode-> next= head;
    head->prev =newnode;
    return newnode;
}

Node * insertBeforeTail(Node *head, int k) {
    Node * newnode = new Node(k);
    if(head  ==nullptr){
        return newnode;
    }
    if(head ->next ==nullptr){
        newnode ->next =head;
        head->prev = newnode;
        return newnode;
    }
    Node * temp= head;
    while(temp->next !=nullptr){
        temp =temp->next;
    }
    Node * last = temp;
    temp =temp->prev;
    temp->next = newnode;
    newnode->prev =temp;
    newnode->next =last;
    last->prev = newnode;
    return head;
}

Node * insertAtTail(Node *head, int k) {
    Node* newnode = new Node(k);
    if(head ==nullptr){
        return newnode;
    }
    Node * temp = head;
    while(temp->next != nullptr){
        temp =temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}




int main(){

}