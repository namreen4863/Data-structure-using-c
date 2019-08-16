#include<stdio.h>
#include<conio.h>
int main()
{
	int i,j,a[100],temp,n;
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	printf("enter the elements");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//sorting
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("sorted elements in descending order are\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
}
