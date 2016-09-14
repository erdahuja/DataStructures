//
// Created by Deepak Ahuja on 13/09/16.
//

//
// Created by Deepak Ahuja on 13/09/16.
//

#include <iostream>
using namespace std;

struct node{

    int data;
    node* left;
    node* right;
};


node* newNode(int data){

    node* current=new node();
    current->left=NULL;
    current->right=NULL;
    current->data=data;

    return current;

}

int getSize(node* root){

    if(root==NULL)
        return 0 ;

    else
        return getSize(root->left)+getSize(root->right)+1;

}

int main() {
    cout<<"Basic tree creation : ";
    node* firstNode=newNode(1);
    firstNode->left=newNode(2);
    firstNode->right=newNode(3);
    firstNode->left->left=newNode(4);
    firstNode->left->right=newNode(5);


    cout<<"the tree is : \n";
    cout<<firstNode->data<<endl;
    cout<<"/"<<"\\"<<endl;
    cout<<firstNode->left->data<<"  ";

    cout<<firstNode->right->data<<endl;

    cout<<"/"<<"\\"<<endl;
    cout<<firstNode->left->left->data<<"  ";

    cout<<firstNode->left->right->data<<endl;
    cout<<"size of tree is :"<<endl;
    int size=getSize(firstNode);

    cout<<size;

    return 0;
}