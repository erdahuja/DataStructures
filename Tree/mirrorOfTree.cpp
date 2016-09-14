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


void mirror(struct Node* node) {
    if (node == NULL) {
        return;
    } else {
        struct Node *temp;

        // do the subtrees
        mirror(node->left);
        mirror(node->right);

        // swap the pointers in this node
        temp = node->left;
        node->left = node->right;
        node->right = temp;
    }


}

    int main() {
        cout<<"Basic tree creation : ";
        Node* firstNode=newNode(1);
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

        mirror(firstNode);



        cout<<"the mirror is : \n";
        cout<<firstNode->data<<endl;
        cout<<"/"<<"\\"<<endl;
        cout<<firstNode->left->data<<"  ";

        cout<<firstNode->right->data<<endl;

        cout<<"  /"<<"\\"<<endl;
        cout<<firstNode->right->left->data<<"  ";
        cout<<firstNode->right->right->data<<endl;

        return 0;

    }
