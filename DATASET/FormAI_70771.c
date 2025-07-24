//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: detailed
#include <stdio.h>

void tower_of_hanoi(int disks, int height, char source, char spare, char destination) {
    if (disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
    } else {
        tower_of_hanoi(disks - 1, height, source, destination, spare);
        printf("Move disk %d from %c to %c\n", disks, source, destination);
        tower_of_hanoi(disks - 1, height, spare, source, destination);
    }
}

int main() {
    int disks, height;
    printf("Enter the number of disks: ");
    scanf("%d", &disks);
    printf("Enter the height of each disk: ");
    scanf("%d", &height);
    printf("\nThe Tower of Hanoi solution for %d disks is:\n\n", disks);
    tower_of_hanoi(disks, height, 'A', 'B', 'C');
    return 0;
}