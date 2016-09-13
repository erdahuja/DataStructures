#include <queue>
#include <iostream>
#include <stdlib.h>

using namespace std;
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

/* Helper function that allocates a new node
with the given data and NULL left and right
pointers. */
struct node* newNode(int data)
{
    struct node* node = (struct node*)
            malloc(sizeof(struct node));
    node->data  = data;
    node->left  = NULL;
    node->right = NULL;

    return(node);
}


struct node* insert(struct node* node, int data)
{
    /* 1. If the tree is empty, return a new,
        single node */
    if (node == NULL)
        return(newNode(data));
    else


    {
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data)
            node->left  = insert(node->left, data);
        else
            node->right = insert(node->right, data);

        /* return the (unchanged) node pointer */
        return node;
    }
}


//Level Order

void LevelOrder(node *root){

    if(root==NULL){

        return;
    }


    queue<node*> Q;
    Q.push(root);

    while(!Q.empty()){

        node* current = Q.front();

        cout<<current->data<<" ";

        if(current->left!=NULL)
            Q.push(current->left);
        if(current->right!=NULL)
            Q.push(current->right);
        Q.pop();

    }



}

int main(){


    struct node* root = NULL;
    root = insert(root, 4);
    insert(root, -2);
    insert(root, 0);
    insert(root, 3);
    insert(root, 6);
    insert(root, 5);

    LevelOrder(root);


    return 0;}


