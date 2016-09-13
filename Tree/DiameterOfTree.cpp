//
// Created by Deepak Ahuja on 13/09/16.
//

#include<iostream>

using namespace std;

struct Node {
    char data;
    Node *left;
    Node *right;
};


Node* Insert(Node* root,char data){

    if(root == NULL) {
        root = new Node();
        root->data = data;
        root->left = root->right = NULL;
    }
    else if(data <= root->data) root->left = Insert(root->left,data);
    else root->right = Insert(root->right,data);
    return root;
}


int max(int a, int b)
{
    return (a >= b)? a: b;
}


int height(Node* node){
    if(node == NULL)
        return 0;

    /* If tree is not empty then height = 1 + max of left
       height and right heights */
    return 1 + max(height(node->left), height(node->right));


}

int diameter(Node* root){

    if(root==NULL){
        return 0;
    }
    int lheight=height(root->left);

    int rheight=height(root->right);

    int ldiameter=diameter(root->left);
    int rdiameter=diameter(root->right);

    return max(lheight+rheight+1,max(ldiameter,rdiameter));



}



int main() {
    /*Code To Test the logic
      Creating an example tree
                 M
               / \
              B   Q
             / \   \
            A   C   Z
    */
    Node* root = NULL;
    root = Insert(root,'M'); root = Insert(root,'B');
    root = Insert(root,'Q'); root = Insert(root,'Z');
    root = Insert(root,'A'); root = Insert(root,'C');
    //Print Nodes in Level Order.
    int dia=diameter(root);

    cout<<"Diameter is "<<dia;
}