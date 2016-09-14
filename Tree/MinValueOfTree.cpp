//
// Created by Deepak Ahuja on 13/09/16.
//


#include <iostream>
// C program to find maximum and minimum in a Binary Tree

#include <limits.h>
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

int getMinValue(node* root){

    cout<<"in stack : "<<root<<endl;

    if(root==NULL) {
        cout<<"return from stack "<<INT_MAX<<endl;
        return INT_MAX;//return 0 if counting nodes as maxdepth/height
    }
    else{

        int res=root->data;
        cout<<"res in root is : "<<res<<endl;
        int lval=getMinValue(root->left);
        cout<<"lval "<<lval<<" on root left : "<<root->left<<endl;
        int rval=getMinValue(root->right);
        cout<<"rval "<<rval<<" on root right : "<<root->right<<endl;

cout<<"================================"<<endl;
cout<<"lval is : "<<lval<<" res is : "<<res<<endl;
        if(lval<res)
            res=lval;
        cout<<"rval is : "<<rval<<" res is : "<<res<<endl;
        if(rval<res)
            res=rval;

        cout<<"returning : "<<res<<endl;
        return res;
    }
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
    cout<<"Min Value of tree is :"<<endl;
    int size=getMinValue(firstNode);

    cout<<size;

    return 0;
}