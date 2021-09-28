// Program to validate parenthesis in an expression

// Program to evaluate a ppostfix expression

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void push(char *s, int *t, char ch);
char pop(char *s, int *t);
char peek(char *s, int t);
void validate(char* inp);
int operand(char ch);
int operator(char ch);


int main()
{
    char inp[50];
    printf("Enter the  expression: ");
    scanf("%s",inp);
    validate(inp);
    return 0;
}

void validate(char* inp)
{
    char stack[50];
    char ch;
    int top=-1;      // top variable for stack
    int i=0;
    int top1=-1;    // top variable for postfix
    int flag=0;
    while(inp[i]!='\0')
    {
        ch = inp[i];
        if(!operator(ch) && !operand(ch))
        {
            if(ch=='[' || ch=='(' || ch=='{')
                push(stack, &top, ch);
            else if(ch==']' || ch==')' || ch=='}')
            {
                if(ch==']' && (peek(stack,top)!='['))
                {
                    flag=-1;
                    break;
                }
                else if(ch==')' && (peek(stack,top)!='('))
                {
                    flag=-1;
                    break;
                }
                else if(ch=='}' && (peek(stack,top)!='{'))
                {
                    flag=-1;
                    break;
                }
                else
                    pop(stack, &top);
            }
            else
            {
                printf("Invalid Expression");
                break;
            }
        }
        i++;
    }
    if(top!=-1)
        flag=-1;
    if(flag==0)
        printf("Valid Expression");
    else
        printf("Invalid Expression");
}

void push(char *s, int *t, char ch)
{
    ++(*t);
    s[*t]=ch;
}

char pop(char *s, int *t)
{
    char x;
    x=s[*t];
    --(*t);
    return x;
}

char peek(char *s, int t)
{
    return s[t];
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