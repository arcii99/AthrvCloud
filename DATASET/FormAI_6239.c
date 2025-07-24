//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: irregular
#include <stdio.h>

void hanoi(int n, char from, char to, char aux) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c.\n", from, to);
        return;
    }
    hanoi(n-1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c.\n", n, from, to);
    hanoi(n-1, aux, to, from);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The steps to solve the Tower of Hanoi problem for %d disks are:\n", n);
    hanoi(n, 'A', 'C', 'B');
    return 0;
}