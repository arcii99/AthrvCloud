//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>

// Function to solve tower of hanoi problem
void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    // Configurable style
    printf("Enter names of rods (separated by space): ");
    char from, to, aux;
    scanf(" %c %c %c", &from, &to, &aux);

    towerOfHanoi(n, from, to, aux); // function call

    return 0;
}