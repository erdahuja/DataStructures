//
// Created by Deepak Ahuja on 14/09/16.
//

/*
 Change a tree so that the roles of the
 left and right pointers are swapped at every node.
 So the tree...
       4
      / \
     2   5
    / \
   1   3

 is changed to...
       4
      / \
     5   2
        / \
       3   1
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


void doubleTree(struct Node* node) {

    if(node==NULL)
        return;
    else {

        doubleTree(node->left);
        doubleTree(node->right);
        Insert(node,node->data);

    }

}
void printTree(Node* root){

    if(root==NULL)
        return;
    cout<<root->data<<"\t";

    printTree(root->left);
    printTree(root->right);

}
int main() {
    cout<<"Basic tree creation : "<<endl;
    Node* root = NULL;
    root = Insert(root,1);

    root = Insert(root,2);

    root = Insert(root,3);

    root = Insert(root,4);


    root = Insert(root,5);


    root = Insert(root,6);


printTree(root);

    doubleTree(root);



    cout<<"the new tree is : \n";
printTree(root);

    return 0;

}
