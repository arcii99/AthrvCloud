//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set seed for random number generator
    srand(time(NULL));
    
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    
    // Conspiracy theories
    char* theories[] = {"The moon landing was faked by the government", 
                        "The Illuminati controls the world's governments",
                        "9/11 was an inside job", 
                        "The earth is flat and the government is hiding it",
                        "Area 51 is hiding extraterrestrial life",
                        "The government is hiding the cure for cancer",
                        "The Hollywood elite are part of a secret society",
                        "The pyramids were built by aliens",
                        "The government is using chemtrails to control the population",
                        "The Bermuda Triangle is a portal to another dimension"};
    
    // Locations for the conspiracy theories
    char* locations[] = {"Washington D.C.", 
                         "Silicon Valley", 
                         "the Vatican",
                         "the United Nations headquarters",
                         "Area 51",
                         "the White House",
                         "Hollywood",
                         "the great pyramids of Giza",
                         "the North Pole",
                         "a secret underground bunker"};

    // People or groups responsible for the conspiracy theories
    char* responsible[] = {"the government", 
                           "the Illuminati",
                           "CIA agents",
                           "NASA scientists",
                           "aliens",
                           "the Bilderberg Group",
                           "the New World Order",
                           "the Masons",
                           "the Rothschilds",
                           "the Deep State"};
    
    // Generate random conspiracy theory
    int theory = rand() % 10;
    int loc = rand() % 10;
    int resp = rand() % 10;
    
    printf("Did you know that %s is hiding a secret from us all?\n", locations[loc]);
    printf("It's true! %s is behind it all, working with %s to keep us in the dark.\n", responsible[resp], locations[loc]);
    printf("They don't want us to know the truth about %s, because if we did, it would change everything.\n", theories[theory]);
    
    return 0;
}