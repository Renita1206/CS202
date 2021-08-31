//Tower of Hanoi problem solved using recursion

#include<stdio.h>

void solve(int n, char a, char b, char c); 
//a - initial peg (starting point)
//b - intermediate peg
//c - final peg (destination)

int no_of_moves=0;

void solve(int n, char a, char b, char c)
{   
    if(n==1)
    {
        printf("Move disk from %c to %c \n",a,c);
        no_of_moves++;
    }
    else
    {
        solve(n-1,a,c,b);
        printf("Move disk from %c to %c \n",a,c);
        no_of_moves++;
        solve(n-1,b,a,c);
    }
}

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("\n");
    solve(n,'A','B','C');
    printf("\nTotal number of moves required: %d",no_of_moves);
    return 0;
}