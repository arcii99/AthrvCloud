//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

void move(char from, char to) {
    printf("Move disk from %c to %c\n", from, to);
}

void hanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        move(source, destination);
    } else {
        hanoi(n - 1, source, destination, auxiliary);
        move(source, destination);
        hanoi(n - 1, auxiliary, source, destination);
    }
}

int main() {
    int num_disks = 5;
    printf("Welcome to the Tower of Hanoi problem!\n");
    printf("In this example, we have %d disks.\n", num_disks);
    printf("Let's move them from source pillar A to destination pillar C.\n");
    hanoi(num_disks, 'A', 'B', 'C');
    printf("All disks successfully moved from A to C!\n");
    return 0;
}