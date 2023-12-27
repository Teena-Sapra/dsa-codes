//singly linked list
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* next;
    node(int d){
        data=d;
        next = NULL;
    }
};
void insert_at_head(node* &head, int d){
    node* temp= new node(d);
    temp->next=head;
    head=temp;
}
void insert_at_tail(node* &tail, int d){
    node* temp= new node(d);
    tail->next=temp;
    tail= temp;
}
void insert_at_pos(node* &tail, node* &head, int position, int d){
    if(position==1){
        insert_at_head(head, d);
        return;
    }
    node* temp= head;
    int count=1;
    while(count<position-1){
        temp = temp->next;
        count++;
    }
    if(temp->next == NULL){
        insert_at_tail(tail,d);
        return;
    }
    node* nodetoinsert = new node(d);
    nodetoinsert->next = temp->next;
    temp->next = nodetoinsert;
}
void delete_node(node* &head, int pos){
    if(pos==1){
        node* temp=head;
        head= head->next;
        temp->next = NULL;
        delete temp;
    }
    else{
        node* prev=NULL;
        node* curr=head;
        int count=1;
        while(count<pos){
            prev=curr;
            curr=curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next =NULL;
        delete curr;
    }
}
void print(node* &head){
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    node* node1= new node(10);
    //cout<<node1 ->next;
    node* head = node1;
    node* tail=node1;
    insert_at_tail(tail, 11);
    insert_at_tail(tail, 12);
    insert_at_pos(tail, head, 4, 13);
    print(head);
    delete_node(head, 4);
    print(head);
    return 0;
}