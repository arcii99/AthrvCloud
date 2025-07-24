//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // initialize random seed
    
    // arrays of conspiracy theories, verbs, and nouns
    char* theories[] = {"The moon landing was faked", 
                        "Chemtrails are controlling our minds",
                        "The government is hiding evidence of aliens",
                        "COVID-19 was created in a lab"};
    char* verbs[] = {"proving",
                     "disproving",
                     "suppressing",
                     "exposing",
                     "fabricating"};
    char* nouns[] = {"evidence",
                     "documents",
                     "test results",
                     "eyewitness accounts",
                     "video footage"};
                     
    // generate and print 5 random conspiracy theories
    printf("Random Conspiracy Theories:\n");
    for (int i = 0; i < 5; i++) {
        int tIndex = rand() % 4; // generate random index for theories
        int vIndex = rand() % 5; // generate random index for verbs
        int nIndex = rand() % 5; // generate random index for nouns
        
        // print conspiracy theory in format: 
        // "The (theory) is (verb) (noun)"
        printf("The %s is %s %s.\n", theories[tIndex], verbs[vIndex], nouns[nIndex]); 
    }
    
    return 0;
}