//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    // arrays of conspiracy theories to randomly select from
    char *george_bush[] = {"George Bush caused 9/11 as an excuse to start a war in the Middle East.", 
                           "George Bush is a reptilian alien from another planet.", 
                           "George Bush is a member of the illuminati.",
                           "George Bush is a time traveler who went back in time to change the course of history."};
    char *moon_landing[] = {"The moon landing was faked by the US Government.", 
                            "The moon landing was real, but the footage was heavily edited by the US Government.", 
                            "The moon landing was real, but the astronauts were hypnotized by the US Government to forget what they saw."};
    char *vaccines[] = {"Vaccines are really just a way for the Government to control the population.", 
                        "Vaccines have mind-altering chemicals in them that make people more docile and easy to control.", 
                        "Vaccines are a hoax and don't actually prevent disease."};
    
    // randomly select conspiracy theories
    int rand_bush = rand() % 4;
    int rand_moon = rand() % 3;
    int rand_vaccines = rand() % 3;
    
    // print out the conspiracy theories
    printf("Did you know that:\n");
    printf("%s\n", george_bush[rand_bush]);
    printf("%s\n", moon_landing[rand_moon]);
    printf("%s\n", vaccines[rand_vaccines]);
    
    return 0;
}