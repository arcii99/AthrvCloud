//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: grateful
#include <stdio.h>

void move(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Move disk from %c to %c\n", source, target);
        return;
    }
    move(n - 1, source, auxiliary, target);
    printf("Move disk from %c to %c\n", source, target);
    move(n - 1, auxiliary, target, source);
}

int main() {
    int n;
    printf("Welcome to the Tower of Hanoi game!\n");
    printf("Please enter the number of disks: ");
    scanf("%d", &n);

    printf("Here are the steps to solve the problem:\n");
    move(n, 'A', 'C', 'B');

    printf("Congratulations, you have solved the puzzle!\n");
    printf("Thank you for playing the Tower of Hanoi game!\n");

    return 0;
}