//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>

void TOH(int n, char start, char middle, char end) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", start, end);
        return;
    }
    TOH(n - 1, start, end, middle);
    printf("Move disk %d from %c to %c\n", n, start, end);
    TOH(n - 1, middle, start, end);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks <= 0) {
        printf("Invalid input: number of disks must be greater than 0\n");
        return 1;
    }

    printf("Starting Tower of Hanoi...\n");
    TOH(num_disks, 'A', 'B', 'C');
    printf("Tower of Hanoi completed!\n");

    return 0;
}