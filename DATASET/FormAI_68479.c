//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); //initialize random seed
    
    char *subjects[] = {"The moon landing", "Area 51", "9/11", "Chemtrails", "The Illuminati", "Bigfoot", "Bermuda Triangle", "The JFK Assassination", "The Denver Airport", "Flat Earth"};
    int numSubjects = sizeof(subjects)/sizeof(subjects[0]);

    char *verbs[] = {"was faked by", "was orchestrated by", "is being controlled by", "is a cover up for", "is secretly working with", "is a pawn of"};
    int numVerbs = sizeof(verbs)/sizeof(verbs[0]);

    char *objects[] = {"the government", "aliens", "the Freemasons", "the lizard people", "the deep state", "Satanists", "the New World Order"};
    int numObjects = sizeof(objects)/sizeof(objects[0]);

    char *locations[] = {"in the desert", "underground", "in a secret base", "in a bunker", "in another dimension"};
    int numLocations = sizeof(locations)/sizeof(locations[0]);

    char *actions[] = {"to control the masses", "to harvest our DNA", "to steal our souls", "to create a one world government", "to bring the Antichrist to power"};
    int numActions = sizeof(actions)/sizeof(actions[0]);

    char *evidences[] = {"there is no photographic evidence", "too many coincidences", "witnesses have been silenced", "the official story doesn't add up", "there are government documents that prove it"};
    int numEvidences = sizeof(evidences)/sizeof(evidences[0]);

    char *conspiracyTheories[] = {"%s %s %s %s", "%s %s %s because %s", "%s is hiding %s %s %s", "%s is behind the %s %s %s", " %s %s %s %s %s"};

    int numConspiracyTheories = sizeof(conspiracyTheories)/sizeof(conspiracyTheories[0]);

    int randomSubject = rand() % numSubjects;
    int randomVerb = rand() % numVerbs;
    int randomObject = rand() % numObjects;
    int randomLocation = rand() % numLocations;
    int randomAction = rand() % numActions;
    int randomEvidence = rand() % numEvidences;

    char conspiracyTheory[100];

    int randomTheory = rand() % numConspiracyTheories;

    if (randomTheory == 0) {
        sprintf(conspiracyTheory, conspiracyTheories[randomTheory], subjects[randomSubject], verbs[randomVerb], objects[randomObject], locations[randomLocation]);
    } else if (randomTheory == 1) {
        sprintf(conspiracyTheory, conspiracyTheories[randomTheory], subjects[randomSubject], verbs[randomVerb], objects[randomObject], evidences[randomEvidence]);
    } else if (randomTheory == 2) {
        sprintf(conspiracyTheory, conspiracyTheories[randomTheory], subjects[randomSubject], "is hiding", objects[randomObject], actions[randomAction]);
    } else if (randomTheory == 3) {
        sprintf(conspiracyTheory, conspiracyTheories[randomTheory], objects[randomObject], "is behind", subjects[randomSubject], actions[randomAction]);
    } else if (randomTheory == 4) {
        sprintf(conspiracyTheory, conspiracyTheories[randomTheory], evidences[randomEvidence], subjects[randomSubject], verbs[randomVerb], objects[randomObject], actions[randomAction]);
    }

    printf("The conspiracy theory is: %s\n", conspiracyTheory);
    return 0;
}