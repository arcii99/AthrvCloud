//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: curious
#include <stdio.h>

// a structure to represent a disk
struct Disk {
    int size;
};

// function to move disk from source to destination peg
void moveDisk(char source, char destination, struct Disk disk) {
    printf("Moved disk %d from peg %c to peg %c\n", disk.size, source, destination);
}

// recursive function to solve Tower of Hanoi puzzle
void toh(int numDisks, struct Disk source[], struct Disk destination[], struct Disk temp[]) {
    // base case
    if (numDisks == 0) {
        return;
    }

    // move top n-1 disks from source to temp peg
    toh(numDisks - 1, source, temp, destination);

    // move bottom disk from source to destination peg
    moveDisk('A', 'B', source[numDisks - 1]);

    // move top n-1 disks from temp peg to destination peg
    toh(numDisks - 1, temp, destination, source);
}

int main() {
    // initialize disks
    struct Disk disk1 = {1};
    struct Disk disk2 = {2};
    struct Disk disk3 = {3};

    // create pegs
    struct Disk pegA[3] = {disk1, disk2, disk3};
    struct Disk pegB[3] = {};
    struct Disk pegC[3] = {};

    // solve Tower of Hanoi puzzle
    toh(3, pegA, pegB, pegC);

    return 0;
}