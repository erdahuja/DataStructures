//trasverse and insert node at a given position

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

void pushAfter(node *prev,int data){  //can't pass head as it is actually a copy of head of LL
	
	if(prev==NULL){
	cout<<"\nempty!";
	}
		
	struct node *nw=(struct node*)malloc(sizeof(struct node));
	nw->data=data;
	nw->next=prev->next;
	
	prev->next=nw;
	
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
	
	
	pushAfter(second,9);
	print(head);
return 0;
}


