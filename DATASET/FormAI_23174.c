//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>

void moveBlocks(int count, char source, char destination, char spare) {
    if(count == 1) {
        printf("Move disk 1 from %c to %c\n", source, destination);
        return;
    }
    moveBlocks(count - 1, source, spare, destination);
    printf("Move disk %d from %c to %c\n", count, source, destination);
    moveBlocks(count - 1, spare, destination, source);
}

int main() {
    int numOfBlocks = 4;
    printf("Welcome to the Tower of Hanoi! \n");
    printf("We are going to move %d blocks from Tower A to Tower C. \n", numOfBlocks);
    moveBlocks(numOfBlocks, 'A', 'C', 'B');
    printf("All blocks moved successfully! \n");
    return 0;
}