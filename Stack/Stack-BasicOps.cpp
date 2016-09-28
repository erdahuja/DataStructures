#include <iostream>

using namespace std;

struct Stack{

    int top;
    unsigned capacity;
    int* array;

};


Stack* createStack(int capacity){

    Stack*  stack=(Stack*)malloc(sizeof(Stack));

    stack->capacity=capacity;
    stack->top=-1;

    stack->array=(int*)malloc(capacity*sizeof(int));
    return stack ;
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



void  push(Stack* stack,int data){
    if(isFull(stack)){
        return;
    }
    else

        stack->array[++stack->top]=data;
    cout<<"added "<<data<<" top is "<<stack->top<<"\n";


}

void pop(Stack* stack){

    if(!isEmpty(stack))
    {
        stack->array[stack->top--];
        cout<<"popped "<<"top is "<<stack->top;

    } else
        cout<<"can't pop...\n";
}





int main() {
    Stack* stack=createStack(100);

    push(stack,1);
    push(stack,2);
    push(stack,2);
    cout<<"popping...\n";
    pop(stack);




    return 0;
}