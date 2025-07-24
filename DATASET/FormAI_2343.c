//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set up conspiracy theories
    char *theories[] = {
        "The moon landing was faked",
        "The government controls our thoughts with chemtrails",
        "Elvis Presley is alive and in hiding",
        "The earth is flat",
        "Aliens are among us",
        "The Illuminati controls the world",
        "The JFK assassination was an inside job",
        "9/11 was an inside job",
        "COVID-19 was created in a lab",
        "The government is hiding the cure for cancer"
    };
    
    // Generate a random index
    srand(time(NULL));
    int index = rand() % 10;
    
    // Print the conspiracy theory
    printf("Did you know that %s?\n", theories[index]);
    
    return 0;
}