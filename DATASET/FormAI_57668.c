//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

void move_tower(int, char, char, char);

int main()
{
    int num_disks;
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    printf("The steps to solve the Tower of Hanoi problem with %d disks are:\n\n", num_disks);

    move_tower(num_disks, source, auxiliary, destination);

    return 0;
}

void move_tower(int num_disks, char source, char auxiliary, char destination)
{
    if(num_disks == 1)
    {
        printf("Move Disk %d from %c to %c\n", num_disks, source, destination);
        return;
    }

    move_tower(num_disks - 1, source, destination, auxiliary);
    printf("Move Disk %d from %c to %c\n", num_disks, source, destination);
    move_tower(num_disks - 1, auxiliary, source, destination);
}