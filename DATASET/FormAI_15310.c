//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: optimized
#include<stdio.h>
#include<stdlib.h>

void towerOfHanoi(int numDisks, char source, char destination, char auxiliary)
{
    if(numDisks==1)
    {
        printf("\nMove disk 1 from %c to %c",source,destination);
        return;
    }
    towerOfHanoi(numDisks-1,source,auxiliary,destination);
    printf("\nMove disk %d from %c to %c",numDisks,source,destination);
    towerOfHanoi(numDisks-1,auxiliary,destination,source);
}

int main()
{
    int numDisks;
    printf("Enter the number of disks:");
    scanf("%d",&numDisks);
    printf("\nSteps to solve Tower of Hanoi problem with %d disks:",numDisks);
    towerOfHanoi(numDisks,'A','C','B');
    return 0;
}