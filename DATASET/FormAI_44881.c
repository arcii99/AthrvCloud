//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ephemeral
#include <stdio.h>

void moveDisk(int n, char source, char dest, char auxiliary) {
    // Base case: if there is only one disk, move it from source to destination
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, dest);
        return;
    }
    
    // Move n-1 disks from source to auxiliary
    moveDisk(n-1, source, auxiliary, dest);
    
    // Move the remaining disk from source to destination
    printf("Move disk %d from rod %c to rod %c\n", n, source, dest);
    
    // Move the n-1 disks from auxiliary to destination
    moveDisk(n-1, auxiliary, dest, source);
}

int main() {
    int num_disks = 4;
    char rodA = 'A', rodB = 'B', rodC = 'C';
    
    printf("The Tower of Hanoi problem with %d disks and rods A, B, C:\n\n", num_disks);
    
    // Solve the problem
    moveDisk(num_disks, rodA, rodC, rodB);
    
    return 0;
}