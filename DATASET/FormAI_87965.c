//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Declare and initialize arrays for conspiracy theories 
char *theories[] = {"The moon landing was faked",
                    "The government is run by reptilian aliens",
                    "The earth is flat",
                    "Chemtrails are being used to control the population",
                    "The Illuminati controls everything",
                    "The JFK assassination was an inside job",
                    "9/11 was an inside job",
                    "COVID-19 was created in a lab"};

char *proofs[] = {"There are no stars in the moon landing photos",
                  "The royal family are actually reptilian shapeshifters",
                  "The horizon always appears at eye level",
                  "Government planes are secretly spraying chemicals on us",
                  "There are hidden symbols and messages in popular media",
                  "The magic bullet theory doesn't add up",
                  "The towers fell at free-fall speed",
                  "There are patents for the coronavirus"};

char *enemies[] = {"The Deep State",
                   "The New World Order",
                   "The Freemasons",
                   "The Bilderberg Group",
                   "The Vatican",
                   "The Trilateral Commission",
                   "The Rothschild family",
                   "The Federal Reserve"};

int main(){
    srand(time(NULL)); //use current time as seed for random number generation

    //generate random index numbers for each array
    int theory_index = rand() % 8;
    int proof_index = rand() % 8;
    int enemy_index = rand() % 8;

    //print out the randomly generated conspiracy theory
    printf("Did you know that %s?\n", theories[theory_index]);
    printf("And the evidence for this is that %s.\n", proofs[proof_index]);
    printf("But the real culprit behind all of this is %s!\n", enemies[enemy_index]);
    return 0;
}