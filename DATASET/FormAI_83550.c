//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>

void tower_of_hanoi(int n, char from, char to, char aux)
{
    if(n==1)
    {
        printf("\nMove Disk 1 from %c to %c", from, to);
        return;
    }

    tower_of_hanoi(n-1, from, aux, to);
    printf("\nMove Disk %d from %c to %c", n, from, to);
    tower_of_hanoi(n-1, aux, to, from);
}

int main()
{
    int disk_count;
    printf("Welcome to Tower of Hanoi Problem!\n\n");
    printf("Enter the number of disks: ");
    scanf("%d", &disk_count);

    if(disk_count<1)
    {
        printf("\nInvalid input! The number of disks should be greater than 0.\n");
        exit(0);
    }

    printf("\nSolution for Tower of Hanoi with %d disks:", disk_count);
    tower_of_hanoi(disk_count, 'A', 'C', 'B');
    printf("\n\nThank you for trying the program!");

    return 0;
}