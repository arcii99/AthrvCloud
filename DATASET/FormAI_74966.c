//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    srand(time(NULL)); // seeding the random number generator with current time
    int num_theories = 10; // number of conspiracy theories to generate
    char* theories[] = {
        "The government is using chemtrails to control the population.",
        "The moon landing was faked by the Illuminati.",
        "The Earth is flat and the government is hiding the truth.",
        "Aliens have been living among us for centuries.",
        "The Illuminati controls the world through secret societies.",
        "The government is hiding the cure for cancer.",
        "Social media is a tool for mind control.",
        "The COVID-19 pandemic was intentionally created.",
        "The Bilderberg Group is behind all major world events.",
        "Elvis Presley is still alive and in hiding."
    };

    // generating random conspiracy theories
    for (int i = 0; i < num_theories; i++) {
        int random_index = rand() % num_theories; // getting a random index
        printf("%d. %s\n", i+1, theories[random_index]);
    }

    printf("There you have it! Don't believe everything you hear...\n");
    return 0;
}