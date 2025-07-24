//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include<stdio.h>
void tower_of_hanoi(int n, char source, char destination, char helper)
{
    if(n==1)
    {
        printf("Move disk 1 from %c to %c\n",source,destination);
        return;
    }
    tower_of_hanoi(n-1,source,helper,destination);
    printf("Move disk %d from %c to %c\n",n,source,destination);
    tower_of_hanoi(n-1,helper,destination,source);
}
int main()
{
    int n;
    char source='A',destination='C',helper='B';
    printf("**************************************\n");
    printf(" Welcome to the Tower of Hanoi Problem\n");
    printf("**************************************\n");
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    printf("The steps to solve the Tower of Hanoi problem with %d disks are:\n",n);
    tower_of_hanoi(n,source,destination,helper);
    printf("**************************************\n");
    printf(" Thank you for playing the game!\n");
    printf("**************************************\n");
    return 0;
}