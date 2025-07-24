//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
// C program to solve Tower of Hanoi problem with n disks and c towers
#include <stdio.h>

void TowerOfHanoi(int n, int c, int source, int auxiliary, int destination)
{
    // Base case: If there is only 1 disk to be moved, move it and return
    if (n == 1)
    {
        printf("Move disk 1 from tower %d to tower %d\n", source, destination);
        return;
    }
  
    // Move the top n-1 disks from source to auxiliary using destination as the auxiliary tower
    TowerOfHanoi(n-1, c, source, destination, auxiliary);
    printf("Move disk %d from tower %d to tower %d\n", n, source, destination);
  
    // Move the n-1 disks from auxiliary tower to destination using source as the auxiliary tower
    TowerOfHanoi(n-1, c, auxiliary, source, destination);
}

int main()
{
    int n = 4; // Number of disks
    int c = 3; // Number of towers
    printf("Tower of Hanoi problem with %d disks and %d towers\n", n, c);
    TowerOfHanoi(n, c, 1, 2, 3); // Source: Tower 1, Auxiliary: Tower 2, Destination: Tower 3
    return 0;
}