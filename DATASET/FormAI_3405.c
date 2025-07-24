//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: creative
#include <stdio.h>

// Recursive function to move disks
void TowerOfHanoi(int num_disks, char source_peg, char destination_peg, char auxiliary_peg) {
    if (num_disks == 1) {
        printf("\nMove disk 1 from peg %c to peg %c", source_peg, destination_peg);
        return;
    }
    TowerOfHanoi(num_disks - 1, source_peg, auxiliary_peg, destination_peg);
    printf("\nMove disk %d from peg %c to peg %c", num_disks, source_peg, destination_peg);
    TowerOfHanoi(num_disks - 1, auxiliary_peg, destination_peg, source_peg);
}

int main() {
    int num_disks = 5;
    printf("The Tower of Hanoi problem with %d disks:\n\n", num_disks);
    TowerOfHanoi(num_disks, 'A', 'C', 'B');
    printf("\n\nThe Tower of Hanoi problem with %d disks is solved!", num_disks);
    return 0;
}