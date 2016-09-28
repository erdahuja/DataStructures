//
// Created by Deepak Ahuja on 28/09/16.
//


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
    stack->capacity=capacity;
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
        cout<<"stack full ";
        return;
    }
    else {
        stack->array[++stack->top] = data;
        cout << "added " << data << "\n";
    }


}

char pop(Stack* stack){


    if(!isEmpty(stack))
    {
        cout<<"popped "<<"\n";
        return stack->array[stack->top--];



    } else
        return -1;
}


bool isMatchedParanthesis(char opening,char closing){

cout<<"matching "<<opening<<" "<<closing<<endl;
    if(opening == '(' && closing == ')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;
    return false;


}
bool checkBalancedParanthesis(char string[]){


    Stack* stack=createStack(strlen(string));

    int i=0;
    while(string[i]){

        cout<<"Scanning "<<string[i]<<"\n";

        if(string[i]=='{'||string[i]=='('||string[i]=='['){

            push(stack,string[i]);


        }
        else if(string[i]=='}'||string[i]==']'||string[i]==')')
        {
            if(isEmpty(stack)){
                cout<<"stack empty...";
                return false;
            }

            if(isMatchedParanthesis(stack->array[stack->top],string[i])){
                cout<<"matched "<<"\n";
                pop(stack);

            }

        }
        i++;
    }

    return isEmpty(stack);



}



int main() {

    char string[100];
    cout<<"enter string of paranthesis to check ";
    cin>>string;
    if(checkBalancedParanthesis(string)){
        cout<<"true";

    }else

        cout<<"false";


    return 0;
}