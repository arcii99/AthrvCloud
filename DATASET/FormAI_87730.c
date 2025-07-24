//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

void tower_of_hanoi(int disks, char source, char auxiliary, char destination) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    tower_of_hanoi(disks - 1, source, destination, auxiliary);
    printf("Move disk %d from %c to %c\n", disks, source, destination);
    tower_of_hanoi(disks - 1, auxiliary, source, destination);
}

int main() {
    int disks;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    if (disks < 1) {
        printf("Invalid number of disks\n");
        return 0;
    }
    printf("The steps to solve the Tower of Hanoi problem:\n");
    tower_of_hanoi(disks, 'A', 'B', 'C');
    return 0;
}