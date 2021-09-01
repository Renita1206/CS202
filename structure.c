// Program implementing structures in C

#include<stdio.h>
#include<string.h>

typedef struct mark
{
    char code[10];
    int score;
}M;

typedef struct student
{
    char name[100];
    int srn;
    int sem;
    M marks[5];
}S;

int main()
{
    int n;
    S record[100];
    printf("Enter the number of students: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\n Enter the name of the student: ");
        scanf("%s",record[i].name);
        printf("\n Enter the srn of the student: ");
        scanf("%d",&record[i].srn);
        printf("\n Enter the semester of the student: ");
        scanf("%d",&record[i].sem);
        printf("\n Enter the subject code: ");
        scanf("%s",record[i].marks[0].code);
        printf("\n Enter marks: ");
        scanf("%d",&record[i].marks[0].score);
        printf("\n Enter the subject code: ");
        scanf("%s",record[i].marks[1].code);
        printf("\n Enter marks: ");
        scanf("%d",&record[i].marks[1].score);
    }
    
    char subject[10];
    printf("\n Enter subject code to calculate average: ");
    scanf("%s",subject);
    int sum=0,count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<5;j++)
        {
            if(strcmp(subject,(record[i].marks[j].code))==0)
            {
                sum+=record[i].marks[j].score;
                count++;
            }
        }
    }
    int avg=sum/count;
    printf("Average: %d\n",avg);

    //sort by srn
    for(int i=0;i<n;i++)
    {
        int pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(record[i].srn>record[j].srn)
                pos=j;
        }
        if(pos!=i)
        {
            //swap values
            S r1=record[pos];
            record[pos]=record[i];
            record[i]=r1;
        }
    }

    //print sorted array
    for(int i=0;i<n;i++)
    {
        printf("%s\t",record[i].name);
        printf("%d\t",record[i].srn);
        printf("%d\n",record[i].sem);
    }

    return 0;
}