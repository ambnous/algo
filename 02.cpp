#include<iostream>
using namespace std;

int c;

void maxheapify(int a[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	
	if(l<n)
	{
		c++;
		if(a[l]>a[largest])
		{
			largest=l;
		}
	}
	
	if(r<n)
	{
		c++;
		if(a[r]>a[largest])
		{
			largest=r;
		}
	}
	
	if(largest!=i)
	{
		int temp=a[i];
		a[i]=a[largest];
		a[largest]=temp;
		maxheapify(a,n,largest);
	}
	cout<<"Number of comparisons: "<<c<<endl;
}

void heapsort(int a[],int n)
{
	for(int i=n/2-1; i>=0;i--)
	maxheapify(a,n,i);

	for(int i=n-1;i>=0;i--)
	{
		int temp=a[0];
		a[0]=a[i];
		a[i]=temp;
		maxheapify(a,i,0);
	}
}

void display(int a[],int n)
{
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
}

int main()
{
	int n;
	cout<<"Enter size of heap"<<endl;
	cin>>n;
	int arr[n];
	cout<<"Enter elements of heap"<<endl;
	for(int i=0;i<n;i++)
	cin>>arr[i];
	
	heapsort(arr,n);
	
	cout<<"Sorted array: ";
	display(arr,n); 

	return 0;
}

