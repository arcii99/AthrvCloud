//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scalable
#include <stdio.h>

void tower_of_hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    tower_of_hanoi(n-1, source, destination, auxiliary);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    tower_of_hanoi(n-1, auxiliary, source, destination);
}

int main() {
    int num_disks;

    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    tower_of_hanoi(num_disks, 'A', 'B', 'C');

    return 0;
}