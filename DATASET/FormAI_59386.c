//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

void moveDisks(int, char, char, char);

int main() {
    int numDisks;

    printf("How many disks would you like to solve for? ");
    scanf("%d", &numDisks);

    if (numDisks <= 0) {
        printf("Please enter a positive integer!");
        return 0;
    }

    printf("\nSolving for %d disks using the Tower of Hanoi...\n", numDisks);

    moveDisks(numDisks, 'A', 'C', 'B');

    printf("\n\nWe have successfully solved the puzzle for %d disks! Congrats!\n\n", numDisks);

    return 0;
}

void moveDisks(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", from, to);
        return;
    } else {
        moveDisks(n - 1, from, aux, to);
        printf("Move disk %d from %c to %c\n", n, from, to);
        moveDisks(n - 1, aux, to, from);
    }
}