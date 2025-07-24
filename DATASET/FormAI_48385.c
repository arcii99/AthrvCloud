//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: surrealist
#include <stdio.h>

void move(int discs, char fromPole, char toPole, char withPole) {
    if (discs == 1) {
        printf("Take disc 1 from %c to %c\n", fromPole, toPole);
    } else {
        move(discs - 1, fromPole, withPole, toPole);
        printf("Take disc %d from %c to %c\n", discs, fromPole, toPole);
        move(discs - 1, withPole, toPole, fromPole);
    }
}

int main() {
    int discs;

    printf("Welcome to the Surrealist Tower of Hanoi Problem!\n");
    printf("Enter the number of discs: ");
    scanf("%d", &discs);

    if (discs < 1) {
        printf("Invalid number of discs!\n");
        return 1;
    }

    printf("The solution to the Tower of Hanoi Problem with %d discs is:\n", discs);
    move(discs, 'A', 'C', 'B');

    printf("Congratulations, you have solved the problem!\n");

    return 0;
}