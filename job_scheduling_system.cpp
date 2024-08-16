#include <iostream>
using namespace std;
class Node
{
public:
    string name;
    int task,id,count1=0;
    Node*temp;
    Node*prev;
    Node(string n,int t,int i)
    {
        name=n;
        task=t;
        id=i;
        count1=0;
        temp=NULL;
    }
};
void no_of_turn(Node*head,int sum)
{
    int i=1,count1=1;
    Node*list1=head;
    Node*curr=head;
    do
    {
        if(head->task!=0)
        {
            cout<<"Turn"<<i<<":"<<" "<<"Task of"<<" "<<head->id<<endl;
            i++;
            int d=head->task;
            d--;
            head->task=d;
        }
        else
        {
            head->count1=count1;
            count1++;
        }
        head=head->temp;
    }
    while(i!=sum+1);
    do
    {
        if(list1->count1==1)
        {
            cout<<"First completed task:"<<list1->id<<endl;
            break;
        }
        list1=list1->temp;
    }
    while(list1!=curr);
}
int main()
{
    int j, i,n,id,task,sum=0;
    string name;
    Node* head = NULL;
    Node* current = NULL;
    cout << "Enter the number of elements: ";
    cin >> j;
    for (i = 0; i < j; i++)
    {
        cout<<"Enter the id ,name and no of tasks:";

        cin >>id>>name>>n ;
        if (head == NULL)
        {
            head = new Node(name,n,id);
            current = head;
        }
        else
        {
            current->temp = new Node(name,n,id);
            current->prev=current->temp;
            current = current->temp;
        }
        sum+=n;
    }
    current->temp=head;
    no_of_turn(head,sum);
}

