//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

void move(int n, char src, char dest, char aux) {
    if (n == 1) {
        printf("Move disk 1 from tower %c to tower %c\n", src, dest);
        return;
    }
    move(n - 1, src, aux, dest);
    printf("Move disk %d from tower %c to tower %c\n", n, src, dest);
    move(n - 1, aux, dest, src);
}

int main() {
    int numDisks;
    printf("Enter the number of disks on the tower: ");
    scanf("%d", &numDisks);
    if (numDisks < 1) {
        printf("Error: number of disks must be 1 or greater.\n");
        return 1;
    }

    move(numDisks, 'A', 'C', 'B');
    return 0;
}