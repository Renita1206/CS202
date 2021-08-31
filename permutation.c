// Program to print all permutations
#include <stdio.h>
#include <string.h>
 

void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void permute(char *a, int begin, int end)
{
    int i;
    if (begin == end)
        printf("%s\n", a);
    else
    {
        for (i = begin; i <= end; i++)
        {
            swap((a+begin), (a+i));
            permute(a, begin+1, end);
        }
    }
}
 
int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s",str);
    int n = strlen(str);
    permute(str, 0, n-1);
    return 0;
}