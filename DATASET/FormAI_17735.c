//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: recursive
#include <stdio.h>

void tower_of_hanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
    } else {
        tower_of_hanoi(n-1, from_rod, aux_rod, to_rod);
        printf("Move disk %d from rod %c to rod %c\n", n, from_rod, to_rod);
        tower_of_hanoi(n-1, aux_rod, to_rod, from_rod);
    }
}

int main() {
    int n = 4;
    tower_of_hanoi(n, 'A', 'C', 'B');  
    return 0;
}