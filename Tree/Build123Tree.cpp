    //
    // Created by Deepak Ahuja on 13/09/16.
    //

    #include <iostream>
    using namespace std;

    struct node{

        int data;
        node* left;
        node* right;
    };


    node* newNode(int data){

        node* current=new node();
        current->left=NULL;
        current->right=NULL;
        current->data=data;

        return current;

    }

    int main() {
        cout<<"Basic tree creation : ";
        node* firstNode=newNode(1);
        node* secNode=newNode(2);
        node* thirdNode=newNode(3);

        cout<<"the tree is : \n";
        cout<<firstNode->data<<endl;
        cout<<"/"<<"\\"<<endl;
        cout<<secNode->data<<"  ";

            cout<<thirdNode->data<<endl;


        return 0;
    }