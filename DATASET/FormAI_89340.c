//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random number generation
    int random = rand() % 4; // Generates a random number between 0-3
    char *theory; // String to hold the conspiracy theory

    // Switch statement to generate a random conspiracy theory
    switch (random) {
        case 0:
            theory = "The knights of the Order of the Dragon are secretly controlling the King's decisions.";
            break;
        case 1:
            theory = "The Black Death was intentionally spread by the Church to control the population.";
            break;
        case 2:
            theory = "The Lady of the Lake is actually a witch who cursed King Arthur's Sword to break in the final battle.";
            break;
        case 3:
            theory = "The King's advisor is a warlock who is using dark magic to influence the court's decisions.";
            break;
    }

    // Print the conspiracy theory
    printf("Did you hear? %s\n", theory);

    return 0;
}