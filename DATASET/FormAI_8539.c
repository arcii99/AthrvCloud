//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    //Initializing arrays
    char subject[10][25] = {"The Moon", "The Government", "The Illuminati", "The Aliens", "The Reptilians", "Big Pharma", "The Rothschilds", "The Freemasons", "The Deep State", "The Vatican"};
    char verb[10][25] = {"controls", "manipulates", "brainwashes", "influences", "secretly funds", "observes", "creates", "manages", "infects", "destroys"};
    char object[10][25] = {"the Weather", "the Media", "the Economy", "the Education System", "the Elections", "the Stock Market", "our Thoughts", "our Emotions", "our DNA", "our Health"};

    //Generating random conspiracy theory sentence
    int subjIndex = rand() % 10;
    int verbIndex= rand() % 10;
    int objIndex= rand() % 10;

    printf("Did you know that %s %s %s?\n", subject[subjIndex], verb[verbIndex], object[objIndex]);

    return 0;
}