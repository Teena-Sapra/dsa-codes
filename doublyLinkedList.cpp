#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node*next;
    node*prev;
    node(int d){
        data=d;
        next=NULL;
        prev=NULL;
    }
};
void print(node*head){
    node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getLength(node*head){
    node*temp=head;
    int l=0;
    while(temp!=NULL){
        l++;
        temp=temp->next;
    }
    return l;
}
void insertAtHead(node*&head, node*&tail, int d){
    node*newNode= new node(d);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    newNode->next= head;
    head->prev= newNode;
    head=newNode;
}
void insertAtTail(node* &tail, node*&head, int d){
    node*newNode = new node(d);
    if(tail==NULL){
        tail=newNode;
        head=newNode;
        return;
    }
    tail->next=newNode;
    newNode->prev=tail;
    tail=newNode;
}
void insertAtPos(node*&head, node*&tail, int d, int pos){
    if(pos==1){
        insertAtHead(head,tail, d);
        return;
    }
    node*temp= head;
    int c=1;
    while(temp!=NULL && c<pos-1){
        temp=temp->next;
        c++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,head,d);
    }
    else if(temp==NULL){
        cout<<"position out of bounds"<<endl;
    }
    else{
        node*newNode= new node(d);
        newNode->next=temp->next;
        temp->next->prev= newNode;
        temp->next=newNode;
        newNode->prev=temp;
    }
}
void deleteNode(node*&head, node*&tail, int pos){
    if(pos==1){
        node*temp=head;
        temp->next->prev=NULL;
        head=temp->next;
        temp->next=NULL;
        delete temp;
    }else{
        node*curr=head;
        node*p=NULL;
        int c=1;
        while(curr!=NULL && c<pos){
            p=curr;
            curr=curr->next;
            c++;
        }
        if(curr==NULL){
            cout<<"pos not found"<<endl;
        }
        else if(curr->next==NULL){
            curr->prev=NULL;
            p->next=NULL;
            tail=p;
            delete curr;
        }
        else{
            curr->prev=NULL;
            p->next= curr->next;
            curr->next->prev= p;
            curr->next=NULL;
            delete curr;
        }
    }
}
void deleteSpecificNode(node*&head, int val){
    node*curr=head;
    node*p=NULL;
    while(curr!=NULL){
        if(curr->data==val){
            if(curr==head){
                head=head->next;
                if(head){
                    head->prev=NULL;
                }
            }
            else{
                p->next=curr->next;
                curr->next->prev=p;
            }
            delete curr;
            return;
        }
        p=curr;
        curr=curr->next;
    }
    cout<<"value not found";
}
int main(){
    node*node1= new node(10);
    node*head= node1;
    node*tail=node1;
    insertAtHead(head, tail, 11);
    insertAtHead(head, tail,12);
    insertAtTail(tail,head, 9);
    insertAtPos(head, tail, 8, 2);
    print(head);
    deleteSpecificNode(head, 8);
    print(head);
    return 0;
}