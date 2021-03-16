#include<stdio.h>
#include<conio.h>
int smallest(int a[],int n,int k);
void selection_sort(int a[],int n);
void main()
{
	int a[50];
	int n,i;
	printf("ENTER THE NUMBER OF ELEMENTS\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("ENTER a[%d]= \n",i);
		scanf("%d",&a[i]);
	}
	selection_sort(a,n);
	printf("SORTED ARRAY IS\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);
	}
	getch();
}

void selection_sort(int a[],int n)
{
	int k,pos,temp;
	for(k=0;k<n;k++)
	{
		pos=smallest(a,n,k);
		temp=a[k];
		a[k]=a[pos];
		a[pos]=temp;
	}
}

int smallest(int a[],int n,int k)
{
	int i;
	int pos=k;
	int small=a[k];
	for(i=k+1;i<n;i++)
	{
		if(a[i]<small)
		{
			small=a[i];
			pos=i;
		}
	}
	return pos;
}
