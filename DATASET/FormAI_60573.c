//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int ghosts_count = rand() % 10 + 1;
    int distance_to_exit = rand() % 100 + 1;
    int steps_taken = 0;
    int current_position = 0;
    int ghosts_found = 0;

    printf("*** Welcome to the Haunted House Simulator ***\n");
    printf("Your goal is to escape the haunted house by walking %d steps without encountering %d ghosts.\n", distance_to_exit, ghosts_count);

    while (steps_taken < distance_to_exit) {
        int encounter = rand() % 4 + 1;
        if (encounter == 1) {
            printf("You hear a ghostly moan...\n");
            ghosts_found++;
            if (ghosts_found == ghosts_count) {
                printf("You have encountered too many ghosts... You lose!\n");
                return 0;
            }
        } else {
            printf("You take a step forward...\n");
            current_position++;
            steps_taken++;
            if (current_position == distance_to_exit) {
                printf("Congratulations! You have escaped the haunted house!\n");
                return 0;
            }
        }
    }

    printf("You have reached the maximum number of steps without escaping... You lose!\n");
    return 0;
}