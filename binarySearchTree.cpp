#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};
node* insertIntoBst(node*root, int d){
    if(root==NULL){
        root = new node(d);
        return root;
    }
    if(d > root->data){
        root->right = insertIntoBst(root->right,d);
    }
    else{
        root->left = insertIntoBst(root->left, d);
    }
}
void levelOrderTraversal(node*root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
node* minValue(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}
node*maxValue(node*root){
    node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}
node* deleteFromBst(node* root, int val){
    if(root==NULL){
        return root;
    }
    if(root->data == val){
        //0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child
        if(root->left!=NULL && root->right ==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        if(root->left==NULL && root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL && root->right!=NULL){
            node* min= minValue(root->right);
            int mini= min->data;
            root->data = mini;
            root->right = deleteFromBst(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left= deleteFromBst(root->left, val);
        return root;
    }
    else{
        root->right = deleteFromBst(root->right, val);
        return root;
    }

}
int main(){
    node*root=NULL;
    int data;
    cout<<"enter data for bst: ";
    cin>>data;
    while(data!=-1){
        root= insertIntoBst(root, data);
        cin>>data;
    }
    cout<<endl;
    levelOrderTraversal(root);
    root= deleteFromBst(root,50);
    levelOrderTraversal(root);
}
//50 20 70 10 30 90 110 -1