//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shape shifting
#include <stdio.h>

void move(char from, char to, int disks) {
    printf("Move %d disks from %c to %c\n", disks, from, to);
}

void towerOfHanoi(char source, char aux, char dest, int disks) {
    if (disks == 1) {
        move(source, dest, disks);
        return;
    }
    towerOfHanoi(source, dest, aux, disks-1);
    move(source, dest, disks);
    towerOfHanoi(aux, source, dest, disks-1);
}

int main() {
    int num_disks = 4;
    char source = 'A';
    char aux = 'B';
    char dest = 'C';
    printf("Solving Tower of Hanoi for %d disks\n", num_disks);
    towerOfHanoi(source, aux, dest, num_disks);
    printf("Solution complete!\n");
    return 0;
}