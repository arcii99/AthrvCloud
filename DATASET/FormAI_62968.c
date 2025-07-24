//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>

void hanoi(int, char, char, char);

int main()
{
    int n;

    printf("Welcome to the Tower of Hanoi puzzle!\n");
    printf("Please enter the number of disks you want to play with: ");
    scanf("%d", &n);

    if(n <= 0)
    {
        printf("Invalid input. Please enter a positive integer.\n");
        return 0;
    }

    printf("Here is the starting position of the puzzle:\n");
    for(int i = n; i >= 1; i--)
        printf("%*c%*c\n", i, '#', (n - i + 1), '#');

    hanoi(n, 'A', 'B', 'C');

    printf("Congratulations, you have solved the puzzle!\n");

    return 0;
}

void hanoi(int n, char from, char to, char aux)
{
    if(n == 1)
    {
        printf("\nMove disk 1 from rod %c to rod %c", from, to);
        return;
    }

    hanoi(n-1, from, aux, to);
    printf("\nMove disk %d from rod %c to rod %c", n, from, to);
    hanoi(n-1, aux, to, from);
}