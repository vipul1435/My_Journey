#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000;
class Stack
{
    int top;

public:
    int ar[MAX];
    Stack()
    {
        top = -1;
    }
    bool push(int x);
    int pop();
    int peek();
    bool Isempty();
};
bool Stack::push(int x)
{
    if (top >= (MAX - 1))
    {
        cout << "over flow" << endl;
        return false;
    }
    else
    {
        ar[++top] = x;
        return true;
    }
}
int Stack::pop(){
    if(top<0){
        cout<<"under flow"<<endl;
        return 0;
    }
    else{
        int x = ar[top--];
        return x;
    }
}
int Stack::peek(){
    if(top<0){
        cout<<"stack is empty"<<endl;
        return 0;
    }else {
        int x= ar[top];
        return x;
    }
}
bool Stack::Isempty(){
    if(top<0) return true;
    return false;
}
int main()
{
    class Stack s;
    s.push(10);
    s.push(34);
    s.push(324);
    s.push(314);
    s.push(374);
    s.push(3134);
    s.push(384);

    s.pop();
    s.peek();
    while(!(s.Isempty())){
        cout<<s.peek()<<" ";
        s.pop();
    }
    cout<<endl;
    
}