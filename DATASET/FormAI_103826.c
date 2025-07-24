//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>

void towerOfHanoi(int num, char source_rod, char dest_rod, char aux_rod) {
    if (num == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source_rod, dest_rod);
        return;
    }
    towerOfHanoi(num-1, source_rod, aux_rod, dest_rod);
    printf("Move disk %d from rod %c to rod %c\n", num, source_rod, dest_rod);
    towerOfHanoi(num-1, aux_rod, dest_rod, source_rod);
}

int main() {
    int num_of_disks;

    printf("Welcome to the peaceful Tower of Hanoi Problem!\n");
    printf("This problem represents the essential ideas of recursion. You need to move all the disks from the source rod to the destination rod.\n");
    printf("You can move only one disk at a time, and you can never place a larger disk on a smaller disk.\n");

    printf("\nEnter the number of disks: ");
    scanf("%d", &num_of_disks);

    printf("\nHere are the steps to solve the Tower of Hanoi Problem with %d disks:\n", num_of_disks);
    towerOfHanoi(num_of_disks, 'A', 'C', 'B');
    
    printf("\nCongratulations! You have solved the peaceful Tower of Hanoi problem in %d steps.\n", (1 << num_of_disks) - 1);

    return 0;
}