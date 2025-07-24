//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>

void tower_of_hanoi(int discs, char from_rod, char to_rod, char aux_rod) {
    if (discs == 1) {
        printf("Move disc 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    tower_of_hanoi(discs - 1, from_rod, aux_rod, to_rod);
    printf("Move disc %d from rod %c to rod %c\n", discs, from_rod, to_rod);
    tower_of_hanoi(discs - 1, aux_rod, to_rod, from_rod);
}

int main() {
    int num_discs;
    printf("Enter the number of discs: ");
    scanf("%d", &num_discs);
    tower_of_hanoi(num_discs, 'A', 'C', 'B');
    return 0;
}