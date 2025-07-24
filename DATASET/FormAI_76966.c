//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: genious
#include <stdio.h>
#include <stdlib.h>

void towerOfHanoi(int n, char source, char aux, char dest) {
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", source, dest);
        return;
    }
    towerOfHanoi(n-1, source, dest, aux);
    printf("Move disk %d from %c to %c\n", n, source, dest);
    towerOfHanoi(n-1, aux, source, dest);
}

int main() {
    int n;
    printf("Welcome to the Tower of Hanoi!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &n);
    if (n < 1) {
        printf("Invalid input. Please enter a number greater than 0.\n");
        return 1;
    }
    printf("The optimal solution for %d disks is:\n", n);
    towerOfHanoi(n, 'A', 'B', 'C');
    printf("Thanks for playing!\n");
    return 0;
}