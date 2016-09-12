/* This program swaps the nodes of linked list rather
   than swapping the field from the nodes.*/
 
#include<stdio.h>
#include<stdlib.h>
 
/* A linked list node */
struct node
{
    int data;
    struct node *next;
};


void swapNodes(struct node** head,int a,int b){
	
	if(a==b){
		return;
		}
		
	
	
	
	struct node* prevX=NULL;
	struct node* currX=*head;
	
	while(currX&&currX->data != a){
		prevX=currX;
		currX=currX->next;
		
		}
		
		struct node *prevY = NULL;
		struct node *currY = *head;
   while (currY && currY->data != b)
   {
       prevY = currY;
       currY = currY->next;
   }
   
      // If either x or y is not present, nothing to do
   if (currX == NULL || currY == NULL)
       return;
 
   // If x is not head of linked list
   if (prevX != NULL)
       prevX->next = currY;
   else // Else make y as new head
       *head= currY;  
 
   // If y is not head of linked list
   if (prevY != NULL)
       prevY->next = currX;
   else  // Else make x as new head
       *head = currX;
   
   struct node* temp = currY->next;
   currY->next = currX->next;
   currX->next  = temp;
	
		}




 
 /* Function to add a node at the begining of List */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while(node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Druver program to test above function */
int main()
{
    struct node *start = NULL;
 
    /* The constructed linked list is:
     1->2->3->4->5->6->7 */
    push(&start, 7);
    push(&start, 6);
    push(&start, 5);
    push(&start, 4);
    push(&start, 3);
    push(&start, 2);
    push(&start, 1);
 
    printf("\n Linked list before calling swapNodes() ");
    printList(start);
 
    swapNodes(&start, 4,5);
 
    printf("\n Linked list after calling swapNodes() ");
    printList(start);
 
    return 0;
}
