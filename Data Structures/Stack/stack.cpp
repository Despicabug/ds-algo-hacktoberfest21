//Himanshu Kumar
//https://github.com/HK24-HIMANSHU
#include<bits/stdc++.h>
using namespace std;
#define SIZE 5

// function to push elements in the stack
void push(int *top,int a[]){  
    int item;
    if(*top==SIZE-1){
        cout<<"Stack overflow\n";
    }
    else{
        cout<<"Enter the item\n";
        cin>>item;
        a[++*top]=item;
        a[*top]=item;
    }
}

// function to pop elements out of the stack
void pop(int *top,int a[]){
    if(*top==-1){
        cout<<"Stack is empty";
    }
    else{
        cout<<"Deleted item is"<<a[*top]<<endl;
        *top=*top-1;
    }
}

// function to display elements of the stack
//Time Complexity= O(n)
void display(int top,int a[]){
    int i;
    if(top==-1){
        cout<<"Stack is empty";
    }
    else{
        for(i=top;i>=0;i--){
            cout<<a[i]<<endl;
        }
    }
}
int main(){
    int a[100],ch,top=-1;
    for(;;){
        cout<<"Enter your choice \n 1.Push\n 2.Pop\n 3.Display\n";
        cin>>ch;
        switch(ch){
            case 1: push(&top,a);
            break;
            case 2: pop(&top,a);
            break;
            case 3: display(top,a);
            break;
            default:exit(0);
        }
    }
}