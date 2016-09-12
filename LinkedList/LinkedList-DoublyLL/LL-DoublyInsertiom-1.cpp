	#include <stdlib.h>
	#include <iostream>
	#include <stdio.h>
	
	using namespace std;
	struct dlink{
	
	dlink *prev;
	dlink *next;
	int info;
	
	};
	
	void display( dlink *node );
	void createList(dlink *node );
	dlink* insertAtBeginning(dlink *node);
	dlink* getNode(int x);
	
	dlink* getNode(int x){

		dlink *curr=(struct dlink*)malloc(sizeof(struct dlink));

	curr->info=x;
	curr->prev=NULL;
	curr->next=NULL;
	return curr;

	}
	

	
	//insert at beginning
	
	dlink* insertAtBeginning(dlink *node){

	int i=0;
	cout<<"\nenter value to be inserted :";
	cin>>i;
	dlink* temp=getNode(i);

	
	if(temp==NULL){
	cout<<"\n oo memory !";
	}

	if(node!=NULL)
	node->prev=temp;

	
temp->next=node;
node=temp;
return node;


	
	
	
	
	}
	
	
	void createList( dlink *node ){
	
	dlink *curr;
	int i=0;
	cout<<"enter the value of %d node :"+i;
	cin>>node->info;
	node->prev=NULL;
	node->next=NULL;
	i++;
	
	cout<<"press n to quit and any other key to continue ";
	fflush(stdin);
	char ch;
	cin>>ch;
	while(ch!='n'){
	curr=(struct dlink*)malloc(sizeof(struct dlink));
	
	if(curr==NULL){
	
	cout<<"\nempty";
	exit(0);
	}
	
	
	node->next=curr;
	curr->prev=node;
	
	node=node->next;
	
	cout<<"\nenter the value of %d node :"+i;
	
	cin>>node->info;
	node->next=NULL;
	
	cout<<"\npress n to quit and any other key to continue   ";
	
	fflush(stdin);
	cin>>ch;
	i++;
	}
	
	
	}
	
	
	void display( dlink *node){
	
	dlink *temp=NULL;
	
	cout<<"\n forward list :";
	while(node!=NULL){
	
	cout<<node->info<<"  ";
	temp=node;
	node=node->next;
	
	}
	
	cout<<"\nbackward list :";
	
	node=temp;
	
	while(node!=NULL){
	
	cout<<node->info<<" ";
	node=node->prev;
	
	}

	
	}
	
	int main(){
	
	struct  dlink *node;
	
	node=(struct dlink *)malloc(sizeof(struct dlink));
	
	if(node==NULL){
	
	cout<<"\nempty";
	exit(0);
	
	}
	
	
	createList(node);
	
	dlink* node2=insertAtBeginning(node);
	
	display(node2);
	
	
	
	
	
	
	return 0;
	}
	
	
