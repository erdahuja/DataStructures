//
// Created by Deepak Ahuja on 30/09/16.
//

// A Stack based C program to find next greater element
// for all array elements.
#include<iostream>
#include<stdlib.h>
#define STACKSIZE 100
using namespace std;
// stack structure
struct stack
{
    int top;
    int items[STACKSIZE];
};

// Stack Functions to be used by printNGE()
void push(struct stack *ps, int x)
{
    if (ps->top == STACKSIZE-1)
    {
        printf("Error: stack overflow\n");
        getchar();
        exit(0);
    }
    else
    {
        ps->top += 1;
        int top = ps->top;
        ps->items [top] = x;
    }
}

bool isEmpty(struct stack *ps)
{
    return (ps->top == -1)? true : false;
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
    int i=0;
    struct stack s;
    s.top=-1;
    int next;
    int element;

    push(&s,arr[0]);

    for(int i=1;i<n;i++) {
        next = arr[i];

        if (!isEmpty(&s)) {
            element = pop(&s);

            while (element < next) {

                cout << "NGE of element " << element << " is " << next << endl;
                if (isEmpty(&s))
                    break;

                element = pop(&s);

            }

            if (element > next)
                push(&s, element);


        }

        push(&s, next);
    }

    while(!isEmpty(&s)){
        element=pop(&s);
        cout<<"NGE of element "<<element<<" is "<<"-1"<<endl;

    }


}

int main()
{
    int arr[]= {11, 13, 21, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printNGE(arr, n);
    getchar();
    return 0;
}