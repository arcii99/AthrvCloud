//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_THEORIES 10

const char *subjects[] = {
    "the moon landing",
    "9/11",
    "the Illuminati",
    "the government",
    "chemtrails",
    "vaccines",
    "big pharma",
    "aliens",
    "Area 51",
    "the assassination of JFK"
};

const char *actions[] = {
    "was faked",
    "was an inside job",
    "controls the world",
    "is hiding the truth",
    "is poisoning us all",
    "causes autism",
    "is creating diseases",
    "is studying us",
    "has alien technology",
    "was a conspiracy"
};

const char *evidences[] = {
    "It's obvious when you look at the video",
    "The government cover-up is proof",
    "Just connect the dots, people",
    "There's secret documents that prove it",
    "The truth is out there, you just have to find it",
    "I heard it from a reliable source",
    "It's on the internet, so it must be true",
    "There's too many coincidences for it not to be true",
    "It's just my gut feeling",
    "The illuminati told me"
};

int main()
{
    srand(time(0)); // seed random number generator with current time
    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");
    
    int i;
    for(i = 0; i < NUM_THEORIES; i++) {
        int subject_index = rand() % 10; // generate random index for subjects array
        int action_index = rand() % 10; // generate random index for actions array
        int evidence_index = rand() % 10; // generate random index for evidences array
        
        printf("Theory #%d: %s %s because %s.\n\n", i+1, subjects[subject_index], actions[action_index], evidences[evidence_index]);
    }
    
    printf("Thanks for using the Random Conspiracy Theory Generator!\n");
    return 0;
}