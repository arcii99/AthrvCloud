//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10 // number of conspiracy theories in the array
#define MAX_THEORY_LEN 100 // maximum length of theory string

int main() {
    srand(time(NULL)); // seed random number generator

    // conspiracy theories array
    char theories[NUM_THEORIES][MAX_THEORY_LEN] = {
        "The moon landing was fake", 
        "The government is controlling our thoughts with chemtrails", 
        "9/11 was an inside job", 
        "The Illuminati is running the world", 
        "The earth is flat", 
        "The Simpsons are predicting the future", 
        "The Holocaust didn't happen", 
        "The Bermuda Triangle is a portal to another dimension", 
        "Aliens are living among us", 
        "COVID-19 was created in a lab"
    };

    // generate random conspiracy theory
    int rand_index = rand() % NUM_THEORIES; // random index of theory in array
    char theory[MAX_THEORY_LEN]; // theory string
    sprintf(theory, "Theory #%d: %s", rand_index+1, theories[rand_index]); // format theory string with number and theory from array
    printf("%s\n", theory);

    return 0;
}