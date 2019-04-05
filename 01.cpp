#include<iostream>
using namespace std;

void bubblesort(int arr[],int n)
{
	int i,j,c=0;
	bool flag=false;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			c++;
			if(arr[j]>arr[j+1])
			{
				flag=true;
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
		if(flag==false)
		break;
	}
	cout<<"Sorted array: ";
	for(i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Number of comparisons: "<<c<<endl;
}

void selectionsort(int arr[],int n)
{
	int min=0,j,temp,c=0;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(j=i+1;j<n;j++)
		{
			c++;
			if(arr[min]>arr[j])
			min=j;
		}

		if(min!=i)
		{
			temp=arr[min];
			arr[min]=arr[i];
			arr[i]=temp;
		}
	}
	cout<<"Sorted array: ";
	for(int i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Number of comparisons: "<<c<<endl;
}

void insertionsort(int arr[],int n)
{
	int i,j,x,c=0;
	for(i=1;i<n;i++)
	{
		j=i-1;
		x=arr[i];
		while(j>=0)
		{
			if(arr[j]>x)
			{
				c++;
				arr[j+1]=arr[j];
				j--;
			}
			else
			{
				c++;
				break;
			}
		}
		arr[j+1]=x;
	}
	cout<<"Sorted array: ";
	for(i=0;i<n;i++)
	cout<<arr[i]<<" ";
	cout<<endl;
	cout<<"Number of comparisons: "<<c<<endl;
}

int partition(int a[],int l,int r)
{
	int pivot=a[r];
	int i=l-1;
	int temp;
	int c=0;

	for(int j=l;j<r;j++)
	{
		c++;
		if(a[j]<=pivot)
		{
			i++;

			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	

	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	
	cout<<"Number of comparisons: "<<c<<endl;

	return i+1;
}

void quicksort(int a[],int l,int r)
{
	if(l<r)
	{
		int pi=partition(a,l,r);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,r);
	}
}

int merge(int a[],int l,int m,int r)
{
	int i,j,k,c=0;
	int n1=m-l+1;
	int n2=r-m;

	int L[n1],R[n2];

	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	R[j]=a[m+1+j];

	i=0,j=0,k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=R[j])
		{
			c++;
			a[k]=L[i++];
		}
		else
		{
			c++;
			a[k]=R[j++];
		}

		k++;
	}

	while(i<n1)
	{
		a[k]=L[i++];
		k++;
	}

	while(j<n2)
	{
		a[k]=R[j++];
		k++;
	}
	
	cout<<"Number of comparisons: "<<c<<endl;
}

void mergesort(int a[],int l,int r)
{
	if(l<r)
	{
		int m=(r+l)/2;
		
		mergesort(a,l,m);
		mergesort(a,m+1,r);
		
		merge(a,l,m,r);
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
	int n,ch;

	do
	{
		cout<<"\n*****MENU*****"<<endl;
		cout<<"1.Bubble Sort"<<endl;
		cout<<"2.Selection Sort"<<endl;
		cout<<"3.Insertion Sort"<<endl;
		cout<<"4.Quick Sort"<<endl;
		cout<<"5.Merge Sort"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>ch;

		cout<<"Enter size of array"<<endl;
		cin>>n;
		int a[n];
		cout<<"Enter elements of array"<<endl;
		for(int i=0;i<n;i++)
		cin>>a[i];

		switch(ch)
		{
			case 1: bubblesort(a,n);
				break;
			case 2: selectionsort(a,n);
				break;
			case 3: insertionsort(a,n);
				break;
			case 4: quicksort(a,0,n-1);
				cout<<"Sorted array: ";
				display(a,n);
				break;
			case 5: mergesort(a,0,n-1);
				cout<<"Sorted array: ";
				display(a,n);
				break;
			default:cout<<"Invalid choice"<<endl;
		}
	}
	while(ch>0 && ch<=5);
	return 0;
}
