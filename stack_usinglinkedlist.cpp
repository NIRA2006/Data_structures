#include <iostream>
#include <string>
using namespace std;
struct Student
{
    string name;
    int id;
    double gpa;
    Student* next;
};
class Stack
{
private:

    Student* top;
public:
    Stack()
    {
        top = NULL;
    }

    void push(const string& name, int id, double gpa)
    {
        Student* newStudent = new Student{name, id, gpa, top};
        top = newStudent;
    }
    void pop()
    {
        if (top == NULL)
        {
            cout << "Stack Underflow" << endl;
            return;
        }
        Student* temp = top;
        top = top->next;
        delete temp;
    }
    Student* peek() const
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return NULL;
        }
        return top;
    }
    void print() const
    {
        if (top == NULL)
        {
            cout << "Stack is Empty" << endl;
            return;
        }
        Student* current = top;
        while (current != NULL)
        {
            cout << "Name: " << current->name << ", ID: " << current->id << ", GPA: " << current->gpa << endl;
            current = current->next;
        }
    }
};

int main()
{
    Stack stack;

    stack.push("Alice Johnson", 1, 3.5);
    stack.push("Bob Smith", 2, 3.7);
    stack.push("Carol White", 3, 3.9);
    cout << "Stack contents after pushing 3 students:" << endl;
    stack.print();
    cout << endl;
    Student* topStudent = stack.peek();
    if (topStudent != NULL)
    {
        cout << "Top student: Name: " << topStudent->name << ", ID: " << topStudent->id << ", GPA: " << topStudent->gpa << endl;
    }
    cout << endl;
    stack.pop();
    cout << "Stack contents after popping 1 student:" << endl;
    stack.print();

    return 0;
}

