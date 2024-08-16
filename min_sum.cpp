#include<iostream>
using namespace std;
int main()
{
    int arr[]={4,6,2,1,7,8},temp=0,sum=0;
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if (arr[i]<arr[j])
            {
                swap(arr[i],arr[j]);
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    for(int i=0; i<n/2; i++)
    {
        sum+=arr[i]*arr[n-i-1];
    }
    cout<<"\nMinimum sum:"<<sum;
    return 0;
}
