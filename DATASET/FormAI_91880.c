//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: configurable
#include<stdio.h>

void hanoi(int n, char fromRod, char toRod, char auxRod) {
    if(n == 1) {
        printf("Move disk 1 from rod %c to rod %c\n", fromRod, toRod);
        return;
    }
    hanoi(n-1, fromRod, auxRod, toRod);
    printf("Move disk %d from rod %c to rod %c\n", n, fromRod, toRod);
    hanoi(n-1, auxRod, toRod, fromRod);
}

int main() {
    int n = 3; // Number of disks
    char fromRod = 'A', toRod = 'C', auxRod = 'B';
    
    printf("Tower of Hanoi problem for %d disks\n", n);
    hanoi(n, fromRod, toRod, auxRod);

    return 0;
}