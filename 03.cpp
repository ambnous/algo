#include<iostream> 
using namespace std; 
  
int getmax(int arr[],int n) 
{ 
    int max=arr[0]; 
    for(int i=1;i<n;i++)
	{ 
        if(arr[i]>max) 
        max=arr[i]; 
    }
    return max; 
} 

void countingsort(int arr[],int n,int exp) 
{ 
    int output[n];  
    int i,count[10]={0};
  
    for(i=0;i<n;i++) 
    count[(arr[i]/exp)%10]++; 
		 
    for(i=1;i<10;i++) 
    count[i]+=count[i-1]; 
 
    for(i=n-1;i>=0;i--) 
    { 
        output[count[(arr[i]/exp)%10]-1]=arr[i]; 
    	count[(arr[i]/exp)%10]--; 
    } 

    for(i=0;i<n;i++) 
    arr[i]=output[i]; 
    
    for(int i=0;i<n;i++) 
    cout<<arr[i]<<" "; 
    
	cout<<"\n\n";
} 
  
void radixsort(int arr[],int n) 
{ 
    int m=getmax(arr,n); 
  
    for (int exp=1;m/exp>0;exp*=10) 
    countingsort(arr,n,exp); 
} 
  
int main() 
{ 
    int n;
    cout<<"Enter size of array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements of array"<<endl;
    for(int i=0;i<n;i++)
    cin>>arr[i];
 
    radixsort(arr,n);  
    return 0; 
} 
