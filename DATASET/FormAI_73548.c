//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>

void hanoi(int n, char start, char dest, char aux);

int main() {
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    hanoi(n, 'A', 'C', 'B');

    return 0;
}

void hanoi(int n, char start, char dest, char aux) {
    if(n == 1) {
        printf("Move disk 1 from %c to %c\n", start, dest);
        return;
    }

    hanoi(n-1, start, aux, dest);

    printf("Move disk %d from %c to %c\n", n, start, dest);

    hanoi(n-1, aux, dest, start);
}