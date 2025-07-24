//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: light-weight
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

char* phrases[] = {
    "The government is hiding evidence of extraterrestrial life",
    "The moon landing was staged",
    "The Illuminati controls the world",
    "Birds are drones created by the government to spy on us",
    "The world is controlled by lizard people in disguise",
    "The Bermuda Triangle is a portal to another dimension"
};

int main() {
    srand(time(0)); // seed random number generator with current time
    
    // Generate random conspiracy theory
    int index = rand() % 6;
    char* conspiracy = phrases[index];
    
    // Print conspiracy theory
    printf("Did you know? %s\n", conspiracy);
    
    return 0;
}