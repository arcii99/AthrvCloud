//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <unistd.h>

// Function to generate a random boolean value
bool random_bool() {
    return rand() % 2 == 0;
}

// Function to generate a random conspiracy theory
char *generate_conspiracy_theory() {
    // List of conspiracy theories
    char *conspiracy_theories[] = {
        "The moon landing was faked by the government.",
        "The government is hiding the existence of extraterrestrial life.",
        "The Illuminati controls everything from behind the scenes.",
        "9/11 was an inside job.",
        "The world is run by a secret society known as the New World Order.",
        "The vaccines are actually causing illness, not preventing it.",
        "The earth is flat and the government is covering it up.",
        "The Bilderberg Group is secretly controlling the world.",
        "The Rothschild family controls the world's wealth.",
        "The government is using chemtrails to control the population.",
        "The Bermuda Triangle is a portal to another dimension."
    };
    
    // Generate a random index to select a conspiracy theory
    int random_index = rand() % 11;
    
    return conspiracy_theories[random_index];
}

// Asynchronous function to print a random conspiracy theory every 5 seconds
void async_conspiracy_printer() {
    while (true) {
        char *conspiracy_theory = generate_conspiracy_theory();
        printf("Did you know? %s\n", conspiracy_theory);
        sleep(5);
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    // Start the asynchronous conspiracy theory printer
    async_conspiracy_printer();
    
    return 0;
}