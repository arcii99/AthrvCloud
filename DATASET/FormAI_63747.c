//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

void move(char from, char to) {
    printf("Move disk from %c to %c\n", from, to);
}

void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        move(source, destination);
        return;
    }
    towerOfHanoi(n-1, source, destination, auxiliary);
    move(source, destination);
    towerOfHanoi(n-1, auxiliary, source, destination);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}