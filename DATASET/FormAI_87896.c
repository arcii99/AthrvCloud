//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: thriller
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(){
    char *subjects[5] = {"Aliens","Illuminati","Big Pharma","Government","Reptilians"};
    char *verbs[5] = {"are controlling","poisoning","manipulating","spying on","experimenting on"};
    char *objects[5] = {"our minds","the economy","the environment","our food","our DNA"};
    char *locations[5] = {"Area 51","the White House","the Bermuda Triangle","the Vatican","the Moon"};

    srand(time(NULL));
    int subject = rand() % 5;
    int verb = rand() % 5;
    int object = rand() % 5;
    int location = rand() % 5;

    char theory[100];
    sprintf(theory, "%s %s %s at %s", subjects[subject], verbs[verb], objects[object], locations[location]);

    printf("Welcome to the Random Conspiracy Theory Generator. Sit back and get ready to have your mind blown.\n");
    printf("According to our sources, %s\n", theory);
    printf("Do you believe it? Or is the truth out there somewhere else?\n");

    return 0;
}