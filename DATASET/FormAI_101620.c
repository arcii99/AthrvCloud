//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    towerOfHanoi(n-1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main()
{
    int num_disks;
    char source = 'A', auxiliary = 'B', destination = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if(num_disks < 1)
    {
        printf("Invalid input\n");
        return 0;
    }

    towerOfHanoi(num_disks, source, auxiliary, destination);

    return 0;
}