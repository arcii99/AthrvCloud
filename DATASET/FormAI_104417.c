//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: automated
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int count,i,sum=0,num,temp;
    printf("Enter the number of integers to be checked:");
    scanf("%d",&count);
    for(i=1;i<=count;i++)
    {
        printf("\nEnter integer #%d: ",i);
        scanf("%d",&num);
        sum+=num;
    }
    temp=256-sum%256;
    printf("\n\nChecksum value: %d",temp);
    return 0;
}