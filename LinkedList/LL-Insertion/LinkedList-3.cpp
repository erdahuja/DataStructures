//trasverse and insert node at beginning

#include <iostream>
#include <cstdlib>

using namespace std;

struct node{ //creating a node
int data;
node *next;
};

void print(node *n){
	cout<<"\n data : ";
	
	while(n!=NULL){
	cout<<n->data<<" ";
	n=n->next;
	}

}

/*
void push(node *head,int data){//can't pass head as it is actually a copy of head of LL
	
	struct node *nw=(struct node*)malloc(sizeof(struct node));
	nw->data=data;
	nw->next=head;
	print(nw);//only use print in local here, bcs copy of head is passed.
	//use double pointer to change value in one functn in other functn.
	
	}
	


*/


void push(struct node** head_ref, int new_data)
{
    /* 1. allocate node */
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
  
    /* 2. put in the data  */
    new_node->data  = new_data;
  
    /* 3. Make next of new node as head */
    new_node->next = (*head_ref);
  
    /* 4. move the head to point to the new node */
    (*head_ref)    = new_node;
}

int main(){ 

cout<<"Linked List traverse";
	
	struct node *first=NULL;
	struct node *second=NULL;
	

struct node *head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	
	head->data=1;//data
	head->next=first;//link to next node
	
	
	first->data=2;
	first->next=second;
	
	second->data=3;
	second->next=NULL;
	
//	push(head,5);//push at beginning
	push(&head,5);
	print(head);

return 0;
}

