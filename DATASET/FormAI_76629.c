//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>

// Function prototype
void tower_of_hanoi(int num_disks, char source_rod, char destination_rod, char auxiliary_rod);

int main()
{
    int num_disks, moves_required;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // Check if the input is valid
    if (num_disks <= 0)
    {
        printf("Error: Invalid input!\n");
        return 0;
    }

    // Calculate the minimum moves required
    moves_required = (1 << num_disks) - 1;

    // Print the result
    printf("\nFor %d disks, the minimum number of moves required is: %d\n", num_disks, moves_required);

    // Solve the problem using recursive algorithm
    printf("\nSolution:\n");
    tower_of_hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}

void tower_of_hanoi(int num_disks, char source_rod, char destination_rod, char auxiliary_rod)
{
    // Base case: For single disk
    if (num_disks == 1)
    {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, destination_rod);
        return;
    }

    // Move n-1 disks from source rod to auxiliary rod
    tower_of_hanoi(num_disks - 1, source_rod, auxiliary_rod, destination_rod);

    // Move the remaining disk from source rod to destination rod
    printf("Move disk %d from rod %c to rod %c\n", num_disks, source_rod, destination_rod);

    // Move n-1 disks from auxiliary rod to destination rod
    tower_of_hanoi(num_disks - 1, auxiliary_rod, destination_rod, source_rod);
}