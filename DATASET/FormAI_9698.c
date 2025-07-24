//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char *adjectives[] = {"alien","lizard","illuminati","robotic","time-traveling","mind-controlling","interdimensional","cyborg","zombie","vampire"};
    char *nouns[] = {"government","world leaders","celebrities","media","big pharma","technology companies","secret societies","extraterrestrials","AI","ancient civilizations"};
    char *verbs[] = {"brainwashing","mind control","manipulating","poisoning","meddling","altering","watching","spying","experimenting","building"};
    char *targets[] = {"humanity","the future","our minds","the weather","our DNA","the internet","our society","the world's economy","our thoughts","the afterlife"};

    srand(time(NULL));
    int adjIndex = rand() % 10;
    int nounIndex = rand() % 10;
    int verbIndex = rand() % 10;
    int targetIndex = rand() % 10;

    printf("Did you know that the %s %s are %s %s to %s?\n", adjectives[adjIndex], nouns[nounIndex], verbs[verbIndex], targets[targetIndex], nouns[nounIndex]);

    return 0;
}