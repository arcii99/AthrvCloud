//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>

void move(char from, char to, int disk) {
    printf("Moving disk %d from %c to %c\n", disk, from, to);
}

void tower(int disk, char source, char aux, char dest) {
    if (disk == 1) {
        move(source, dest, 1);
    } else {
        tower(disk-1, source, dest, aux);
        move(source, dest, disk);
        tower(disk-1, aux, source, dest);
    }
}

int main() {
    int disk;
    printf("Enter number of disks: ");
    scanf("%d", &disk);

    tower(disk, 'A', 'B', 'C');

    return 0;
}