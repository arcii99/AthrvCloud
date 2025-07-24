//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

// Function to solve the Towers of Hanoi puzzle
void solveTowersOfHanoi(int n, char source_pole, char destination_pole, char auxiliary_pole)
{
    // Base case: if there is only one disk to move
    if (n == 1)
    {
        printf("Wow! Move disk 1 from pole %c to pole %c\n", source_pole, destination_pole);
        return;
    }

    // Move top n-1 disks from source pole to auxiliary pole using destination pole as intermediary
    solveTowersOfHanoi(n - 1, source_pole, auxiliary_pole, destination_pole);

    // Move remaining bottom disk from source pole to destination pole
    printf("Wait, What?! Move disk %d from pole %c to pole %c\n", n, source_pole, destination_pole);

    // Move n-1 disks from auxiliary pole to destination pole using source pole as intermediary
    solveTowersOfHanoi(n - 1, auxiliary_pole, destination_pole, source_pole);
}

// Driver code
int main()
{
    int n = 3; // Number of disks

    // Function call to solve the problem
    solveTowersOfHanoi(n, 'A', 'C', 'B');
    
    printf("WOOHOO! The Tower of Hanoi problem is solved.\n");

    return 0;
}