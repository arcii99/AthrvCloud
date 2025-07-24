//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>

void hanoi(int num_disks, char source, char auxiliary, char destination) {
    if (num_disks == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
    } else {
        hanoi(num_disks - 1, source, destination, auxiliary);
        printf("Move disk %d from %c to %c\n", num_disks, source, destination);
        hanoi(num_disks - 1, auxiliary, source, destination);
    }
}

int main() {
    int num_disks;
    printf("ENTER THE NUMBER OF DISKS: ");
    scanf("%d", &num_disks);
    printf("THE SOLUTION TO THE TOWER OF HANOI PROBLEM IS:\n\n");
    hanoi(num_disks, 'A', 'B', 'C');
    return 0;
}