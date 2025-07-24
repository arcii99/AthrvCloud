//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACY_THEORIES 10
#define MAX_CONSPIRACY_LENGTH 1000

int main(int argc, char *argv[]) {
    // Set up variables
    char conspiracyTheories[MAX_CONSPIRACY_THEORIES][MAX_CONSPIRACY_LENGTH];
    bool isCustom = false;
    bool outputAll = false;
    int numTheories = 0;
    int i;

    // Set up random number generator
    srand(time(NULL));

    // Fill in conspiracyTheories array with default conspiracy theories
    strcpy(conspiracyTheories[0], "The moon landing was faked.");
    strcpy(conspiracyTheories[1], "The government is controlling our minds through the media.");
    strcpy(conspiracyTheories[2], "Vaccines cause autism.");
    strcpy(conspiracyTheories[3], "The Illuminati control the world.");
    strcpy(conspiracyTheories[4], "9/11 was an inside job.");
    numTheories += 5;

    // Check command line arguments for custom conspiracy theories
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-c") == 0) {
            isCustom = true;
            continue;
        }

        if (strcmp(argv[i], "-a") == 0) {
            outputAll = true;
            continue;
        }

        if (isCustom && numTheories < MAX_CONSPIRACY_THEORIES) {
            strcpy(conspiracyTheories[numTheories], argv[i]);
            numTheories++;
        }
    }

    // Generate conspiracy theories
    if (outputAll) {
        for (i = 0; i < numTheories; i++) {
            printf("%s\n", conspiracyTheories[i]);
        }
    } else {
        printf("%s\n", conspiracyTheories[rand() % numTheories]);
    }

    return 0;
}