//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random conspiracy theories
char* generateTheory() {
    // Array of conspiracy theories
    char* theories[10] = {
        "The earth is flat and the government is hiding it",
        "The moon landing was faked to distract from secret space missions",
        "NASA is hiding evidence of alien life",
        "The government is using chemtrails to control the weather",
        "The Illuminati is controlling world events",
        "The government is controlling our minds with radio waves",
        "The Mandela Effect is proof of alternate realities",
        "The Loch Ness Monster is real and being covered up",
        "The Bermuda Triangle is a portal to another dimension",
        "The government is hiding evidence of time travel"
    };
    
    // Generate random index to select random theory
    int randomIndex = rand() % 10;
    
    // Return randomly selected theory
    return theories[randomIndex];
}

int main() {
    // Seed random number generator
    srand(time(NULL));
    
    // Generate and print 5 random conspiracy theories
    for (int i = 0; i < 5; i++) {
        char* theory = generateTheory();
        printf("Theory %d: %s\n", i+1, theory);
    }
    
    return 0;
}