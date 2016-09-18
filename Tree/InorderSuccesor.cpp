//
// Created by Deepak Ahuja on 16/09/16.
//


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

node* search(node* root,int data){

    if(root==NULL)
        return NULL;
    else if(root->data==data)
        return root;
    else if(data<root->data)
        return search(root->left,data);
    else
        return search(root->right,data);

}

node* findMin(node* root){

    if(root==NULL)
        return NULL;

    while(root->left!=NULL)
        root=root->left;

    return root;


}

node* inorderSuccessor(node* root,int data){


    node* current=search(root,data);
    if(current==NULL)
        return NULL;
    if(current->right!=NULL)
        return findMin(current->right);

    else
    {

        node* succesor=NULL;
        node* ancestor=root;

        while(ancestor!=current){

            if(current->data<ancestor->data) {
                succesor = ancestor;
                ancestor = ancestor->left;
            } else
                ancestor=ancestor->right;

        }
        return succesor;

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
    node* succ=inorderSuccessor(root,40);
    cout<<succ->data;


    return 0;
}
