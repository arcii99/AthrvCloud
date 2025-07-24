//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>

void hanoi(int n, char source, char destination, char auxiliary)
{
    if (n == 1) // Base case
    {
        // Move disk 1 from source to destination
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    hanoi(n-1, source, auxiliary, destination);
    
    // Move remaining disk from source to destination
    printf("Move disk %d from %c to %c\n", n, source, destination);
    
    // Move n-1 disks from auxiliary to destination
    hanoi(n-1, auxiliary, destination, source);
}

int main()
{
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}