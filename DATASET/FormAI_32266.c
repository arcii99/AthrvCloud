//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include<stdio.h>
#include<stdlib.h>

int count = 0; // Keeping track of the number of moves

void TOH(int n, char from_rod, char to_rod, char aux_rod) {
    if(n == 1) {
        count++;
        printf("%d. Move disk 1 from %c rod to %c rod\n", count, from_rod, to_rod);
        return;
    }
    TOH(n - 1, from_rod, aux_rod, to_rod);
    count++;
    printf("%d. Move disk %d from %c rod to %c rod\n", count, n, from_rod, to_rod);
    TOH(n - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("\nTower of Hanoi Solution for %d disks:\n\n", n);
    TOH(n, 'A', 'C', 'B');
    return 0;
}