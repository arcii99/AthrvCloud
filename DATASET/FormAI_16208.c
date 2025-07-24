//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

void tower_of_hanoi(int n, char A, char C, char B) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", A, C);
        return;
    }
    tower_of_hanoi(n - 1, A, B, C);
    printf("Move disk %d from rod %c to rod %c\n", n, A, C);
    tower_of_hanoi(n - 1, B, C, A);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}