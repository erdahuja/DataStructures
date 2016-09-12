//insert at the end.
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
void append(struct node* head,int data){
	
	struct node* last=head;//copy of head to traverse.
	
	struct node *nw=(struct node*)malloc(sizeof(struct node));
	
	
	nw->data=data;
	nw->next=NULL;
	
	while (last->next != NULL)
        last = last->next;
	
	last->next=nw;
	
	

}
int main(){ 

cout<<"Linked List traverse";
	struct node *head=NULL;
	struct node *first=NULL;
	struct node *second=NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	first=(struct node*)malloc(sizeof(struct node));
	second=(struct node*)malloc(sizeof(struct node));
	
	head->data=1;//data
	head->next=first;//link to next node
	
	
	first->data=2;
	first->next=second;
	
	second->data=3;
	second->next=NULL;
	
	append(head,9);
	print(head);
return 0;
}
