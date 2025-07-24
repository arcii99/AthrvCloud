//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
/******************************************************************************
* Tower of Hanoi Program in Linux Torvalds style                                 
*******************************************************************************/

#include <stdio.h>

void move(int n, char source, char destination, char aux) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    move(n-1, source, aux, destination);
    printf("Move disk %d from %c to %c\n", n, source, destination);
    move(n-1, aux, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Tower of Hanoi solution for %d disks:\n", n);
    move(n, 'A', 'C', 'B');
    return 0;
}