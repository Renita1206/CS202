// Program to create records for IPL players
// Stores playername, teamname, no of matches played and runs scored
//   i)Display details of player who scored max runs
//  ii)Compute no of matches played by each player

#include<stdio.h>
#include<string.h>

typedef struct matches
{
    char code[50];
    int runs;
}M;

typedef struct player
{
    char name[100];
    char team[50];
    M mdetails[100];
}P;

int main()
{
    /*char inp[1000];
    printf("Enter the string: ");
    scanf("%[^\n]s",inp); //to input a string with spaces */
    
    int n;
    P record[100];

    //input number of players
    printf("\nEnter the number of players: ");
    scanf("%d",&n);

    //input player details
    for(int i=0;i<n;i++)
    {
        int m=0;
        printf("\nEnter the name: ");
        scanf("%s",record[i].name);
        printf("\nEnter the team name: ");
        scanf("%s",record[i].team);
        printf("\nEnter the number of matches played: ");
        scanf("%d",&m);
        for(int j=0;j<m;j++)
        {
            printf("\nEnter the match name or code: ");
            scanf("%s",record[i].mdetails[j].code);
            printf("\nEnter runs scored by player in the match: ");
            scanf("%d",&record[i].mdetails[j].runs);
        }
    }

    //display player with max runs per match
    char matchcode[50];
    printf("\n Enter match code or name to display player with max runs: ");
    scanf("%s",matchcode);
    int position=0,max=0;
    for(int i=0;i<n;i++)
    {
        int nm=0;
        for(int j=0;j<100;j++)
        {
            if(strcmp("",(record[i].mdetails[j].code))==0)
            {
                break;
            }
            else
            {
               if(strcmp(matchcode,(record[i].mdetails[j].code))==0)
                {
                    if(record[i].mdetails[j].runs>max)
                    {
                        max=record[i].mdetails[j].runs;
                        position=i;
                    }
                } 
                nm++;
            }
        }
        printf("\nPlayer name: %s \t Number of matches played: %d",record[i].name,nm);
    }

    printf("\nMax runs scored by: ");
    printf("\nPlayer name: %s \t Team name: %s",record[position].name,record[position].team);
    return 0;
}