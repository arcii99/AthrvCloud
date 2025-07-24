//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: protected
#include <stdio.h>
#include <stdlib.h>

void towers_of_hanoi(int, char, char, char);

int main() {
    int num_of_disks;
    printf("Enter the number of disks:\n");
    scanf("%d", &num_of_disks);
    if (num_of_disks < 1) {
        printf("Invalid input!\n");
        exit(1);
    }
    printf("Steps to solve the Towers of Hanoi problem:\n\n");
    towers_of_hanoi(num_of_disks, 'A', 'C', 'B');
    return 0;
}

void towers_of_hanoi(int num_of_disks, char source, char destination, char auxiliary) {
    if (num_of_disks == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    towers_of_hanoi(num_of_disks - 1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", num_of_disks, source, destination);
    towers_of_hanoi(num_of_disks - 1, auxiliary, destination, source);
}