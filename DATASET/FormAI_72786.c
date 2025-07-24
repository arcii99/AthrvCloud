//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: authentic
#include <stdio.h>

void move(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from, to);
        return;
    }
    move(n-1, from, aux, to);
    printf("Move disk %d from rod %c to rod %c\n", n, from, to);
    move(n-1, aux, to, from);
}

int main() {
    int n = 3;
    move(n, 'A', 'C', 'B');
    return 0;
}