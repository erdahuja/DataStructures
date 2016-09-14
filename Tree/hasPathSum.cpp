//Find sum of all paths from root node to lef node, return true if sum is equal to given sum.

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

bool getResult(node* root,int sum){

  bool result;


    if(root==NULL){
        return sum==0;
    }

    else {

        int subSum = sum - root->data;
        return (getResult(root->left, subSum) || getResult(root->right, subSum));

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

   bool result=getResult(firstNode,5);
    cout<<"Result is :"<<result;



    return 0;
}