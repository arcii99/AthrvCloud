//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include<stdio.h>

void tower_of_hanoi(int n, char source, char destination, char temp)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n-1, source, temp, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    tower_of_hanoi(n-1, temp, destination, source);
}

int main()
{
    int n;
    char source = 'A', destination = 'C', temp = 'B';
    
    printf("***** Welcome to Tower of Hanoi Challenge *****\n\n");
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("\n");
    printf("The solution to the Tower of Hanoi problem with %d disks is:\n\n", n);
    tower_of_hanoi(n, source, destination, temp);
    printf("\n");
    printf("***** Challenge Complete! *****\n");
    
    return 0;
}