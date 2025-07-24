//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: decentralized
#include <stdio.h>

// function to solve tower of Hanoi problem
void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) { // base case
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod); // recursion step
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod); // recursion step
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("The steps to solve the Tower of Hanoi problem with %d disks are:\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}