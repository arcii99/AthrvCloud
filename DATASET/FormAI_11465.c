//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: medieval
#include <stdio.h>

void move(char from, char to) {
    printf("Move ring from %c to %c.\n", from, to);
}

void solve(int rings, char from, char to, char aux) {
    if (rings == 1) {
        move(from, to);
    } else {
        solve(rings - 1, from, aux, to);
        move(from, to);
        solve(rings - 1, aux, to, from);
    }
}

int main() {
    int num_rings = 5;
    char peg_a = 'A', peg_c = 'C', peg_b = 'B';
    printf("Welcome to the Tower of Hanoi game!\n\n");
    printf("You have %d rings on Peg A and your goal is to move them to Peg C, using Peg B as an auxiliary peg.\n", num_rings);
    printf("Let's get started...\n\n");
    solve(num_rings, peg_a, peg_c, peg_b);
    printf("\nCongratulations, you successfully completed the game!\n");
    return 0;
}