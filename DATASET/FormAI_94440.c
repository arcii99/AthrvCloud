//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char* conspiracy_theories[] = {
    "The moon landing was actually filmed in a studio on Mars.",
    "The government controls the weather with a secret machine.",
    "The Earth is actually flat and the round Earth theory is a hoax.",
    "The Illuminati run the world behind the scenes.",
    "COVID-19 was created in a lab as a form of population control.",
    "Aliens have been living among us for centuries.",
    "The Bermuda Triangle is a portal to another dimension.",
    "Mandela Effect proves that we are living in a parallel universe.",
    "The world is controlled by a secret society of lizard people."
};

int main(void) {
    srand(time(NULL)); // seed the random number generator with the current time
    int conspiracy_index = rand() % 9; // generate a random index to select a conspiracy theory
    
    printf("Did you know that: %s\n\n", conspiracy_theories[conspiracy_index]);
    
    return 0;
}