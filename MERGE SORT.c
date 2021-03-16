#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define MAX 100

//DECLARATION
int a[MAX];
void merge(int a[],int beg,int mid,int end);
void merge_sort(int a[],int beg,int end);

int main()
{
	int i,n;
	
	//TAKING INPUTS
	printf("ENTER THE NUMBER OF ELEMENTS\n");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	{
		printf("ENTER a[%d] = ",i);
		scanf("%d",&a[i]);
	}	
	
	//CALLING MERGE SORT FUNCTION
	merge_sort(a,0,n-1);
	
	//DISPLAY OF SORTED ARRAY
	printf("SORTED ARRAY IS:\n");
	for(i=0;i<n;i++)
	{
		printf("a[%d]=%d\n",i,a[i]);
	}
	
	
	return 0;
}


//CONQUER 
void merge(int a[],int beg,int mid,int end)
{
	int i=beg;
	int j=mid+1;
	int temp[MAX];
	int index=beg;
	int k;
	
	
	/*COPYING SMALLEST TO THE BIGGEST ELEMENT IN NEW TEMPORARY ARRARY
	TILL THIS WHILE LOOP CONDITION IS SATISFIED*/
	while((i<=mid)&&(j<=end))
	{
		if(a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
		}
		if(a[i]>a[j])
		{
			temp[index]=a[j];
			j++;
		}
		index++;
	}
	
	/*COPYING THE REMAINNING ELEMENTS TO THE TEMPORARY ARRAY*/
	if(i>mid)
	{
		while(j<=end)
		{
			temp[index]=a[j];
			j++;
			index++;
		}
	}
	
	
	else
	{
		while(i<=mid)
		{
			temp[index]=a[i];
			i++;
			index++;
		}
	}
	
	//COPING ALL THE SORTED ELEMENT FROM TEMPORARY ARRAY TO THE MAIN ARRAY
	for(k=beg;k<index;k++)
	{
		a[k]=temp[k];
	}
	
	
}


//DIVIDE
void merge_sort(int a[],int beg,int end)
{
	int mid;
	
	//BREAKING THE ARRAY INTO SINGLE SINGLE ELEMENT
	if(beg<end)
	{
		mid = (beg+end)/2;
		//USING RECURSION CONCEPT TO BREAK ARRAY
		
		//BREAKING LEFT SUB ARRAY
		merge_sort(a,beg ,mid);
		
		//BREAKING RIGHT SUB ARRAY
		merge_sort(a,mid+1,end);
		
		//CALL FOR CONQUER
		merge(a,beg,mid,end);
		
	}
	
}

