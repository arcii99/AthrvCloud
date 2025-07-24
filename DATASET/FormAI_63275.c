//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: shocked
#include <stdio.h>

void towerOfHanoi(int disk, char source, char temp, char dest) {
    if(disk == 1) {
        printf("\n Move disk 1 from peg %c to peg %c", source, dest);
        return;
    }
    towerOfHanoi(disk-1, source, dest, temp);
    printf("\n Move disk %d from peg %c to peg %c", disk, source, dest);
    towerOfHanoi(disk-1, temp, source, dest);
}

int main() {
    int disks;
    char source = 'A', temp = 'B', dest = 'C';

    printf("Enter the number of disks: ");
    scanf("%d", &disks);

    printf("The steps for moving %d disks from source %c to destination %c are: \n", disks, source, dest);

    towerOfHanoi(disks, source, temp, dest);
    return 0;
}