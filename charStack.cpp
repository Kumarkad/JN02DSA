/*

Program to demonstrte Character Stack

*/

#include <iostream>
#define SIZE 10
using namespace std;

class Stack{
    char data[SIZE];
    int top;
    
    public:
    Stack()
    {
        top=-1;
    }
    void push(char element){
        if (isFull()==1)
            cout<<"Stack is full !!!";
        else
            data[++top]=element;
    }
    
    char pop(){
        if (isEmpty()==1)
            return -1;
        else
            return data[top--];
    }
     int isEmpty(){
        if (top==-1)
            return 1;
        else
            return 0;
    }
    int isFull(){
        if (top==SIZE-1)
            return 1;
        else
            return 0;
    }
    int peek(){
        if (isEmpty()==1)
            return -1;
        return data[top];
    }
 
};
   int getPrecedence(char ch)
    {
        if(ch =='^')
            return 3;
        else if (ch=='*' || ch=='/')
            return 2;
        else if (ch=='+'|| ch=='-')
            return 1;
        else
            return 0;
    }
    bool isOperator(char ch)
    {
        if (ch=='+' || ch=='-' || ch=='/' || ch=='*' || ch=='^')
            return true;
        else
            return false;

    }
    
int main()
{
    cout<<"------ Infix to Postfix ------"<<endl;
    Stack st;

    char infix[20],postfix[20];
    int j=0;

    cout<<"Enter the Infix expression : ";
    cin>>infix;

    cout<<"\nInfix :"<<infix;

    
    
    for(int i=0;infix[i]!='\0';i++)
    {
        char symbol=infix[i];
        if(isalpha(symbol) || isdigit(symbol))
            postfix[j]=symbol;
        else if (symbol=='(')
            st.push(symbol);
        else if (symbol==')')
        {
            while(st.peek()!='(')
            {
                postfix[++j]=st.pop();
                st.pop();
            }
            st.pop();

        }
        else{
            while(!st.isEmpty() && getPrecedence(symbol)<=getPrecedence(st.peek())){
                postfix[j++]=st.peek();
                st.pop();
            }
            st.push(symbol);
        }
    }
        /*
        else if(isOperator(symbol))
        {
            if(st.isEmpty()==1)
                st.push(symbol);
            else if (symbol=='(')
                st.push(symbol);
            else if (getPrecedence(symbol)>=getPrecedence(st.peek()))
                st.push(symbol);
            else
            {
                while(getPrecedence(symbol)>=getPrecedence(st.peek()))
                {
                    postfix[j++]=st.pop();
                }
            }
        }

    }*/
    while(!st.isEmpty())
    {
        postfix[j++]=st.pop();
    }
    postfix[j]='\0';
    cout<<"\nThe Postfix expression is : "<<postfix;

    return 0;
}