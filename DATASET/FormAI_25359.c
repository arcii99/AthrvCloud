//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: genious
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printConspiracyTheory(){
    char* theories[] = {"The moon landing was faked by the US government to win the space race.",
                        "The government has been hiding the cure for cancer to keep the pharmaceutical industry afloat.",
                        "Aliens have been visiting Earth for centuries and the government is working with them in secret.",
                        "The Illuminati controls all world governments and events to create a new world order.",
                        "The government created the AIDS virus in a lab to reduce the global population.",
                        "The assassination of John F. Kennedy was a planned and executed plot by the US government.",
                        "The 9/11 attacks were an inside job arranged by the US government.",
                        "The fluoride in our water is actually a mind control agent added by the government.",
                        "The Bermuda Triangle is actually a portal to another dimension that the government is keeping a secret.",
                        "The government is hiding evidence of the existence of Sasquatch to prevent widespread panic."};

    //generate a random index
    srand(time(NULL));
    int randomIndex = rand() % 10;

    //print the theory
    printf("CONSPIRACY THEORY ALERT: \n");
    printf("Did you know that %s\n\n", theories[randomIndex]);
}

int main(){
    //generate 10 random conspiracy theories
    for(int i=0; i<10; i++){
        printConspiracyTheory();
    }

    return 0;
}