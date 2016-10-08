//
// Created by Deepak Ahuja on 29/09/16.
//

//postfix evaluation


#include <iostream>

using namespace std;


struct Stack{

    int top;
    unsigned capacity;
    int* array;

};

Stack* createStack(int capacity){

    Stack* stack=(Stack*)malloc(sizeof(Stack));
    stack->top=-1;
    stack->capacity=capacity;
    stack->array=(int*)malloc(capacity*sizeof(int));
    return stack;


}


bool  isFull(Stack* stack){

    return (stack->top==stack->capacity-1);


}

bool  isEmpty(Stack* stack){

    if(stack->top==-1)
        return true;
    else
        return false;

}



void  push(Stack* stack,char data){


    if(isFull(stack)){
        cout<<"stack full ";
        return;
    }
    else {
        stack->array[++stack->top] = data;

    }


}

char pop(Stack* stack){


    if(!isEmpty(stack))
    {

        return stack->array[stack->top--];



    } else
        return -1;
}
int performOperation(char operation, int operand1, int operand2)
{


    if(operation == '+') return operand1 +operand2;
    else if(operation == '-') return operand1 - operand2;
    else if(operation == '*') return operand1 * operand2;
    else if(operation == '/') return operand1 / operand2;

    else cout<<"Unexpected Error \n";
    return -1;
}

int postfixEvaluation(char string[]){
    Stack* stack=createStack(strlen(string));

    for(int i=0;i<strlen(string);i++){
        if(string[i]=='+'||string[i]=='-'||string[i]=='/'||string[i]=='*'){


            int res=performOperation(string[i],stack->array[stack->top-1],stack->array[stack->top]);

            pop(stack);
            pop(stack);
            push(stack,res);



        }
        else if(string[i]>='0'&&string[i]<='9'){

            push(stack,string[i]-'0');
        }



    }

    return stack->array[stack->top];


}


int main() {

    char string[100];
    cout << "enter postfix expression to evaluate ";
    cin >> string;
    cout << postfixEvaluation(string);


    return 0;

}
