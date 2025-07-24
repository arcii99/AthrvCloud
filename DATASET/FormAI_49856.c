//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: modular
#include <stdio.h>
#include <stdlib.h>

void move(int n, char A, char B, char C) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", A, C);
        return;
    }
    move(n-1, A, C, B);
    printf("Move disk %d from rod %c to rod %c\n", n, A, C);
    move(n-1, B, A, C);
}

int main() {
    int n = 3; // Number of disks
    move(n, 'A', 'B', 'C');
    return 0;
}