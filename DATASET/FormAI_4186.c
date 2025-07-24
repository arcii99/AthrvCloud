//FormAI DATASET v1.0 Category: Tower of Hanoi Problem ; Style: statistical
#include <stdio.h>

int moves = 0;

void tower_of_hanoi(int discs, char source, char auxiliary, char destination) {
    if (discs == 1) {
        printf("Move disk from %c to %c\n", source, destination);
        moves++; // increment the number of moves
        return;
    }

    tower_of_hanoi(discs - 1, source, destination, auxiliary);
    printf("Move disk from %c to %c\n", source, destination);
    moves++; // increment the number of moves
    tower_of_hanoi(discs - 1, auxiliary, source, destination);
}

int main() {
    int discs;
    printf("Enter the number of discs: ");
    scanf("%d", &discs);

    printf("Tower of Hanoi solution for %d discs:\n", discs);
    tower_of_hanoi(discs, 'A', 'B', 'C');

    printf("Total moves: %d\n", moves);

    return 0;
}