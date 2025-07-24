//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>

void hanoi(int n, char start, char middle, char end) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", start, end);
        return;
    }
    hanoi(n-1, start, end, middle);
    printf("Move disk %d from %c to %c\n", n, start, end);
    hanoi(n-1, middle, start, end);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    hanoi(n, 'A', 'B', 'C');
    return 0;
}