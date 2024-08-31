#include<iostream>
#include<vector>
#include<bits/stdc++.h>
/// linked list basic all done
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

void create_list(vector<int>& arr,node*head){
    node* mover = head;
    for (int i=1;i<arr.size();i++){
        node* temp =new node(arr[i],nullptr);
        mover->next=temp;
        mover =temp;
    }
    cout<<head->data<<"\n";
    cout<<mover->data<<endl;
}

void iterate_list(node*head){
    node* temp = head;
    cout<<"linked_list element is"<<endl;
    while(temp != nullptr){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<endl;
}

void length_of_list(node*head){
    node* temp = head;
    int count =0;
    cout<<"length of list  is"<<endl;
    while(temp != nullptr){
        count++;
        temp =temp->next;
    }
    cout<<count<<endl;
}

void search_elememt(node* head , int element){
    node* temp = head;
    int check =0;
    while(temp != nullptr){
        if(temp->data == element){
            check=1;
            cout<<"yes"<<endl;
        }
        temp =temp->next;
    }
    if(check != 1){
        cout<<"no matching found"<<endl;
    }
    
}

void delete_head(node* head){
    node * temp =head;
    node* next =temp->next;
    temp = temp->next;
    cout<<"after deleting the head list is"<<endl;
    iterate_list(temp);
}
void delete_tail(node* head){
    node * starting =head;
    node * temp =head;
    while(temp->next->next != nullptr){
        temp =temp->next;
    }
    temp->next =nullptr;
    cout<<"after deleting the tail list is"<<endl;
    iterate_list(starting);
}
/*
Node *deleteLast(Node *list){
    // Write your code here
    Node * starting =list;
    Node * temp =list;
    while(temp->next->next != nullptr){
        temp =temp->next;
    }
    temp->next =nullptr;
    return starting;
}
\*/

void delete_kth_element(node* head , int k){
    node* temp =head;
    node* start =head;
    int count =0;
    if(k==0){
        start=temp->next;
    }
    while(temp !=nullptr){
        if(count ==k-1){
            temp->next = temp->next->next;
            break;
        }
        count++;
        temp =temp->next;
    }
    iterate_list(start);
}

/*
Node *deleteNode(Node *head, int k)
{
    Node* temp =head;
	Node* start =head;
    int count =0;
	if(start ==nullptr){
		start =nullptr;
	    return start;
	}
    if(k==0){
        start=temp->next;
        delete temp;
		return start;
    }
    while(temp !=nullptr){
        if(count ==k-1){
            if(temp->next)
                temp->next = temp->next->next;
			return start;
        }
        count++;
        temp =temp->next;
    }
    if(count<k){
        return start;
    }

}
*/

Node* insertAtFirst(Node* list, int newValue) {
    // Write your code here
    Node* head = new Node(newValue,nullptr);
    head->next = list;
    return head;
     
}

Node* insertEnd(Node* head, int k) {
    // Write your code here.
    Node* start =head;
    Node* temp =head;
    Node* add = new Node(k);
    if(temp == NULL){
        start =add;
        return start;
    }
    while(temp->next !=NULL){
        temp =temp->next;
    }
    temp->next = add;
    return start;
}

Node * insert(Node * head, int n, int pos, int val) {
    Node* newnode = new Node(val );
    int count =0;
    Node* temp =head;
    if(temp ==NULL){
        temp = newnode;
        return temp;
    }
    if(pos ==0){
        newnode->next = temp;
        temp=newnode;
        return temp;
    }

    while(temp !=NULL  ){
        // temp =temp->next;
        count++;
        if(count ==pos){
            if(temp->next ==NULL){
                temp->next = newnode;
                return head;
            }
            Node * newtemp = temp->next;
            temp->next =newnode;
            newnode->next=newtemp;
        }
        temp =temp->next; 
    }   
    return head;
}

Node* insertBeforeValue(Node* head, int x, int val){
    Node* newnode = new Node(x);
    int count =0;
    Node* temp =head;
    if(temp->data==val){
        newnode->next = temp;
        temp =newnode;
        return temp;
    }
    while(temp!=NULL){
        if(temp->next ==NULL){
            return head; 
        }
        if(temp->next->data==val){
            newnode->next=temp->next;
            temp->next=newnode;
            return head;
        }

        temp =temp->next;
        
    }
    return head;

}

int main(){
    vector<int> arr ={1,2,3,4,5};
    node* head = new node(arr[0]);
    create_list(arr,head);
    iterate_list(head);
    length_of_list(head);
    search_elememt(head,5);
    delete_head(head);
    delete_tail(head);
    delete_kth_element(head,2);

}