//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: automated
#include <stdio.h>

void move(int numDisks, char from, char to, char using);

int main() {
    int numDisks;
    printf("Enter the number of disks: ");
    scanf("%d", &numDisks);
    if (numDisks <= 0) {
        printf("Invalid number of disks entered. Exiting...\n");
        return 0;
    }
    move(numDisks, 'A', 'C', 'B');
    return 0;
}

void move(int numDisks, char from, char to, char using) {
    if (numDisks == 1) {
        printf("Move disk 1 from peg %c to peg %c\n", from, to);
    } else {
        move(numDisks-1, from, using, to);
        printf("Move disk %d from peg %c to peg %c\n", numDisks, from, to);
        move(numDisks-1, using, to, from);
    }
}