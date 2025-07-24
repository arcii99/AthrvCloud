//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: careful
#include <stdio.h>

void towerOfHanoi(int n, char start, char end, char middle) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", start, end);
        return;
    }
    
    towerOfHanoi(n-1, start, middle, end);
    printf("Move disk %d from %c to %c\n", n, start, end);
    towerOfHanoi(n-1, middle, end, start);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}