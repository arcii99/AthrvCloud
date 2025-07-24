//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *topics[] = {"Government", "Aliens", "Illuminati", "Telekinesis", "Time Travel"};
char *actions[] = {"controlling", "influencing", "manipulating", "hiding", "revealing", "creating"};
char *objects[] = {"the weather", "mind control", "the stock market", "the media", "the internet", "world events"};

int main() {
    srand(time(NULL)); //Set the random seed based on current time
    int topicIndex = rand() % 5; //Pick a random index for the topic
    int actionIndex = rand() % 6; //Pick a random index for the action
    int objectIndex = rand() % 6; //Pick a random index for the object
    
    printf("Did you know that the %s are %s %s to control %s?\n", topics[topicIndex], actions[actionIndex], objects[objectIndex], objects[objectIndex]);
    printf("It's all a part of their plan to take over the world!");
    
    return 0;
}