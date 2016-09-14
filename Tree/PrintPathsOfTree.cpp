//
// Created by Deepak Ahuja on 13/09/16.
//

//Print all possible paths of given tree.



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

void printArray(int array[],int length){
    cout<<"path is : ";
    for(int i=0;i<length;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
}

void printPaths(node* root,int path[],int length){

    if(root==NULL)
        return ;

    path[length++]=root->data;

    if(root->right==NULL&&root->left==NULL){
        printArray(path,length);
    }

    else {
        printPaths(root->left, path, length);
        printPaths(root->right, path, length);

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
    int path[1000];
    int length=0;
    printPaths(firstNode,path,length);

    return 0;
}