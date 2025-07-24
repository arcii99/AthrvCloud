//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* subjects[] = {"The Government", "The Illuminati", "Aliens", "The Freemasons", "The Reptilians", "The Deep State", "The New World Order", "The CIA", "The FBI"};
char* actions[] = {"controls", "manipulates", "monitors", "influences", "dominates", "brainwashes", "manages", "observes", "subjugates", "directs"};
char* objects[] = {"the media", "the economy", "the weather", "our minds", "the education system", "the internet", "the stock market", "the entertainment industry"};

int main()
{
    int num_theories = 10;
    srand(time(NULL));

    printf("Welcome to the Random Conspiracy Theory Generator!\n\n");

    printf("Here are %d conspiracy theories:\n", num_theories);

    for (int i = 1; i <= num_theories; i++)
    {
        int subj_index = rand() % 9;
        int act_index = rand() % 10;
        int obj_index = rand() % 8;

        char conspiracy[200];

        sprintf(conspiracy, "%d. %s %s %s.", i, subjects[subj_index], actions[act_index], objects[obj_index]);

        printf("%s\n", conspiracy);
    }

    return 0;
}