//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>

void move_disc(int disc, char start, char middle, char end) {
    if (disc == 1) {
        printf("Move disc 1 from %c to %c\n", start, end);
    } else {
        move_disc(disc-1, start, end, middle);
        printf("Move disc %d from %c to %c\n", disc, start, end);
        move_disc(disc-1, middle, start, end);
    }
}

int main() {
    int num_discs;
    printf("Welcome to the Tower of Hanoi problem solver!\n");
    printf("How many discs do you want to move?\n");
    scanf("%d", &num_discs);
    printf("Here's how to solve the problem for %d discs:\n", num_discs);
    move_disc(num_discs, 'A', 'B', 'C');
    printf("Congratulations! The problem has been solved.\n");
    return 0;
}