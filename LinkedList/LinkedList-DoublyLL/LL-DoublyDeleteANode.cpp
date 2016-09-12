
#include <stdlib.h>
	#include <iostream>
	#include <stdio.h>
	
	using namespace std;
	struct node{
	
	node *prev;
	node *next;
	int data;
	
	};

//get new node

	
	node* getNode(int x){

		node *curr=(struct node*)malloc(sizeof(struct node));

	curr->data=x;
	curr->prev=NULL;
	curr->next=NULL;
	return curr;

	}
void printList(struct node *node)
{

  while(node!=NULL)
  {
   printf("%d ", node->data);
   node = node->next;
   
  }
}


//delete function
void deleteNode(node** head,node* del){

if(*head==NULL||del==NULL){
return ;

}

if(*head==del){

*head=del->next;
	}

if(del->prev != NULL)
    del->prev->next = del->next; 



  if(del->next != NULL){
    del->next->prev = del->prev;
  }
	free(del);
	return ;

	}

 node* push(node* head,int data){

node* temp=getNode(data);

temp->prev=NULL;

if(head!=NULL)
head->prev=temp;

temp->next=head;

head=temp;

return head;
	 }

int main(){
node* head=NULL;

head=push(head,3);
head=push(head,2);
head=push(head,1);

cout<<"b4 deletion :"<<endl;
printList(head);

deleteNode(&head,head);
cout<<"\nafter deleteion :"<<endl;

printList(head);

	return 0;
	}
