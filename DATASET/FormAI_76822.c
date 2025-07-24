//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool is_valid_int(char* str) {
    while (*str) {
        if (!isdigit(*str++))
            return false;
    }
    return true;
}

int roll_dice(int sides) {
    return rand() % sides + 1;
}

int main(int argc, char* argv[]) {
    srand(time(NULL));

    if (argc != 2 || !is_valid_int(argv[1])) {
        printf("Usage: %s <number of sides>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sides = atoi(argv[1]);
    printf("Rolling a %d-sided dice...\n\n", sides);
    printf("Result: %d\n", roll_dice(sides));

    return EXIT_SUCCESS;
}