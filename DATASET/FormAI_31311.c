//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multivariable
#include <stdio.h>

// function to move disks
void move(char source, char destination, int disk_number)
{
    printf("Move disk %d from %c to %c\n", disk_number, source, destination);
}

// recursive function to solve Tower of Hanoi problem
void tower_of_hanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        move(source, destination, n);
        return;
    }
    tower_of_hanoi(n-1, source, destination, auxiliary);
    move(source, destination, n);
    tower_of_hanoi(n-1, auxiliary, source, destination);
}

int main()
{
    int number_of_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &number_of_disks);
    tower_of_hanoi(number_of_disks, 'A', 'B', 'C');
    return 0;
}