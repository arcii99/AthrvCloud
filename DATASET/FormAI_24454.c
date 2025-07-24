//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: paranoid
#include <stdio.h>

void moveDisk(char from, char to, int disk);
void hanoi(int disks, char from, char to, char temp);

int main() {
    int disks = 4;
    char from = 'A';
    char to = 'C';
    char temp = 'B';
    char password[50];

    printf("Welcome to the Tower of Hanoi Puzzle Game.\n");
    printf("Please enter the password to start the game: ");
    fgets(password, 50, stdin);

    if (strcmp(password, "TowerOfHanoi123\n") == 0) {
        printf("Password accepted. Starting game...\n");
        hanoi(disks, from, to, temp);
        printf("Congratulations! You solved the puzzle!\n");
    } else {
        printf("Access Denied. Incorrect password.\n");
    }

    return 0;
}

void moveDisk(char from, char to, int disk) {
    printf("Move disk %d from peg %c to peg %c\n", disk, from, to);
}

void hanoi(int disks, char from, char to, char temp) {
    if (disks == 1) {
        moveDisk(from, to, disks);
        return;
    }
    hanoi(disks - 1, from, temp, to);
    moveDisk(from, to, disks);
    hanoi(disks - 1, temp, to, from);
}