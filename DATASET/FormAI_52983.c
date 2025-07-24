//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>

void move(int n, char source, char destination, char auxiliary) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", source, destination);
        return;
    }
    move(n-1, source, auxiliary, destination);
    printf("Move disk %d from rod %c to rod %c\n", n, source, destination);
    move(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);
    printf("The sequence of steps involved in solving the Tower of Hanoi problem for %d disks:\n", n);
    move(n, 'A', 'C', 'B');
    return 0;
}