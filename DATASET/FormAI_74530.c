//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function that generates a random conspiracy theory
char* generate_conspiracy_theory() {
    
    // Conspiracy theory options
    char* theories[] = {"The moon landing was fake",
                        "The government is run by lizard people",
                        "The Illuminati controls the world",
                        "Area 51 is hiding extraterrestrial life",
                        "The Earth is flat",
                        "The COVID-19 vaccine is a plot to microchip the population",
                        "9/11 was an inside job"};
    
    // Generate a random index
    int index = rand() % 7;
    
    return theories[index];
}

int main() {
    
    // Seed random generator with current time
    srand(time(NULL));
    
    // Generate 10 conspiracy theories
    for (int i = 1; i <= 10; i++) {
        printf("%d. %s\n", i, generate_conspiracy_theory());
    }
    
    return 0;
}