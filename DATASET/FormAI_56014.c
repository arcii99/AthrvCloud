//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: funny
#include<stdio.h>
#include<stdlib.h>

void toh(int, char, char, char);

int main() {

    int n = 3;
    char A='A', B='B', C='C';
    printf("Welcome to the Tower of Hanoi Game!\n");
    printf("Your Goal: Move all disks from post A to post C\n");
    printf("Rules: You can only move one disk at a time\n");
    printf("A larger disk cannot be placed on a smaller disk\n");
    printf("Let's Begin!!!\n\n");
    printf("There are %d disks on post A (largest at the bottom)\n\n", n);

    toh(n,A,C,B);

    printf("\nCongratulations! You have won the Tower of Hanoi Game!\n");

    return 0;
}

void toh(int n, char from, char to, char aux) {
    if (n == 1) {
        printf("Move disk 1 from post %c to post %c\n", from, to);
        return;
    }
    toh(n-1, from, aux, to);
    printf("Move disk %d from post %c to post %c\n", n, from, to);
    toh(n-1, aux, to, from);
}