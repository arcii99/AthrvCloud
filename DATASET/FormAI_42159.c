//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>

void move(int n, char start, char end, char temp) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", start, end);
        return;
    }
    move(n-1, start, temp, end);
    printf("Move disk %d from rod %c to rod %c\n", n, start, end);
    move(n-1, temp, end, start);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    move(n, 'A', 'C', 'B');
}