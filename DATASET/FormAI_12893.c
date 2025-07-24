//FormAI DATASET v1.0 Category: Game ; Style: recursive
/* This C program is a recursive implementation of the famous Towers of Hanoi puzzle */
#include <stdio.h>

void hanoi(int n, char start_pos, char end_pos, char temp_pos);

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');  // A, B and C are names of the pegs
    return 0;
}

void hanoi(int n, char start_pos, char end_pos, char temp_pos)
{
    if (n == 1)
    {
        printf("\nMove disk 1 from peg %c to peg %c", start_pos, end_pos);
        return;
    }
    hanoi(n - 1, start_pos, temp_pos, end_pos);
    printf("\nMove disk %d from peg %c to peg %c", n, start_pos, end_pos);
    hanoi(n - 1, temp_pos, end_pos, start_pos);
}