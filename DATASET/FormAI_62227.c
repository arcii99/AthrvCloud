//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: retro
#include <stdio.h>

void moveTower(int height, char fromPeg, char toPeg, char usingPeg);

int main() {
    int height = 4; // Change this value to change the height of the Tower
    moveTower(height, 'A', 'C', 'B');
    return 0;
}

void moveTower(int height, char fromPeg, char toPeg, char usingPeg) {
    if (height <= 0) {
        return;
    }
    moveTower(height-1, fromPeg, usingPeg, toPeg);
    printf("Move disk %d from peg %c to peg %c\n", height, fromPeg, toPeg);
    moveTower(height-1, usingPeg, toPeg, fromPeg);
}