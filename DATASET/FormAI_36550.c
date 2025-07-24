//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Cyberpunk
#include <stdio.h>

void move(int disks, int source, int target, int spare) {
    if(disks == 1) {
    printf("Moving disk %d from pole %d to pole %d\n", disks, source, target);
    return;
    }
    move(disks-1, source, spare, target);
    printf("Moving disk %d from pole %d to pole %d\n", disks, source, target);
    move(disks-1, spare, target, source);
}

int main() {
    int disks = 3, source = 1, target = 3, spare = 2;
    printf("Welcome to the Tower of Hanoi!\n");
    printf("You are a hacker tasked with cracking an encrypted file using the Tower of Hanoi. The encrypted file is stored in disk 1, while the decryption key is stored in disk 3.\n");
    printf("You must move all the disks from pole 1 to pole 3 in order to obtain the key and unlock the file.\n");
    move(disks, source, target, spare);
    printf("Congratulations, you have successfully obtained the decryption key and unlocked the file. Happy hacking!\n");
    return 0;
}