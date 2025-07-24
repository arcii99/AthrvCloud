//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

void move(int n, char source, char destination, char intermediate) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    move(n-1, source, intermediate, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    move(n-1, intermediate, destination, source);
}

int main() {
    int num_disks = 0;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks <= 0) {
        printf("Invalid input!\n");
        return 1;
    }
    printf("The steps to solve the Tower of Hanoi problem with %d disks are:\n", num_disks);
    move(num_disks, 'A', 'C', 'B');
    return 0;
}