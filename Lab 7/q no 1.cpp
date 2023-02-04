#include <iostream>
using namespace std;
#include <cstdlib>

void Fcfs(int arr[],int n,int head){
    int sum=0;
    for(int i =0 ; i<n ; i++){
        sum+=abs(arr[i]-head);
        head = arr[i];
   }
   cout<<endl;
   cout<<endl;
   cout<<"The seek time is : "<< sum<<endl;
}

int main()
{
    int n;
    int head=50;
    int arr[n]={0};
    cout<<"Enter the number of sequence : ";
    cin>>n;

    for(int i=0; i<n ; i++){
        cout<<"Enter "<<"sequence " << i + 1 << ": ";
        cin>>arr[i];
    }
    
    Fcfs(arr,n,head);
    
    return 0;
}
