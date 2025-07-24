//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: peaceful
#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod);

int count_steps = 0; // counting total number of steps to solve problem

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    printf("Solving Tower of Hanoi problem for %d disks...\n", n);
    tower_of_hanoi(n, 'A', 'C', 'B');
    printf("\nTotal number of steps taken to solve the problem: %d\n", count_steps);

    return 0;
}

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    count_steps++; // incrementing number of steps count
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
    printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
}