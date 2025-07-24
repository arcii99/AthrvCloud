//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time

    // declare arrays for each part of the conspiracy theory
    char *groups[] = {"Illuminati", "Freemasons", "Bilderberg Group", "New World Order", "Trilateral Commission", "Council on Foreign Relations", "Skull and Bones Society", "Bohemian Club", "The Elite"};
    char *events[] = {"9/11 attacks", "moon landing", "JFK assassination", "Area 51", "COVID-19 pandemic", "global warming", "911 inside job theory", "Mass Control Theory", "UFO sightings"};
    char *actions[] = {"planned", "orchestrated", "executed", "funded", "controlled", "covered up", "concealed", "manipulated", "put in motion"};
    char *locations[] = {"Washington D.C.", "New York City", "London", "Paris", "Brussels", "Geneva", "Moscow", "Beijing", "Tokyo"};

    // generate random indices for each array
    int group_index = rand() % 9;
    int event_index = rand() % 9;
    int action_index = rand() % 9;
    int location_index = rand() % 9;

    // print out the conspiracy theory sentence
    printf("Did you know that the %s %s the %s in %s?\n", groups[group_index], actions[action_index], events[event_index], locations[location_index]);

    return 0;
}