//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    srand(time(NULL));
    //initialize random seed

    char *adjectivesList[] = {
        "sinister",
        "evil",
        "hidden",
        "concealed",
        "undisclosed",
        "secret",
        "obscure",
        "mysterious",
        "suspicious",
        "mystical",
        "unknown",
        "cryptic",
        "ambiguous",
        "enigmatic"
    };
    //list of adjectives to be used in conspiracy theories

    char *nounList[] = {
        "government",
        "Illuminati",
        "aliens",
        "Big Pharma",
        "vaccines",
        "illuminati",
        "CIA",
        "NASA",
        "New World Order",
        "Freemasons",
        "Deep State",
        "Satanists",
        "Reptilians",
        "Bigfoot"
    };
    //list of nouns to be used in conspiracy theories

    int numOfAdjectives = sizeof(adjectivesList)/sizeof(adjectivesList[0]);
    int numOfNouns = sizeof(nounList)/sizeof(nounList[0]);
    //get size of adjective and noun lists

    int numOfIterations = 10;
    //number of random conspiracy theories to generate

    for(int i=1; i<=numOfIterations; i++){
        int adjIndex = rand() % numOfAdjectives;
        int nounIndex = rand() % numOfNouns;
        //generate random indices for adjective and noun lists

        printf("%d. %s %s are controlling the world through %s.\n",i,adjectivesList[adjIndex],nounList[nounIndex],"mind control");
        //print random conspiracy theory
    }

    return 0;
}