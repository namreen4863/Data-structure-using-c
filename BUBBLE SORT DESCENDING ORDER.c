#include<stdio.h>
#include<conio.h>
int main()
{
	int a[25];
	int i,num,temp,j;
	printf("ENTER THE NUMBER OF ELEMENTS\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("ENTER a[%d]=\n",i);
		scanf("%d",&a[i]);
	}
	for(i=0;i<num;i++)
	{
		for(j=0;j<num-i-1;j++)
		{
			if(a[j]<a[j+1])
			{
			  temp=a[j];
			  a[j]=a[j+1];
			  a[j+1]=temp;
		    }
		}
	}
	for(i=0;i<num;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);
	}
	return 0;
}
