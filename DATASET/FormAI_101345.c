//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>

void moveDisc(int n, int start, int end) {
    printf("Move disc %d from Tower %d to Tower %d\n", n, start, end);
}

void TowerOfHanoi(int n, int start, int end, int middle) {
    if (n == 1) {
        moveDisc(n, start, end);
        return;
    }
    TowerOfHanoi(n - 1, start, middle, end);
    moveDisc(n, start, end);
    TowerOfHanoi(n - 1, middle, end, start);
}

int main() {
    int n;
    printf("Enter the number of discs in Tower of Hanoi: ");
    scanf("%d", &n);
    TowerOfHanoi(n, 1, 3, 2);
    return 0;
}