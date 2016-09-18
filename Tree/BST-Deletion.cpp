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

struct node* findMin(struct node* node){
    struct node* current = node;

    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;

    return current;
}

// C function to search a given key in a given BST
/*struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is greater than root's key
    if (root->data < key)
        return search(root->right, key);

    // Key is smaller than root's key
    return search(root->left, key);
}*/

struct node* deleteNode(node* root,int data){


    if(root==NULL)
        return root;
    else if(data<root->data)
        root->left=deleteNode(root->left,data);
    else if(data>root->data)
        root->right=deleteNode(root->right,data);
    else//node to be deleted found.
    {//no child
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
            return root;
        }
            //one child
        else if (root->left == NULL) {
            node* temp = root;
            root = root->right;
            delete (temp);

        } else if (root->right == NULL) {
            node* temp = root;
            root = root->left;
            delete (temp);


        } else {
            node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }


    }

    return root;


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
             \       \
             40       80 */
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);

    root = insert(root, 40);
    root = insert(root, 70);

    root = insert(root, 80);

    printf("Inorder traversal of the given tree \n");
    inorder(root);


    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 80\n");
    root = deleteNode(root, 80);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    printf("\nDelete 70\n");
    root = deleteNode(root, 70);
    printf("Inorder traversal of the modified tree \n");
    inorder(root);

    return 0;
}