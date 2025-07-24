//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: synchronous
#include<stdio.h>

void tower_of_hanoi(int, char, char, char);

int main()
{
    int num_disks;
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    tower_of_hanoi(num_disks, source, auxiliary, destination);

    return 0;
}

void tower_of_hanoi(int num_disks, char source, char auxiliary, char destination)
{
    if(num_disks == 1)
    {
        printf("\nMove Disk 1 from %c to %c", source, destination);
        return;
    }

    tower_of_hanoi(num_disks-1, source, destination, auxiliary);

    printf("\nMove Disk %d from %c to %c", num_disks, source, destination);

    tower_of_hanoi(num_disks-1, auxiliary, source, destination);
}