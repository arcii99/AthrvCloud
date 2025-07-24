//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>

//Function prototype
void tower_of_hanoi(int n, char from, char to, char temp);

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d",&n);
    
    if(n < 1)
    {
        printf("The number of disks cannot be less than 1.");
        return 0;
    }
    
    printf("Tower of Hanoi problem with %d disks:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    
    return 0;
}

//Function to implement tower of hanoi
void tower_of_hanoi(int n, char from, char to, char temp)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    tower_of_hanoi(n-1, from, temp, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    tower_of_hanoi(n-1, temp, to, from);
}