//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random integer between a and b (inclusive)
int random_int(int a, int b) {
    return (rand() % (b - a + 1)) + a;
}

// Function to generate a random conspiracy theory
char* random_conspiracy() {
    char* conspiracies[] = {
        "The government is hiding the existence of aliens",
        "The moon landing was faked",
        "The Illuminati controls the world",
        "Chemtrails are a method of mind control",
        "The earth is flat",
        "The Bermuda Triangle is a portal to another dimension",
        "The Denver International Airport is a secret base for the New World Order",
        "The government is hiding evidence of time travel",
        "The Loch Ness monster is real and the government is keeping it a secret",
        "The Titanic was sunk on purpose for insurance money"
    };
    int num_conspiracies = sizeof(conspiracies) / sizeof(conspiracies[0]);
    return conspiracies[random_int(0, num_conspiracies-1)];
}

// Main program
int main() {
    // Set random seed based on current time
    srand((unsigned int)time(NULL));

    // Generate a random conspiracy theory
    char* conspiracy = random_conspiracy();

    // Print the conspiracy theory
    printf("Did you know that %s?\n", conspiracy);

    return 0;
}