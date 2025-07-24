//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char* subjects[] = {"The government", "The Illuminati", "Aliens", "The New World Order", "The Deep State", "The Freemasons", "The reptilian overlords", "The shadow government", "The Rothschilds", "The Bilderberg Group", "The Trilateral Commission"};
char* actions[] = {"controls", "manipulates", "secretly funds", "influences", "takes orders from", "is being controlled by", "planned", "organized", "created", "destroyed", "predicted"};
char* objects[] = {"the economy", "the education system", "the media", "the global climate", "world events", "the food supply", "the healthcare system", "technology", "religion", "entertainment"};

int main(){
    srand(time(NULL));  //seeding the random number generator with time for more randomness
    
    printf("------------------------------\n");
    printf("Random Conspiracy Theory Generator\n");
    printf("------------------------------\n\n");
    
    for(int i = 0; i < 10; i++){
        int subIndex = rand() % 11;   //selecting a random subject index
        int actIndex = rand() % 11;   //selecting a random action index
        int objIndex = rand() % 10;   //selecting a random object index (excluding "entertainment" for more serious theories)
        
        char conspiracy[100];
        strcpy(conspiracy, subjects[subIndex]);   //copying subject to final conspiracy string
        strcat(conspiracy, " ");
        strcat(conspiracy, actions[actIndex]);    //appending action to conspiracy string
        strcat(conspiracy, " ");
        strcat(conspiracy, objects[objIndex]);    //appending object to conspiracy string
        
        printf("%d. %s.\n", i+1, conspiracy);     //printing the conspiracy theory
    }
    
    return 0;
}