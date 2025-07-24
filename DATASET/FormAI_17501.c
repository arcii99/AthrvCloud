//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: introspective
#include<stdio.h>

// Function to move disks from source to destination tower
void moveDisk(char source, char destination, int disk_no)
{
    printf("Move disk %d from %c to %c\n", disk_no, source, destination);
}

// Recursive function to solve Tower of Hanoi problem
void solveTowerOfHanoi(int no_of_disks, char source_tower, char destination_tower, char auxiliary_tower)
{
    if(no_of_disks == 1)
    {
        moveDisk(source_tower, destination_tower, 1); // Move disk from source to destination
        return;
    }

    // Move top n-1 disks from source tower to auxiliary tower
    solveTowerOfHanoi(no_of_disks-1, source_tower, auxiliary_tower, destination_tower);

    // Move remaining 1 disk from source tower to destination tower
    moveDisk(source_tower, destination_tower, no_of_disks);

    // Move top n-1 disks from auxiliary tower to destination tower
    solveTowerOfHanoi(no_of_disks-1, auxiliary_tower, destination_tower, source_tower);
}

int main()
{
    int no_of_disks;
    printf("Enter number of disks: ");
    scanf("%d", &no_of_disks);

    // Solving Tower of Hanoi problem
    solveTowerOfHanoi(no_of_disks, 'A', 'C', 'B');

    return 0;
}