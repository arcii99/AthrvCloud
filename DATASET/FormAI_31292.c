//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include <stdio.h>

// Global variables
int num_disks;
int source_peg = 1, destination_peg = 3, auxiliary_peg = 2;

// Function to move the disks
void towerOfHanoi(int n, int source_peg, int auxiliary_peg, int destination_peg) {
    if (n == 1) {
        printf("\n Move disk 1 from PEG-%d to PEG-%d", source_peg, destination_peg);
        return;
    }
    towerOfHanoi(n - 1, source_peg, destination_peg, auxiliary_peg);
    printf("\n Move disk %d from PEG-%d to PEG-%d", n, source_peg, destination_peg);
    towerOfHanoi(n - 1, auxiliary_peg, source_peg, destination_peg);
}

int main() {
    // Taking input from user
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    // Tower of Hanoi problem
    printf("\n SOLVING TOWER OF HANOI PROBLEM FOR %d DISKS", num_disks);
    towerOfHanoi(num_disks, source_peg, auxiliary_peg, destination_peg);
    printf("\n");

    return 0;
}