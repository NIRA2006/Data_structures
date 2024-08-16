#include<iostream>
#include<string>
using namespace std;

struct employee
{
    string name;
    int id;
    float salary;
};

class Stack
{
private:
    static const int n=100;
    employee arr[n];
    int top;

public:
    Stack()
    {
        top=-1;
    }
    void push(employee emp)
    {
        if(top>=n-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=emp;
    }

    void print()
    {
        if(top<0)
        {
            cout<<"Stack is empty:";
            return;
        }
        for(int i=top; i>=0; i--)
        {

            cout<<"NAME:"<<arr[i].name<<"\nID:"<<arr[i].id<<"\nSALARY:"<<arr[i].salary;
        }
    }
    employee peek()
    {
        if(top<0)
        {
            cout<<"Stack is empty:";

        }
        return arr[top];
    }
    employee pop()
    {
        if(top<0)
        {
            cout<<"Stack is empty:";

        }
        return arr[top--];
    }
};
int main()
{
    Stack stack;

    employee emp1= {"Edward",1,2000};
    employee emp2= {"Jack",2,3000};
    employee emp3= {"Richard",1,4000};

    stack.push(emp1);
    stack.push(emp2);
    stack.push(emp3);

    cout<<"Printing the stack:";
    stack.print();
    cout<<endl;

    employee topemp=stack.peek();
    cout<<"Topemployee:NAME:"<<topemp.name<<"\nID:"<<topemp.id<<"\nSALARY:"<<topemp.salary; cout<<endl;

        employee popemp=stack.pop();

    cout<<"Popped employee:NAME:"<<popemp.name<<"\nID:"<<popemp.id<<"\nSALARY:"<<popemp.salary;
    cout<<endl;

    cout<<"Printing the stack after popping:";
    stack.print();
    cout<<endl;


}

