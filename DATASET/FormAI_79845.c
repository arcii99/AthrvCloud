//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: thoughtful
#include <stdio.h>

void moveTower(int height, char from, char to, char intermediate) {
    if (height >= 1) {
        moveTower(height - 1, from, intermediate, to);
        printf("Move disk %d from %c to %c\n", height, from, to);
        moveTower(height - 1, intermediate, to, from);
    }
}

int main() {
    int height;

    printf("Enter the number of disks: ");
    scanf("%d", &height);

    moveTower(height, 'A', 'C', 'B');

    return 0;
}