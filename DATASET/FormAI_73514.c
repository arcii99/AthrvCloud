//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char *conspiracy_theories[] = {
    "The moon landing was faked by the US government to flex their technological prowess over the Soviet Union.",
    "The government is hiding the cure to cancer because it’s highly profitable to treat it instead of curing it.",
    "COVID-19 was created by the Chinese government in a laboratory and deliberately released into the world.",
    "The government is controlling our minds through radio waves emitted by the cell phone towers.",
    "The Illuminati is a secret society that controls everything from the economy to the government.",
    "The world is flat and every space agency, scientist, and government is conspiring to hide this from us.",
    "The government conducts secret experiments on humans, including mind control and time travel.",
    "The JFK assassination was not carried out by a single shooter, but was a group of conspirators to silence him.",
    "9/11 was an inside job carried out by the US government to justify their invasion of the Middle East.",
    "The world is going to end on December 21, 2012, as predicted by the ancient Mayan calendar.",

};

// Function to generate random index
int get_random_index(int range) {
    srand(time(0));
    return rand() % range;
}

int main() {
    printf("Welcome to the Random Conspiracy Theory Generator.\n");
    printf("Do you want to know the truth behind the world's biggest mysteries? Type 'yes' to proceed otherwise type 'no':");
    char choice[4];
    scanf("%s", choice);
    if (strcmp(choice, "yes") == 0) {
        printf("\n\nYou asked for it. Here's your random conspiracy theory:\n\n");
        int range = sizeof(conspiracy_theories) / sizeof(conspiracy_theories[0]);
        int index = get_random_index(range);
        printf("%s\n", conspiracy_theories[index]);
    }
    else if (strcmp(choice, "no") == 0) {
        printf("You can't handle the truth!");
    }
    else {
        printf("Invalid input.");
    }
    return 0;
}