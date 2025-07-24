//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //Initialize random seed
    srand(time(NULL));
    
    //Conspiracy theories for Romeo
    char* romeo_theories[] = {"The government is controlled by lizard people!",
                              "The moon landings were faked!",
                              "The Illuminati controls the music industry!",
                              "9/11 was an inside job!",
                              "Aliens are among us and have been for centuries!"};
    
    //Conspiracy theories for Juliet
    char* juliet_theories[] = {"Chemtrails are a government mind control experiment!",
                               "The Earth is flat and NASA is hiding the truth!",
                               "Big Pharma is hiding the cure for cancer!",
                               "The government is spying on us through our phones!",
                               "The New World Order is coming and we need to prepare!"};
    
    //Print initial greetings
    printf("Romeo: My dearest Juliet, I have a theory that I cannot keep to myself.\n");
    printf("Juliet: My sweet Romeo, what is it that troubles you so?\n");
    
    //Generate random number to select theory
    int romeo_index = rand() % 5;
    int juliet_index = rand() % 5;
    
    //Print conspiracy theories
    printf("Romeo: I believe that %s\n", romeo_theories[romeo_index]);
    printf("Juliet: Oh my, that is quite a theory.\n");
    printf("Juliet: I too have a theory that has been weighing heavily on my mind.\n");
    printf("Romeo: Please tell me, my love.\n");
    printf("Juliet: I believe that %s\n", juliet_theories[juliet_index]);
    printf("Romeo: My goodness, that is quite an accusation!\n");
    
    //Print conclusion
    printf("Juliet: We must continue to question the world around us and seek out the truth!\n");
    printf("Romeo: Agreed, my love. Let us always be curious and never stop seeking knowledge.\n");
    
    return 0;
}