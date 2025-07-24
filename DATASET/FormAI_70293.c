//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

void towers_of_hanoi(int n, char source_rod, char aux_rod, char dest_rod)
{
    if(n == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, dest_rod);
        return;
    }
    towers_of_hanoi(n - 1, source_rod, dest_rod, aux_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, source_rod, dest_rod);
    towers_of_hanoi(n - 1, aux_rod, source_rod, dest_rod);
}

int main()
{
    int n = 3;
    printf("Welcome to the Tower of Hanoi game!\n\n");
    printf("The rules are simple:\n");
    printf("- There are 3 rods labelled A, B, and C\n");
    printf("- There are %d disks on rod A initially\n", n);
    printf("- The objective is to transfer all the disks from rod A to rod C\n");
    printf("- You can move only one disk at a time\n");
    printf("- A larger disk cannot be placed on top of a smaller disk\n\n");
    printf("Let's start the game!\n");
    towers_of_hanoi(n, 'A', 'B', 'C');
    printf("\nCongratulations! You have completed the game!");
    return 0;
}