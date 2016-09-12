
//Delete a node in LL
//delete  by key
//go to n-1th node and link it to n+1th node .

#include <iostream>
#include <cstdlib>

using namespace std;

	struct node* head = NULL;
struct node
{
    int data;
    struct node *next;
};



void printList(struct node *n)
{
	cout<<endl;
    while (n != NULL)
    {
        cout<<n->data<<" ";
        n = n->next;
    }
    cout<<endl;
}

void push(struct node** head_ref, int new_data)
{
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);
    (*head_ref)    = new_node;
}

//delete function
void deleteANode(int key){
	
	struct node* temp=head;
	struct node *prev;
	if(temp==NULL)
	return;
	
	if(temp!=NULL&&temp->data==key){ //if to delete head node itself
		head=temp->next;
		free(temp);
		return;
	}
	
	while(temp!=NULL&&temp->data!=key){
	prev=temp;
	temp=temp->next;
	
	
	}
	prev->next = temp->next;
	free(temp);
	
	}




int main(){
	cout<<"Linked List Deletion "<<endl;

 
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
 
    cout<<"Created Linked List: "<<endl;
    printList(head);
    
    cout<<"enter position to delete :"<<endl;
	int x;
	cin>>x;
	deleteANode(x);
	 printList(head);
	 
	return 0;}

