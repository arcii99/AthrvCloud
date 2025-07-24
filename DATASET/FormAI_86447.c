//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_THEORIES 10 //Maximum number of conspiracy theories in our database

char *conspiracy_theories[MAX_CONSPIRACY_THEORIES] = {
    "The moon landing was faked",
    "The government is hiding evidence of extraterrestrial life",
    "Bigfoot is real and the government knows it",
    "9/11 was an inside job",
    "The Earth is flat and NASA is hiding the truth",
    "The Illuminati controls the world",
    "Vaccines cause autism and the government is covering it up",
    "Chemtrails are a government effort to control the population",
    "The Denver International Airport is a secret Illuminati base",
    "The JFK assassination was a conspiracy involving multiple shooters"
};

int main() {
    srand(time(NULL)); //Seed the random number generator using the current time

    int conspiracy_index = rand() % MAX_CONSPIRACY_THEORIES; //Select a random conspiracy theory from our database
    char *conspiracy_theory = conspiracy_theories[conspiracy_index];

    printf("Did you know:\n\n%s\n", conspiracy_theory); //Print out the conspiracy theory
    
    return 0;
}