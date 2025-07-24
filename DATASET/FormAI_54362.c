//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: cheerful
#include <stdio.h>

void moveDisk(char from_rod, char to_rod, int disk_number) {
    printf("Move disk %d from %c rod to %c rod. Happy moving!\n", disk_number, from_rod, to_rod);
}

void towerOfHanoi(int number_of_disks, char from_rod, char to_rod, char aux_rod) {
    if (number_of_disks == 1) {
        moveDisk(from_rod, to_rod, number_of_disks);
        return;
    }

    towerOfHanoi(number_of_disks - 1, from_rod, aux_rod, to_rod);
    moveDisk(from_rod, to_rod, number_of_disks);
    towerOfHanoi(number_of_disks - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int number_of_disks;
    printf("Welcome to the Tower of Hanoi problem! Please enter the number of disks you want to move:\n");
    scanf("%d", &number_of_disks);

    if (number_of_disks < 1) {
        printf("Invalid input! The number of disks should be greater than 0.\n");
        return 0;
    }

    printf("Here is the solution to move %d disks from Rod A to Rod C:\n", number_of_disks);
    towerOfHanoi(number_of_disks, 'A', 'C', 'B');

    printf("\nThank you for playing! Happy coding!\n");
    return 0;
}