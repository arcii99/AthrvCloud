//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: futuristic
#include <stdio.h>

void towerOfHanoi(int n, char from_rod[], char to_rod[], char aux_rod[])
{
    if(n == 1)
    {
        printf("Move disk 1 from rod %s to rod %s\n", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %s to rod %s\n", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("Welcome to the Tower of Hanoi challenge! \nIn the year 2050, robots use this game to showcase their algorithmic intelligence. \nEnter the number of disks you want to play with: ");
    scanf("%d", &n);
    printf("\nThe game begins with the following setup:");
    towerOfHanoi(n, "A", "C", "B");
    printf("\nCongratulations! The game has been won.\nHopefully, your human mind was able to match the intelligence of the robots. \nThanks for playing!");
    return 0;
}