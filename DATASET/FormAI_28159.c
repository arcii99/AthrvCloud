//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>

void hanoi(int num, char source, char dest, char temp) {
    if (num == 1) {
        printf("Move disk %d from %c to %c\n", num, source, dest);
        return;
    }
    hanoi(num-1, source, temp, dest);
    printf("Move disk %d from %c to %c\n", num, source, dest);
    hanoi(num-1, temp, dest, source);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    hanoi(num_disks, 'A', 'C', 'B');
    return 0;
}