#include <stdio.h>
#include <conio.h>
void bubblesort(int a[],int n)

{
	int i=0,j=0,t;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
		if(a[j]>a[j+1])
		{
			t=a[j];
			a[j]=a[j+1];
			a[j+1]=t;
		}
				
		}
	}
}
int binarysearch(int a[],int size,int search)
{
	int mid;
	int start=0;
	int end=size-1;
	while(start<=end)
	{
		mid=(start+end)/2;
		if(a[mid]==search)
		return mid;
		else if(a[mid]<search)
		start=mid+1;
		else
		end=mid-1;
	}
	return -1;
}
int main()
{
	int a[50];
	int size,i,search,result;
	//Ask for size of array
	printf("Enter the size of array:");
	scanf("%d",&size);
	//Accept values from user
	printf("enter the element\n");
	for(i=0;i<size;i++)
	{
		scanf("%d",&a[i]);
	}
	//Sort the array
	bubblesort(a,size);
	//Search for value in array
	printf("enter the element to search\n");
	scanf("%d",&search);
	result=binarysearch(a,size,search);
	if(result==-1)
	printf("%d not found\n",search);
	else
	printf("%d found at offset %d\n",search,result);
	return 0;
}
