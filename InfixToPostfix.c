#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<ctype.h>
#define MAX 100

int top=-1;
char st[MAX];
void push(char st[],char);
char pop(char st[]);
int getpriority(char);
void InfixToPostfix(char source[],char target[]);


int main()
{
	char infix[100], postfix[100];
	
	printf("ENTER THE INFIX EXPRESSION\n");
	gets(infix);
	
	strcpy(postfix,"");
	
	InfixToPostfix(infix,postfix);
	
	printf("POSTFIX EXPRESSION IS:\n");
	puts(postfix);
	
	return 0;
}

void push(char st[],char val)
{
	
	if(top==MAX-1)
	{
		printf("STACK OVERFLOW\n");
	}
	
	else
	{
		top++;
		st[top]=val;
	}
	
}

char pop(char st[])
{
	char val=' ';
	
	if(top==-1)
	{
		printf("STACK IS IN UNDERFLOW CONDITION\n");
	}
	
	else
	{
		val=st[top];
		top--;
	}
	
	return val;
	
}

int getpriority(char op)
{
	
	if(op=='/'||op=='*'||op=='%')
	{
		return 1;
	}
	
	else if(op=='+'||op=='-')
	{
		return 0;
	}
	
}

void InfixToPostfix(char source[],char target[])
{
	int i=0,j=0;
	char temp;
	
	strcpy(target, "");
	
	while(source[i]!='\0')
	{
	
		if(source[i]=='(')
		{
			push(st,source[i]);
			i++;
		}
	
		else if(source[i]==')')
		{
	
			while((top!=-1)&&st[top]!='(')
			{
				target[j]=pop(st);
				j++;
			}
			
			if(top==-1)
			{
				printf("INCORRECT EXPRESSION\n");
				exit(1);
			}
			
			temp=pop(st);
			i++;
		}
		
		else if((isalpha(source[i]))||(isdigit(source[i])))
		{
		
			target[j]=source[i];
			i++;
			j++;
		
		}
		
		else if((source[i]=='+')||(source[i]=='-')||(source[i]=='/')||(source[i]=='*')||(source[i]=='%'))
		{
		
			while(top!=-1&&st[top]!='('&&(getpriority(st[top])>getpriority(source[i])))
			{
				target[j]=pop(st);
				j++;
			}
		
			push(st,source[i]);
			i++;
		
		}
		
		else
		{
		
			printf("INVALID ELEMENT USED \n");
			exit(1);
		
		}
	
	}
	
	while(top!=-1&&st[top]!='(')
	{
	
		target[j]=pop(st);
		j++;
	
	}
	
	target[j]='\0';
}
