// Program to convert expression from infix to postfix

#include<stdio.h>
#include<stdlib.h>


void convert(char *infix, char *postfix);
int precedence(char ch);
void push(char *s, int *t, char ch);
char pop(char *s, int *t);
char peek(char *s, int t);
int operand(char ch);


int main()
{
    char infix[10], postfix[10];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    convert(infix, postfix);
    printf("Resultant postfix expression: %s",postfix);
    return 0;
}

void convert(char *infix, char *postfix)
{
    char stack[10];
    char ch;
    int top=-1;      // top variable for stack
    int i=0;
    int top1=-1;    // top variable for postfix
    push(stack, &top, '#');
    while(infix[i]!='\0')
    {
        ch = infix[i];
        if(operand(ch))     // push into postfix expression if character is an operand
            push(postfix, &top1, ch);
        else if(precedence(ch)==1) // if character is '(' push into stack
            push(stack, &top, ch);
        else if(precedence(ch)==2) // if character is ')' pop stack elements until '(' 
        {
            while(precedence(peek(stack,top))!=1)
                push(postfix, &top1, pop(stack, &top));
            pop(stack, &top);
        }
        else if(precedence(ch)>precedence(peek(stack,top))) // push into stack if presedence is greater
            push(stack, &top, ch);
        else if(precedence(ch)==8) // invalid character encountered
            printf("Invalid expression\n");
        else // push elements from stack to postfix till precedence of input less than equal to precedence of top of stack
        {
            while(precedence(ch)<=precedence(peek(stack,top)))
            {
                push(postfix, &top1, pop(stack, &top));
            }
            push(stack, &top, ch);
        }

        i++;
    }
    while(peek(stack, top)!='#') // pop stack elements
    {
        push(postfix, &top1, pop(stack, &top));  
    }
    push(postfix, &top1,'\0'); // end character
}

int precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 4;
        case '*':
        case '/': return 5;
        case '$':
        case '^':return 6;
        case '(': return 1;
        case ')':return 2;
        case '#':return 0;
        default: return -1; 
    }
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