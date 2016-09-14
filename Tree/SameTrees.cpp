//
// Created by Deepak Ahuja on 14/09/16.
//

/*
 Check whether two trees are same or not.
*/

#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
};


Node* newNode(int data){

    Node* current=new Node();
    current->left=NULL;
    current->right=NULL;
    current->data=data;

    return current;

}

Node* Insert(struct Node* node,int data){

    if(node==NULL)
        node=newNode(data);
    else
    {
        if(data<=node->data)
            node->left=Insert(node->left,data);
        else
            node->right=Insert(node->right,data);
    }

    return node;
}


bool sameTree( Node* a,Node* b) {


    if(a==NULL&&b==NULL)
        return true;
    else if(a!=NULL&&b!=NULL)
    {
        return (a->data==b->data)&&sameTree(a->left,b->left)&&sameTree(a->right,b->right);
    } else
        return false;





}
void printTree(Node* root){

    if(root==NULL)
        return;
    cout<<root->data<<"\t";
    printTree(root->left);
    printTree(root->right);


}
int main() {
    cout<<"First tree : "<<endl;
    Node* root = NULL;
    root = Insert(root,1);
    root = Insert(root,2);
    root = Insert(root,3);
    root = Insert(root,4);
    root = Insert(root,5);
    root = Insert(root,6);


    printTree(root);

    Node* b=NULL;

    b = Insert(b,1);
    b = Insert(b,2);
    b = Insert(b,3);
    b = Insert(b,4);
    b = Insert(b,5);
    b = Insert(b,6);

    cout<<"\nSecond tree is : \n";
    printTree(b);
    cout<<endl;
    bool result=sameTree(root,b);
    cout<<"1 is true, 0 is false. "<<result;

    return 0;

}
