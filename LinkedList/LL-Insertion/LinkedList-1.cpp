#include <iostream>
#include <cstdlib>

using namespace std;

struct node{ //creating a node
	int data;
	node *next;
};

// Program to create a simple linked list with 3 nodes

int main(){
	cout<<"Linked List Basics";
	struct node *head=NULL;
	struct node *first=NULL;
	struct node *second=NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	
	head->data=1;//data
	head->next=first;//link to next node
	
	
	first->data=1;
	first->next=second;
	
	second->data=1;
	second->next=NULL;
	
	return 0;
}


