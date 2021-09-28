// Program to evaluate a ppostfix expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(int *s, int *t, int ch);
int pop(int *s, int *t);
int eval(char* inp);
int operand(char ch);
int operator(char ch);


int main()
{
    char inp[50];
    printf("Enter the postfix expression: ");
    scanf("%s",inp);
    int result = eval(inp);
    printf("Result: %d",result);
    return 0;
}

int eval(char* inp)
{
    int stack[50];
    char ch;
    int top=-1;      // top variable for stack
    int i=0;
    int top1=-1;    // top variable for postfix
    int a,r;
    while(inp[i]!='\0')
    {
        ch = inp[i];
        if(operator(ch))
        {
            int op2=pop(stack,&top);
			int op1=pop(stack,&top);
			switch(ch)
			{
				case'+': r = op1+op2;
					push(stack,&top,r);
					break;
				case'-': r = op1-op2;
					push(stack,&top,r);
					break;
				case'*': r = op1*op2;
					push(stack,&top,r);
					break;
				case'/': r = op1/op2;
					push(stack,&top,r);
					break;
			}//switch
        }
        else if(operand(ch))
        {
            printf("%c=",ch);
			scanf("%d",&a);
            push(stack, &top, a);
        }
        else
        {
            printf("Invalid postfix expression\n");
            break;
        }
        i++;
    }
    r = pop(stack, &top);
    return r;
}

void push(int *s, int *t, int ch)
{
    ++(*t);
    s[*t]=ch;
}

int pop(int *s, int *t)
{
    int x;
    x=s[*t];
    --(*t);
    return x;
}


int operand(char ch) // checks if character is an operand
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int operator(char ch)
{
    switch(ch)
		{
			case '+':
			case '-':
			case '*':
			case '/': return 1;
			default : return 0;
		}
}