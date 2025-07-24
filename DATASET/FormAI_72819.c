//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include<stdio.h>
void toh(int,int,int,int); // function prototype

int main()
{
    int n;
    printf("Enter number of discs: ");
    scanf("%d",&n);
    toh(n,1,2,3); // calling the tower of hanoi function
    return 0;
}

void toh(int n, int source, int temp, int dest)
{
    if(n==1) // base condition
    {
        printf("Move disc from pole %d to pole %d\n",source,dest);
        return;
    }
    toh(n-1,source,dest,temp); // recursive call
    printf("Move disc from pole %d to pole %d\n",source,dest); // move the disc
    toh(n-1,temp,source,dest); // recursive call
}