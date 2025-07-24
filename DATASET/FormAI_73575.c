//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* subjects[] = {"The Government", "The Illuminati", "Aliens", 
                    "The New World Order", "The Freemasons", "The Reptilians", 
                    "The Deep State", "The CIA", "The NSA", "The FBI"};
char* verbs[] = {"are controlling", "are planning", "are watching", 
                 "are influencing", "are manipulating", "are brainwashing",
                 "are experimenting on", "are hiding from", "are attacking"};
char* objects[] = {"our thoughts", "the weather", "the stock market",
                   "our dreams", "our health", "our freedoms", 
                   "the media", "our elections", "our environment",
                   "our technology"};

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate random conspiracy theories
    for(int i = 0; i < 10; i++) {
        int subj = rand() % 10;
        int verb = rand() % 8;
        int obj = rand() % 11;

        printf("%s %s %s.\n", subjects[subj], verbs[verb], objects[obj]);
    }

    return 0;
}