//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printHeader(){
    printf("##################################################\n");
    printf("#        Welcome to the Random Conspiracy        #\n");
    printf("#                  Generator!                    #\n");
    printf("##################################################\n\n");
}

void generateConspiracy(){
    // Set up all the random things here
    srand(time(NULL));
    char * organizations[5] = {"NASA", "Illuminati", "CIA", "NRA", "Masons"};
    char * person[5] = {"Donald Trump", "Barack Obama", "Jeff Bezos", "Kim Jong-Un", "John F. Kennedy"};
    char * action[5] = {"plotted", "infiltrated", "brainwashed", "assassinated", "conspired against"};
    char * target[5] = {"Area 51", "the United Nations", "the moon landing", "vaccines", "the Flat Earth Society"};

    int randomOrg = rand() % 5;
    int randomPerson = rand() % 5;
    int randomAction = rand() % 5;
    int randomTarget = rand() % 5;

    printf("Did you know that %s %s %s %s?\n", organizations[randomOrg], person[randomPerson], action[randomAction], target[randomTarget]);
}

int main(){
    printHeader();
    generateConspiracy();
    return 0;
}