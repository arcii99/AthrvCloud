//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed the randomization with time
    char* theories[] = { // Array of conspiracy theories
        "The moon landing was faked by the government.",
        "Aliens have already infiltrated the US government.",
        "The Earth is flat and NASA is hiding it from us.",
        "The Illuminati control everything from behind the scenes.",
        "The government is using chemtrails to control our minds.",
        "911 was an inside job orchestrated by the US government.",
        "The Titanic was intentionally sunk for insurance money.",
        "Paul McCartney died in 1966 and was replaced by a lookalike.",
        "The Bermuda Triangle is a portal to another dimension.",
        "Area 51 is hiding evidence of extraterrestrial life.",
        "The New World Order is planning to take over the world.",
        "The government is hiding the cure for cancer to keep us sick.",
        "Elvis Presley faked his own death and is living in hiding.",
        "The government is secretly controlling the weather with HAARP.",
        "Vaccinations are dangerous and the government is covering it up.",
        "The Illuminati created the Internet to spy on us.",
        "The government is hiding evidence of time travel technology.",
        "The Illuminati are behind every major event in history.",
        "The government is using mind control to create a New World Order.",
        "The Rothschild family controls the world's economy and governments.",
        "The JFK assassination was a government cover-up.",
        "The government is hiding contact with advanced extraterrestrial races.",
        "The Freemasons are part of a worldwide conspiracy to control society.",
        "The government is hiding evidence of the existence of Bigfoot.",
    };
    int num_theories = sizeof(theories) / sizeof(theories[0]); // Calculate the number of theories
    int random_index = rand() % num_theories; // Generate a random index
    printf("Did you know that: %s\n", theories[random_index]); // Print out the random conspiracy theory
    return 0;
}