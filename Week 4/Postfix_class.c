// Program to convert expression from infix to postfix

#include<stdio.h>
#include<stdlib.h>


void convert(char *infix, char *postfix);
int stack_precedence(char ch);
int input_precedence(char ch);
void push(char *s, int *t, char ch);
char pop(char *s, int *t);
char peek(char *s, int t);


int main()
{
    char infix[10], postfix[10];
    printf("Enter the infix expression: ");
    scanf("%s",infix);
    printf("\n");
    convert(infix, postfix);
    printf("Resultant postfix expression: %s",postfix);
    return 0;
}

void convert(char *infix, char *postfix)
{
    char s[10];    //stack
    char ch;
    int i,j,top;
    top=-1;
    i=0;
    j=0;
    push(s,&top,'#');
    while(infix[i]!='\0')
    {
        ch=infix[i];
        while(stack_precedence(peek(s,top))>input_precedence(ch))
        {
            postfix[j++] = pop(s,&top);
        }
        if(stack_precedence(peek(s,top))!=input_precedence(ch))
        {
            push(s,&top,ch);
            i++;
        }
        else
        {
            pop(s,&top);
            i++;
        }
    }
    while(peek(s,top)!='#')
    {
        postfix[j++] = pop(s,&top);
    }
    postfix[j]='\0';

}

int stack_precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 2;
        case '*':
        case '/': return 4;
        case '$': return 5;
        case '(': return 0;
        case '#': return -1;
        default: return 8; 
    }
}

int input_precedence(char ch)
{
    switch(ch)
    {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 3;
        case '$': return 6;
        case '(': return 9;
        case '#': return 0;
        default: return 7; 
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