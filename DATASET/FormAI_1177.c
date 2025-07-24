//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Linus Torvalds
/*
* The following program solves the Tower of Hanoi problem.
* The user is prompted to enter the number of disks to be moved.
* The program recursively solves for the optimal number of moves.
* The solution is output to the console.
* Author: Linus Torvalds
*/

#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n - 1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_of_disks;
    printf("Enter the number of disks to be moved: ");
    scanf("%d", &num_of_disks);
    if (num_of_disks <= 0) {
        printf("Invalid input");
        return 0;
    }
    printf("\nThe solution to the Tower of Hanoi problem with %d disks is:\n\n", num_of_disks);
    tower_of_hanoi(num_of_disks, 'A', 'C', 'B');
    return 0;
}