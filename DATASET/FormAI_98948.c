//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) { 
    if (n == 1) { // Base case
        printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod); // Move top n-1 disks from A to B, using C as auxiliary
    printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod); // Move the nth disk from A to C
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod); // Move the n-1 disks from B to C, using A as auxiliary
}

int main() {
    int no_of_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &no_of_disks);
    tower_of_hanoi(no_of_disks, 'A', 'C', 'B');
    return 0;
}