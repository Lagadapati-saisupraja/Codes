#include<stdio.h>
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
void Maxheapify(int arr[],int n,int i)
{
	int largest=i;
	int l=(2*i);
	int r=(2*i)+1;
	while(l<n && arr[l]>arr[largest])
	{
		largest=l;
	}
	while(r<n && arr[r]>arr[largest])
	{
		largest=r;
	}
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		Maxheapify(arr,n,largest);
	}
}
void heapsort(int arr[],int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		Maxheapify(arr,n,i);
	}
	for(i=n;i>=1;i--)
	{
		swap(&arr[1],&arr[i]);
		Maxheapify(arr,i,1);
	}
}
void printarray(int arr[],int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d ",arr[i]);
	}
}
int main()
{
	int i,n;
	printf("enter the size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of array:");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
	}
	heapsort(arr,n);
	printf("sorted array:\n");
	printarray(arr,n);
	return 0;
}
