#include <stdio.h>
#include <conio.h>
int main()
{
	int a[100],key,n,i,r;
	int search(int a[],int n,int key);
	//input
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	printf("enter the elments\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the element u want to search\n ");
	scanf("%d",&key);
	r=search(a,n,key);
	if(r==n)
	printf("element not found\n");
	else
	printf("\n element found at the position %d",r+1);
	getch();
	return 0;
}
//search using function
int search(int a[],int n,int key)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(key==a[i])
		{
			break;
		}
	}
	return i;
}

