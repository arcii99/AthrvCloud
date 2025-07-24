//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

srand(time(NULL));
char *subjects[] = {"The Government", "The Illuminati", "The Reptilians","The Deep State","The New World Order","The Freemasons"};
char *verbs[] = {"are controlling", "are manipulating", "are brainwashing", "are hiding", "are planning", "are conspiring"};
char *objects[] = {"the weather", "our thoughts", "the markets", "the media", "the elections", "the aliens"};

int subjectIndex = rand() % 6;
int verbIndex = rand() % 6;
int objectIndex = rand() % 6;

printf("\n\n*** RANDOM CONSPIRACY THEORY GENERATOR ***\n\n");

printf("Did you know that %s %s %s?\n", subjects[subjectIndex], verbs[verbIndex], objects[objectIndex]);

printf("\nDon't believe me? Just look at the evidence...\n\n");

for (int i = 0; i < 5; i++) {
    printf("%d. ", i + 1);
    switch (rand() % 5) {
        case 0:
            printf("There have been strange fluctuations in %s's weather patterns.\n", subjects[subjectIndex]);
            break;
        case 1:
            printf("%s is behind the rise of fake news and misinformation.\n", subjects[subjectIndex]);
            break;
        case 2:
            printf("%s has been manipulating the %s for years.\n", subjects[subjectIndex], objects[objectIndex]);
            break;
        case 3:
            printf("There have been numerous sightings of %s members attending secret meetings.\n", subjects[subjectIndex]);
            break;
        case 4:
            printf("%s has been funding and directing the spread of viral diseases.\n", subjects[subjectIndex]);
            break;
    }
}
printf("\nWhat do you think? Are you convinced?\n\n");

return 0; 
}