#include<stdio.h>

int main()
{
    char str[1000],substring[1000];
    printf("\nEnter the string: ");
    scanf("%[^\n]%*c",str);
    printf("\nEnter the substring: ");
    scanf("%[^\n]%*c",substring);
    printf("%s %s",str,substring);
    return 0;
}