//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    char* topics[] = {" government", " illuminati", " reptilian aliens", " Freemasons", " Big Pharma", " Flat Earth Society", " New World Order", " CIA", " FBI", " NSA", " JFK assassination", " moon landing", " chemtrails", " 9/11", " HAARP", " Area 51", " ancient astronauts", " time travel", " black helicopters", " mind control", " cloning", " GMOs", " lizard people", " the Matrix", " interdimensional beings", " parallel universes"};

    char* actions[] = {" is controlling", " is manipulating", " is hiding", " is covering up", " is experimenting on", " is brainwashing", " is harvesting", " is plotting against", " is using", " is weaponizing", " is surveilling"};

    char* objects[] = {" the population", " the weather", " the media", " our minds", " our DNA", " our food", " our water", " our air", " our dreams", " our perceptions"};

    int num_of_topics = sizeof(topics)/sizeof(topics[0]);
    int num_of_actions = sizeof(actions)/sizeof(actions[0]);
    int num_of_objects = sizeof(objects)/sizeof(objects[0]);

    int i, j, k, num_of_theories;

    printf("Welcome to the Random Conspiracy Theory Generator!\n");
    printf("How many theories would you like to generate? ");
    scanf("%d", &num_of_theories);

    for(i = 0; i < num_of_theories; i++) {
        printf("%d) The", i+1);
        j = rand() % num_of_topics;
        printf("%s", topics[j]);
        k = rand() % num_of_actions;
        printf("%s", actions[k]);
        j = rand() % num_of_objects;
        printf("%s.\n", objects[j]);
    }

    return 0;
}