//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CONSPIRACY_THEORIES 5

void generate_random_conspiracy_theory();

int main() {
    srand(time(NULL));  // Seed random number generator
    
    // Loop through NUM_CONSPIRACY_THEORIES times and generate a random conspiracy theory
    for (int i = 0; i < NUM_CONSPIRACY_THEORIES; i++) {
        generate_random_conspiracy_theory();
        printf("\n");
    }
    
    return 0;
}

// Generates and prints a random conspiracy theory
void generate_random_conspiracy_theory() {
    int random_num = rand() % 5;  // Generate random number between 0-4
    
    // Conspiracy theories
    char *theories[5] = {
        "The moon landing was faked by the government.",
        "The Earth is flat and the government is hiding it from us.",
        "The Illuminati control the world's governments.",
        "The government is hiding the existence of extraterrestrial life.",
        "9/11 was an inside job orchestrated by the government."
    };
    
    // Evidence (real or fake)
    char *evidence[5] = {
        "classified documents obtained through a leak",
        "eyewitness testimonies from anonymous sources",
        "a photo that was manipulated to show what they want you to see",
        "a video that was edited to hide the truth",
        "a piece of paper found in a dumpster behind a government building"
    };
    
    // Organizations involved (real or fake)
    char *organizations[5] = {
        "the CIA",
        "the FBI",
        "the NSA",
        "the CDC",
        "the Illuminati"
    };
    
    printf("Conspiracy Theory #%d: ", random_num+1);
    printf("%s\n", theories[random_num]);
    printf("Evidence: %s\n", evidence[rand() % 5]);
    printf("Organization involved: %s\n", organizations[rand() % 5]);
}