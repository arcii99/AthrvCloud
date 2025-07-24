//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>

void move(int n, char start, char middle, char end) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c.\n", start, end);
    } else {
        move(n - 1, start, end, middle);
        printf("Move disk %d from %c to %c.\n", n, start, end);
        move(n - 1, middle, start, end);
    }
}

int main() {
    int disks;

    printf("Welcome to the Tower of Hanoi problem solver.\n");
    printf("How many disks would you like to use? ");
    scanf("%d", &disks);

    printf("\nSolving the Tower of Hanoi problem for %d disks:\n\n", disks);
    move(disks, 'A', 'B', 'C');

    printf("\nDone!");
}