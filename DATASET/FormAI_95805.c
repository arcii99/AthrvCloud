//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>

// Function to calculate the total number of moves for n disks
int calculateTotalMoves(int n) {
    return (1 << n) - 1;
}

// Function to move disks from source to destination using auxiliary tower
void moveDisks(int n, char source, char destination, char auxiliary) {
    if(n == 0) {
        return;
    }
    moveDisks(n-1, source, auxiliary, destination);
    printf("%d. Move disk %d from %c to %c\n", calculateTotalMoves(n), n, source, destination);
    moveDisks(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Total number of moves required to solve the problem for %d disks is: %d\n", n, calculateTotalMoves(n));
    moveDisks(n, 'A', 'C', 'B');
    return 0;
}