//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char* theories[5] = {"The government is controlling the weather to create natural disasters.", 
                         "Aliens already live among us and control the world's governments.", 
                         "The moon landing was faked in a studio on earth.", 
                         "Bigfoot is a government experiment gone wrong.", 
                         "The Illuminati controls the world's economy."};
    char* locations[5] = {"in Antarctica", "in Area 51", "in the Bermuda Triangle", "in the Amazon Rainforest", "underneath the Denver airport"};
    char* evidences[5] = {"the existence of crop circles", "the sudden disappearance of planes", "the rise in sea levels", "the increase in natural disasters", "the development of advanced technology"};
    
    int theoryIndex = rand() % 5; // generate random index for theory array
    int locationIndex = rand() % 5; // generate random index for location array
    int evidenceIndex = rand() % 5; // generate random index for evidence array
    
    printf("According to my sources, %s %s is evidence that %s.\n", theories[theoryIndex], locations[locationIndex], evidences[evidenceIndex]);
    
    return 0;
}