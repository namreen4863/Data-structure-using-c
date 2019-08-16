#include <stdio.h>
#include <conio.h>
int main()
{
	int a[100],n,i,temp,j;
	//input
	printf("enter the no. of elements\n");
	scanf("%d",&n);
	printf("enter the element");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	//sorting
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	//output
	printf("sorted elements are\n");
	for(i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	getch();
	return 0;
}
