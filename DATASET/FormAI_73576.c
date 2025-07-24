//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Create an array of conspiracy theories
    char *theories[] = {
        "The moon landing was faked.",
        "The government is hiding evidence of extraterrestrial life.",
        "Chemtrails are causing a global health crisis.",
        "The Illuminati control the world's governments.",
        "The Earth is flat.",
        "Vaccines have dangerous side effects.",
        "9/11 was an inside job.",
        "The CIA killed JFK."
    };

    // Generate a random seed based on the current time
    srand(time(NULL));

    // Choose a random conspiracy theory from the array
    int idx = rand() % (sizeof(theories) / sizeof(theories[0]));
    char *theory = theories[idx];

    // Print the theory
    printf("Did you know that %s?\n", theory);

    // Generate a second random seed based on the current time, to decide whether to add a twist
    srand(time(NULL) + 1);
    int twist_roll = rand() % 10;
    if (twist_roll > 7) {
        // Choose a random twist from the array
        char *twists[] = {
            "But that's just what they want you to think...",
            "Think about it for a second.",
            "You'll never hear this on the news, but...",
        };
        idx = rand() % (sizeof(twists) / sizeof(twists[0]));
        char *twist = twists[idx];

        // Print the twist
        printf("%s\n", twist);
    }

    return 0;
}