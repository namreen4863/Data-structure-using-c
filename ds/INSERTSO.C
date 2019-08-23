#include<stdio.h>
#include<conio.h>
void main()
{
int a[20],i,k,n,x;
clrscr();
//input
printf("enter no of element");
scanf("%d",&n);
printf("enter elements\n");
for(i=0;i<n;i++)
{
scanf("%d",&a[i]);
}
//sorting
for(k=1;k<n;k++)
{
x=a[k];
i=k-1;
while(i>=0 && a[i]>x)
{
a[i+1]=a[i];
i=i-1;
}
a[i+1]=x;
}
//output
printf("the sorted elements\n");
for(i=0;i<n;i++)
{
printf("%d",a[i]);
}
getch();
}







