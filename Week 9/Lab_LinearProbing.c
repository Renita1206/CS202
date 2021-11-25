//Linear Probing

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define N 10

typedef struct Details
{
    long int phNo; 
    char name[40];
}Details;

void init(Details hashTable[], int n)
{
    for( int i=0;i<N;i++)
    {
        hashTable[i].phNo = -1;
        strcpy(hashTable[i].name, "N/A"); 
    }
}

void display(Details hashTable[], int n)
{
    for( int i=0;i<N;i++)
    {
        printf("%ld\t %s\n", hashTable[i].phNo, 
        hashTable[i].name); 
    }
    printf("\n");
}

void lp(int phNo, char name[], int n, Details hashTable[])
{
    int hashValue = phNo % N;
    while(hashTable[hashValue].phNo != -1)
    {
        hashValue++; 
    }
    hashTable[hashValue].phNo = phNo;
    strcpy(hashTable[hashValue].name, name);
}

void delete(long int phNo, Details hashTable[])
{
    int count = 0, flag=0;
    while(count < N)
    {
        if(hashTable[count].phNo == phNo)
        {
            hashTable[count].phNo = -1;
            strcpy(hashTable[count].name, "N/A");
            printf("Deleted\n");
            flag = 1;
            break;
        }
        count++;
    }
    if(!flag)
        printf("Element does not exist\n");
    else
        printf("Element deleted\n"); 
}

void search(long int phNo, Details hashTable[])
{
    int count = 0, flag=0;
    while(count < N)
    {
        if(hashTable[count].phNo == phNo)
        {
            printf("%ld\t %s\n", hashTable[count].phNo, 
            hashTable[count].name);
            flag = 1;
            break;
        }
        count++;
    }
    if(!flag)
        printf("Element does not exist\n");
}

int main()
{
    int n = 0, count = 0,delOpt = 0,searchOpt = 0;
    long int phNo = 0,delPhNo = 0,searchPhNo = 0;
    int choice;
    char name[40] = "";
    printf("Number of people to add: ");
    scanf("%d", &n);
    Details hashTable[N];
    init(hashTable, n);
    while(count < n)
    {
        printf("Phone number %d: ",(count+1));
        scanf("%ld", &phNo); 
        printf("Name %d: ",(count+1));
        scanf("%s", name);
        lp(phNo, name, n, hashTable);
        count++;
    }
    printf("\n");
    display(hashTable, n);
    printf("\n\n\n");
    do{
        printf("1.Display 2.Delete 3.Search 4.Quit\n");
        printf("Choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: display(hashTable, n);
                    break;
            case 2: printf("Phone number: ");
                    scanf(" %ld", &delPhNo); 
                    delete(delPhNo, hashTable);
                    break;
            case 3: printf("Phone number: ");
                    scanf(" %ld", &searchPhNo);
                    search(searchPhNo, hashTable);
                    break;
            case 4: exit(0);
        }
    }while(choice<6);
}