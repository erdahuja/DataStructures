//
// Created by Deepak Ahuja on 30/09/16.
//
/*

Given an array,
 print the Next Greater Element (NGE) for every element.
 The Next greater Element for an element x is the first greater element on the right side of x in array.
 Elements for which no greater element exist, consider next greater element as -1.*/


#include <iostream>
#define STACKSIZE 100
using namespace std;

struct stack{
    int top;
    int items[STACKSIZE];

};

void push(struct stack* ps,int x){

    if(ps->top==STACKSIZE-1){

        cout<<"Error : stack overflow";
        return;
    }
    else
    {
        ps->top++;
        int top=ps->top;
        ps->items[top]=x;
    }

}

bool isEmpty(struct stack* ps){

    return (ps->top==-1)?true: false;
}

int pop(struct stack *ps)
{
    int temp;
    if (ps->top == -1)
    {
        printf("Error: stack underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        int top = ps->top;
        temp = ps->items [top];
        ps->top -= 1;
        return temp;
    }
}


/* prints element and NGE pair for all elements of
arr[] of size n */
void printNGE(int arr[], int n)
{




    /* push the first element to stack */


    // iterate for rest of the elements






    // if stack is not empty, then pop an element from stack


    /* If the popped element is smaller than next, then
        a) print the pair
        b) keep popping while elements are smaller and
        stack is not empty */


    /* If element is greater than next, then push
       the element back */

    /* push next to stack so that we can find
       next greater for it */

}

/* After iterating over the loop, the remaining
   elements in stack do not have the next greater
   element, so print -1 for them */

}




int pop(struct stack *ps)
{
    int temp;
    if (ps->top == -1)
    {
        printf("Error: stack underflow \n");
        getchar();
        exit(0);
    }
    else
    {
        int top = ps->top;
        temp = ps->items [top];
        ps->top -= 1;
        return temp;
    }
}