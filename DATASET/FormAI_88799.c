//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
#include <stdio.h>

// Function to print the moves in the Tower of Hanoi problem
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if(n == 1)
    {
        printf("\t\t Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }

    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("\t\t Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main()
{
    int n;
    printf("\n\t\t### TOWER OF HANOI PROBLEM ###\n\n");
    printf("\tEnter the total number of disks: ");
    scanf("%d",&n);
  
    printf("\n\tSteps to solve the problem:\n\n");
    towerOfHanoi(n, 'A', 'C', 'B');
    
    printf("\n\tThank you for using our program!\n");
    return 0;
}