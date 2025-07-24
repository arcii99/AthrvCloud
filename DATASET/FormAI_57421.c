//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// Function prototypes
void printHeader();
void generateConspiracy();
void generateOrganization();
void generateEvent();
void generateTheorist();
void generateLocation();
void generateEvidence();

// Main function
int main() {
    printHeader();

    // Seed random number generator
    srand(time(NULL));

    // Generate conspiracy
    generateConspiracy();

    return 0;
}

// Function to print program header
void printHeader() {
    printf("+------------------------------------+\n");
    printf("|  Random Conspiracy Theory Generator |\n");
    printf("+------------------------------------+\n");
    printf("\n");
}

// Function to generate conspiracy
void generateConspiracy() {
    printf("According to new information discovered by a group of anonymous researchers, ");
    generateOrganization();
    printf(" has been planning ");
    generateEvent();
    printf(" in order to ");
    generateTheorist();
    printf(". This dangerous plot is set to take place in ");
    generateLocation();
    printf(".\n\n");

    printf("The evidence to support this conspiracy is overwhelming, including ");
    generateEvidence();
    printf(".\n\n");

    printf("Spread the word and stay vigilant!\n");
}

// Function to generate organization
void generateOrganization() {
    const char* organizations[] = {
        "the Illuminati",
        "the New World Order",
        "the Deep State",
        "the Bilderberg Group",
        "the Freemasons",
        "the Rothschild family"
    };
    int len = sizeof(organizations) / sizeof(organizations[0]);
    int index = rand() % len;

    printf("%s", organizations[index]);
}

// Function to generate event
void generateEvent() {
    const char* events[] = {
        "a global pandemic",
        "a terrorist attack",
        "a financial collapse",
        "a natural disaster",
        "an alien invasion",
        "a world war"
    };
    int len = sizeof(events) / sizeof(events[0]);
    int index = rand() % len;

    printf("%s", events[index]);
}

// Function to generate theorist
void generateTheorist() {
    const char* theorists[] = {
        "maintain their control over the population",
        "reduce the world's population",
        "establish a one-world government",
        "enrich themselves and their cronies",
        "usher in a new age of darkness",
        "serve their extraterrestrial overlords"
    };
    int len = sizeof(theorists) / sizeof(theorists[0]);
    int index = rand() % len;

    printf("%s", theorists[index]);
}

// Function to generate location
void generateLocation() {
    const char* locations[] = {
        "the White House",
        "the Vatican",
        "Area 51",
        "the Federal Reserve",
        "the United Nations",
        "a secret underground bunker"
    };
    int len = sizeof(locations) / sizeof(locations[0]);
    int index = rand() % len;

    printf("%s", locations[index]);
}

// Function to generate evidence
void generateEvidence() {
    const char* evidence[] = {
        "leaked documents",
        "whistleblower testimony",
        "cryptic social media posts",
        "anomalous satellite images",
        "unexplained sightings",
        "ancient prophecies"
    };
    int len = sizeof(evidence) / sizeof(evidence[0]);

    bool selected[len];
    memset(selected, false, sizeof(selected));

    int numSelected = 0;
    while (numSelected < 3) {
        int index = rand() % len;

        if (!selected[index]) {
            printf("%s", evidence[index]);
            selected[index] = true;
            numSelected++;
            if (numSelected < 3) {
                printf(", ");
            }
        }
    }
}