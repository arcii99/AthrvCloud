//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void generateConspiracy();

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate 10 conspiracy theories
    for (int i = 0; i < 10; i++) {
        generateConspiracy();
        printf("\n"); // Add a newline after each conspiracy theory
    }

    return 0;
}

void generateConspiracy() {
    // Arrays of possible conspiracy theories
    char* theories[] = {
        "The moon landing was faked by the government to win the space race.",
        "The Titanic never sank and was actually its sister ship, the Olympic, that was purposefully sunk for insurance fraud.",
        "The government is controlling our minds through chemtrails from airplanes.",
        "The Illuminati control the world and orchestrate major events to benefit themselves.",
        "The Earth is flat and NASA is hiding the truth from us with fake photos and information.",
        "The government is hiding evidence of extraterrestrial life from us.",
        "The JFK assassination was a government conspiracy involving multiple people.",
        "911 was an inside job orchestrated by the US government.",
        "The pharmaceutical industry is hiding cures from us to make more money.",
        "Climate change is a hoax perpetrated by scientists to secure more funding."
    };
    char* culprits[] = {
        "the government",
        "the Illuminati",
        "big pharma",
        "NASA",
        "the Vatican",
        "the military industrial complex",
        "the New World Order",
        "the deep state",
        "the Bilderberg Group",
        "the Rothschilds"
    };
    char* evidence[] = {
        "secret documents leaked by a whistleblower",
        "eye-witness accounts from insiders",
        "analysis of hidden messages in popular media",
        "patterns in historical events",
        "anomalies in scientific data",
        "strange coincidences among world leaders"
    };
    char* outcomes[] = {
        "mass panic and distrust of authority",
        "a popular uprising against the culprits",
        "global chaos and destruction",
        "a new world order controlled by the conspirators",
        "the end of civilization as we know it",
        "total economic collapse"
    };

    // Generate a random index for each array
    int theoryIndex = rand() % 10;
    int culpritIndex = rand() % 10;
    int evidenceIndex = rand() % 6;
    int outcomeIndex = rand() % 6;

    // Print the conspiracy theory
    printf("Did you know that %s is actually a plot by %s to %s? They have %s to prove it!", theories[theoryIndex], culprits[culpritIndex], outcomes[outcomeIndex], evidence[evidenceIndex]);
}