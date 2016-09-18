//
// Created by Deepak Ahuja on 15/09/16.
//

//new key is always inserted at leaf node.


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

node* insert(node* root,int key){

    if(root==NULL)
        return root=newNode(key);

    if(key<root->data)
        root->left=insert(root->left,key);
                else
       root->right= insert(root->right,key);
    return root;
}

void inorder(node* root){


    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }


}

int main() {

    /* Let us create following BST
                50
             /     \
            30      70
           /  \    /  \
         20   40  60   80 */
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // print inoder traversal of the BST
    inorder(root);

    return 0;
}