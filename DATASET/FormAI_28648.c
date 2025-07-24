//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    //Setting up the random seed for generating different results everytime
    srand(time(0));

    //Random arrays of conspiracy theories
    char *theories[] = {"The government is hiding evidence of aliens existence",
                        "The moon landing was faked",
                        "Elon Musk is an alien trying to take over the world",
                        "The Illuminati controls everything from behind the scenes",
                        "Bigfoot is real and the government is covering it up",
                        "9/11 was an inside job",
                        "The earth is flat and the government is hiding it",
                        "Chemtrails are real and poisonous",
                        "The moon is a projection and not real",
                        "The Bermuda Triangle is a portal to another dimension"};

    char *people[] = {"Donald Trump",
                      "Barack Obama",
                      "Bill Gates",
                      "Mark Zuckerberg",
                      "Elon Musk",
                      "Jeff Bezos",
                      "Hillary Clinton",
                      "Kim Jong-un",
                      "The Queen of England",
                      "Vladimir Putin",
                      "Tom Cruise",
                      "Keanu Reeves",
                      "Taylor Swift",
                      "Beyoncé"};

    char *locations[] = {"Area 51",
                         "The Pentagon",
                         "The White House",
                         "Silicon Valley",
                         "The Vatican",
                         "The Bermuda Triangle",
                         "The North Pole",
                         "The South Pole",
                         "The Moon",
                         "Mars",
                         "The Deep Web"};

    char *actions[] = {"is working with aliens",
                       "has access to forbidden knowledge",
                       "is secretly controlling the world",
                       "is hiding the truth from us",
                       "has been replaced by a clone",
                       "is immortal and has been alive for centuries",
                       "is a time traveler from the future",
                       "is in contact with extraterrestrial beings",
                       "is trying to start a new world order",
                       "has the cure for all diseases but won't share it",
                       "is plotting an attack on the US",
                       "is responsible for global warming"};

    //Generating random conspiracy theory
    int theory_index = rand() % 10;
    int person_index = rand() % 14;
    int location_index = rand() % 11;
    int action_index = rand() % 12;

    printf("Did you know that %s %s %s?\n", people[person_index], actions[action_index], locations[location_index]);
    printf("It's all part of a bigger plan to %s.\n", theories[theory_index]);

    return 0;
}