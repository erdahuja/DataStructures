#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{

int data;
node* left;
node* right;

};
node* newNode(int data);
int main(){
struct node* root=newNode(10);
 /* following is the tree after above statement 
 
        1
      /   \
     NULL  NULL  
  */
  

 root->left        = newNode(2);

 
  root->right       = newNode(3);

 /* 2 and 3 become left and right children of 1
           1
         /   \
        2      3
     /    \    /  \
    NULL NULL NULL NULL
  */
 

    root->left->left  = newNode(4);
/* 4 becomes left child of 2
           1
       /       \
      2          3
    /   \       /  \
   4    NULL  NULL  NULL
  /  \
NULL NULL
*/

cout<<root;

return 0;
}

 node* newNode(int data){
	
node* node=(struct node*)malloc(sizeof(struct node*));

node->data=data;
node->left=NULL;
node->right=NULL;
return node;

	}


