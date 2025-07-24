//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char* subjects[10] = {"The government", "Aliens", "The illuminati", "Big Pharma", "The Freemasons", "The CIA", "The lizard people", "The New World Order", "The deep state", "The tech elite"};
    char* actions[10] = {"are controlling", "are manipulating", "are influencing", "are brainwashing", "are sabotaging", "are surveilling", "are experimenting on", "are infiltrating", "are conspiring against", "are funding"};
    char* targets[10] = {"the elections", "the media", "the economy", "the weather", "our minds", "the food supply", "the education system", "the energy industry", "the entertainment industry", "the health industry"};

    int i, j, k;
    for(i = 0; i < 10; i++){
        for(j = 0; j < 10; j++){
            for(k = 0; k < 10; k++){
                int randNum = rand() % 100;
                char* output;
                if(randNum < 33){
                    output = "It's clear to anyone who's paying attention that ";
                } else if(randNum < 66){
                    output = "Believe it or not, ";
                } else {
                    output = "I don't want to sound paranoid, but ";
                }
                printf("%s%s %s %s.\n", output, subjects[i], actions[j], targets[k]);
            }
        }
    }
    return 0;
}