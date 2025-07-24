//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

void move(int, char, char, char);

int main()
{
    int num_disk;
    printf("Enter the number of disks:\n");
    scanf("%d", &num_disk);
    printf("The solution for the Tower of Hanoi problem for %d disks is:\n", num_disk);
    move(num_disk, 'A', 'C', 'B');
    return 0;
}

void move(int n, char from, char to, char via)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    }
    move(n - 1, from, via, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    move(n - 1, via, to, from);
}