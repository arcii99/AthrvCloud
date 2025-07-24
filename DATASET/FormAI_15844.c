//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from %c to %c", source, destination);
        return;
    }
    tower_of_hanoi(n - 1, source, destination, auxiliary);
    printf("\nMove disk %d from %c to %c", n, source, destination);
    tower_of_hanoi(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;
    printf("\nEnter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'B', 'C');
    printf("\n");
    return 0;
}