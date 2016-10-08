//
// Created by Deepak Ahuja on 30/09/16.
//

#include <iostream>

using namespace std;

struct TwoStack{


    int top1;
    int top2;

    unsigned capacity;
    int* array;

};

void push1(TwoStack* twoStack,int data){

    if(twoStack->top2-twoStack->top1>1) {
        twoStack->array[++twoStack->top1] = data;
        cout<<"added "<<data<<" top is "<<twoStack->top1<<"\n";
    }else
    {

        cout<<"stack overflow...";
        return;
    }

}

void push2(TwoStack* twoStack,int data){

    if(twoStack->top2-twoStack->top1>1){

        twoStack->array[--twoStack->top2]=data;
        cout<<"added "<<data<<" top is "<<twoStack->top2<<"\n";
    }
    else
    {

        cout<<"stack overflow...";
        return;
    }

}

int pop1(TwoStack* stack){

    if(stack->top1>=0){
        int x=stack->array[stack->top1];
        stack->top1--;
        return x;

    }
    else{

        cout<<"underflow 1";
    }

}

int pop2(TwoStack* stack){

    if(stack->top2<stack->capacity){
        int x=stack->array[stack->top2];
        stack->top2++;
        return x;

    }
    else{

        cout<<"underflow 2";
    }



}

TwoStack* createStack(int capacity){

    TwoStack* twostack=(TwoStack*)malloc(sizeof(TwoStack));
    twostack->capacity=capacity;
    twostack->top1=-1;
    twostack->top2=capacity;
    twostack->array=(int*)malloc(capacity* sizeof(int));

    return twostack;
}



int main(){
    TwoStack* twoStack=createStack(10);


    push1(twoStack,1);
    push1(twoStack,2);
    push1(twoStack,3);
    push1(twoStack,4);

    push1(twoStack,5);
    push1(twoStack,6);
    push1(twoStack,7);

    push1(twoStack,81);

    push2(twoStack,92);
    push2(twoStack,82);
    push2(twoStack,72);



    return 0;
}