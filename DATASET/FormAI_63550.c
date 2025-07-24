//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10

char* topics[NUM_THEORIES] = {"Chemtrails", "Flat Earth", "Alien Abduction", "New World Order", "Antivaxxers", "Illuminati", "Area 51", "Bigfoot", "Moon Landing", "Reptilians"};

char* theories[NUM_THEORIES] = {"The government is using planes to release chemicals to control our minds.",
                                "The earth is actually flat and everyone who disagrees is part of a vast conspiracy.",
                                "Aliens are abducting people and performing experiments on them.",
                                "A secret group of powerful individuals is working to create a one-world government.",
                                "Vaccines have dangerous side effects and are actually part of a population control scheme.",
                                "A secret society is controlling the world from behind the scenes.",
                                "The government is hiding evidence of extraterrestrial life at a top-secret facility.",
                                "A large bipedal creature resides in remote wilderness areas of North America.",
                                "The moon landing was faked by the U.S. government for political reasons.",
                                "Reptilian humanoids are controlling world events from behind the scenes."};

char* locations[NUM_THEORIES] = {"in the sky",
                                 "at the edge of the world",
                                 "in underground facilities",
                                 "in our own backyards",
                                 "in the halls of power",
                                 "on the dark side of the moon",
                                 "in the forests and mountains",
                                 "in every major city",
                                 "beneath the ocean's surface",
                                 "in the depths of outer space"};

char* motives[NUM_THEORIES] = {"to control the population",
                               "to prevent people from discovering the truth",
                               "to harvest our DNA",
                               "to establish a new world order",
                               "to protect their own interests",
                               "to seize power and wealth",
                               "to maintain their secrecy",
                               "to hide their true nature",
                               "to deceive and mislead us",
                               "to bring about the end of the world"};

int main() {
    srand(time(NULL));

    printf("Welcome to the C Random Conspiracy Theory Generator!\n");
    printf("Would you like a conspiracy theory? [yes/no]\n");

    char response[4];
    fgets(response, 4, stdin);

    if (strncmp(response, "yes", 3) == 0) {
        int index = rand() % NUM_THEORIES;
        printf("\nHere's your conspiracy theory:\n\n");
        printf("%s%s%s", topics[index], " ", theories[index]);
        printf(" They are doing this %s ", locations[index]);
        printf(" %s.\n", motives[index]);
    }
    else {
        printf("Okay, take care.\n");
    }

    return 0;
}