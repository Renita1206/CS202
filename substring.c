// Program to search for substring in string using recursion

#include<stdio.h>
#include<string.h>

int check(char*, char*,char*);
int search(char*, char*);

int check(char *text, char *sub, char *substring)
{
    if (*text == '\0' && *sub != '\0')
        return 0;
    if (*sub == '\0')
        return 1;
  
    if (*text == *sub)
        return check(text + 1, sub + 1, substring);
    
    else
        return check(text+1,substring,substring);
  
    return 0;
}
  
int main()
{
    char str[1000],substring[1000];
    printf("\nEnter the string: ");
    scanf("%[^\n]%*c",str);
    printf("\nEnter the substring: ");
    scanf("%[^\n]%*c",substring);
    int result=check(str,substring,substring);
    if(result==1)
        printf("TRUE");
    else
        printf("FALSE");
    return 0;
}