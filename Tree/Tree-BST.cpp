#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct node{

int data;
node* left;
node* right;

};




 node* newNode(int data){
	
node* node=(struct node*)malloc(sizeof(struct node*));

node->data=data;
node->left=NULL;
node->right=NULL;
return node;

	}

node* Insert(node* root,int data){
if(root==NULL){
root=newNode(data);
return root;

}

if(data<=root->data){

root->left=Insert(root->left,data);
	}
	else {
root->right=Insert(root->right,data);

		}

return root;
	}

	bool search(node* root,int data){

	if(root == NULL) {
		return false;
	}
	else if(root->data == data) {
		return true;
	}
	else if(data <= root->data) {
		return search(root->left,data);
	}
	else {
		return search(root->right,data);
}
			}

int main(){
node* root=NULL;

root=Insert(root,10);
root=Insert(root,15);
root=Insert(root,8);
root=Insert(root,20);
int number;
	cout<<"Enter number be searched\n";
	cin>>number;
	//If number is found, print "FOUND"
	if(search(root,number) == true) cout<<"Found\n";
else cout<<"Not Found\n";



	return 0;
	}
