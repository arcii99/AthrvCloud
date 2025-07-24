//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    char *theories[] = { 
        "The government is controlled by reptilian aliens.",
        "Chemtrails are used to control the population.",
        "The moon landing was faked.",
        "9/11 was an inside job.",
        "COVID-19 was created in a lab.",
        "The world is run by a secret society.",
        "The Illuminati controls everything.",
        "Area 51 is hiding evidence of extraterrestrial life."
    };

    srand(time(NULL));
    int random_index = rand() % 8;  // select a random conspiracy theory
    printf("Random conspiracy theory: %s\n", theories[random_index]);

    return 0;
}