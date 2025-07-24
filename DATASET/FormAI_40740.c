//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surprised
#include <stdio.h>

// function to shift the disk from source to destination tower
void shift(int disks, char source, char temp, char dest) {
    if (disks == 1) {
        printf("Moved disk 1 from %c to %c\n", source, dest);
        return;
    }
    // move disks - 1 from source to temp using destination tower as auxiliary
    shift(disks - 1, source, dest, temp);
    printf("Moved disk %d from %c to %c\n", disks, source, dest);
    // finally move disks - 1 from temp to destination using source tower as auxiliary
    shift(disks - 1, temp, source, dest);
}

int main() {
    int disks;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("How many disks do you want to play with? ");
    scanf("%d", &disks);
    if (disks < 1) {
        printf("No game with less than 1 disk. Goodbye!\n");
        return 1;
    }
    printf("Alright! Let's play!\n");
    // start the game
    shift(disks, 'A', 'B', 'C');
    printf("Congratulations! You've successfully completed the game with %d disks!\n", disks);
    return 0;
}