//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>

void tower_of_hanoi(int disk, char source, char destination, char auxiliary) {
    if (disk == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
    } else {
        tower_of_hanoi(disk - 1, source, auxiliary, destination);
        printf("Move disk %d from %c to %c\n", disk, source, destination);
        tower_of_hanoi(disk - 1, auxiliary, destination, source);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    tower_of_hanoi(num_disks, 'A', 'C', 'B');

    return 0;
}