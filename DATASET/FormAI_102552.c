//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 200

char* conspiracy_ideas[] = {
    "The government is controlling our minds with chemtrails",
    "Aliens are secretly running the world",
    "Elvis Presley faked his own death",
    "The moon landing was a hoax",
    "9/11 was an inside job",
    "The earth is flat and the government is covering it up",
    "The Illuminati is controlling everything",
    "Vaccines are actually harmful to our health",
    "The world is actually run by lizard people"
};

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Generate a random conspiracy
    int conspiracy_index = rand() % (sizeof(conspiracy_ideas) / sizeof(char*));
    char* conspiracy = conspiracy_ideas[conspiracy_index];

    // Add some extra details to the conspiracy
    char extra_details[MAX_CONSPIRACY_LENGTH];
    sprintf(extra_details, " and %d%% of people don't even know it!", rand() % 100);

    // Print out the full conspiracy theory
    printf("Did you know that %s%s\n", conspiracy, extra_details);

    return 0;
}