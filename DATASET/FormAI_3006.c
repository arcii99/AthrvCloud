//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: ultraprecise
#include <stdio.h>

void transfer(int n, char source, char auxiliary, char target) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, target);
        return;
    }
    transfer(n - 1, source, target, auxiliary);
    printf("Move disk %d from %c to %c\n", n, source, target);
    transfer(n - 1, auxiliary, source, target);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    transfer(n, 'A', 'B', 'C');
    return 0;
}