#include <bits/stdc++.h>
using namespace std;

int size = 8;
void SSTF(int arr[], int head)
{
    int sum = 0;
    int arr2[size]={0};
    int num = -1;
    int ind = -1;
	
	for(int i = 0 ;i <size ; i++){
	       for(int j = 0 ; j<size ; j++)
           {
                if(arr2[j]!=1)
                {
                    if(abs(arr[j]-head)<=abs(num-head) || num==-1)
                    {
                        num = arr[j];
                        ind = j;
                        
                        }
                    }
	        }
	    sum+=abs(num-head);
	    if(i==0){
	        cout<<"The sequence is "<<endl;
	        cout<<endl;
	    }
	    cout<<head<<endl;
	    head = arr[ind];
	    num=-1;
	    arr2[ind]=1;


	}
	cout<<endl;
	cout<<"Seek time is : "<<sum;
}

int main()
{
    int head = 50;
    int arr[size] = { 176,79,34,60,92,11,41,114 };
	SSTF(arr, head);
	return 0;
}
