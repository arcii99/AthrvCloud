//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: enthusiastic
#include <stdio.h>
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if (n == 1) // Base case
    {
        printf("\nMove disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
    printf("\nMove disk %d from rod %c to rod %c", n, from_rod, to_rod);
    towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}
int main()
{
    int n = 3; // Number of disks
    printf("Welcome to the C Tower of Hanoi Program!\n\n");
    printf("In this program, we will solve the Tower of Hanoi problem using recursion.\n\n");
    printf("The Tower of Hanoi is a mathematical puzzle consisting of three rods, and a number of disks of different sizes which can slide onto any rod.\n\n");
    printf("The puzzle starts with the disks in a neat stack in ascending order of size on one rod, the smallest at the top, thus making a conical shape.\n\n");
    printf("The objective of the puzzle is to move the entire stack to another rod, satisfying the following rules:\n\n");
    printf("    1. Only one disk can be moved at a time.\n");
    printf("    2. Each move consists of taking the upper disk from one of the rods and sliding it onto another rod, on top of the other disks that may already be present on that rod.\n");
    printf("    3. No disk may be placed on top of a smaller disk.\n");
    printf("\nThe solution to the puzzle requires moving the entire stack to another rod, obeying the rules, using the empty rod as temporary storage.\n\n");
    printf("Let's solve the puzzle with %d disks!\n\n", n);
    towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
    printf("\n\nCongratulations! The puzzle has been solved!\n");
    return 0;
}