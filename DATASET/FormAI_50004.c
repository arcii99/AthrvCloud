//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
#include <stdio.h>

void move_disk(int n, char source, char helper, char destination)
{
    if(n == 1)
    {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }

    move_disk(n-1, source, destination, helper);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    move_disk(n-1, helper, source, destination);
}

int main()
{
    int num_disks;
    printf("Enter number of disks: ");
    scanf("%d", &num_disks);

    printf("Steps to solve Tower of Hanoi problem for %d disks:\n", num_disks);
    move_disk(num_disks, 'A', 'B', 'C');

    return 0;
}