//
// Created by Deepak Ahuja on 28/09/16.
//

//Reverse a string with a separate stack. and also by swaping data ir without extra stack.

#include <iostream>

using namespace std;


struct Stack{

    int top;
    unsigned capacity;
    char* array;

};

Stack* createStack(int capacity){

    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->array=(char*)malloc(capacity*sizeof(char));
    return stack;


}


bool  isFull(Stack* stack){
    if(stack->top==stack->capacity-1)
        return true;
    else
        return false;

}

bool  isEmpty(Stack* stack){
    if(stack->top==-1)
        return true;
    else
        return false;

}



void  push(Stack* stack,char data){
    if(isFull(stack)){
        return;
    }
    else

        stack->array[++stack->top]=data;
    cout<<"added "<<data<<" top is "<<stack->top<<"\n";


}

char pop(Stack* stack){


    if(!isEmpty(stack))
    {
        cout<<"popped "<<"prev top is "<<stack->top<<"\n";
        return stack->array[stack->top--];



    } else
        return -1;
}


/*void reverse(char string[]){

    Stack* stack=createStack(strlen(string));
    for(int i=0;i<strlen(string);i++){
        push(stack,string[i]);

    }

    for(int i=0;i<strlen(string);i++){
        string[i]=pop(stack);

    }

}*/


void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

// A stack based function to reverese a string
void reverse(char str[])
{
    // get size of string
    int n = strlen(str), i;

    for (i = 0; i < n/2; i++)
        swap(&str[i], &str[n-i-1]);
}

int main() {
    Stack* stack=createStack(100);

    char string[]="HELLO";
    cout<<string<<"\n";
    reverse(string);

    cout<<string;


    return 0;
}