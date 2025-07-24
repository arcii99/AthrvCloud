//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complex
#include <stdio.h>
#include <stdlib.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination);

int steps = 0;

int main()
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    tower_of_hanoi(n, 'A', 'B', 'C');

    printf("\nTotal steps taken: %d\n", steps);
    return 0;
}

void tower_of_hanoi(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        printf("\nMove disk 1 from source %c to destination %c", source, destination);
        steps++;
        return;
    }

    tower_of_hanoi(n - 1, source, destination, auxiliary);

    printf("\nMove disk %d from source %c to destination %c", n, source, destination);
    steps++;

    tower_of_hanoi(n - 1, auxiliary, source, destination);
}