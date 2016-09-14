//
// Created by Deepak Ahuja on 13/09/16.
//

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

int getMaxDepth(node* root){

    if(root==NULL)
        return -1;//return 0 if counting nodes as maxdepth/height

    else{

        int lHeight=getMaxDepth(root->left);
        int rHeight=getMaxDepth(root->right);
        return (lHeight>rHeight?lHeight:rHeight)+1;
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
    cout<<"Max depth/height of tree is :"<<endl;
    int size=getMaxDepth(firstNode);

    cout<<size;

    return 0;
}