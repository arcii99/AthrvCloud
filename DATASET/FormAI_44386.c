//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void clearScreen(); //function to clear the screen

int main(){
   srand(time(NULL)); //initialize random seed

   char *conspiracy[10] = {"The government caused the apocalypse to reduce the population","The apocalypse was caused by a secret space weapon",
                            "The rich built bunkers to survive the apocalypse","The virus that caused the apocalypse was created in a lab",
                            "The apocalypse was caused by a nuclear war between two countries","The apocalypse was predicted by the Mayans",
                            "The apocalypse was caused by a natural disaster that was engineered by humans","The apocalypse was caused by aliens",
                            "The apocalypse was planned by the Illuminati","The apocalypse was a cover-up for a secret government project"};

  char *evidence[5] = {"There are secret government documents that prove it","The survivors are all part of a secret government project","The rich have disappeared from society",
                        "There are strange lights in the sky that weren't there before","There are secret meetings that are happening in the middle of the night"};

   char *coverup[5] = {"The government is lying to us about the apocalypse","The apocalypse was caused by climate change and they are covering it up",
                        "The survivors are all being brainwashed by the government","They are keeping us in the dark about what really caused the apocalypse",
                        "There are still people out there who know what really happened but they're too scared to speak up"};

   int random_conspiracy = rand() % 10; //randomly choose a conspiracy theory
   int random_evidence = rand() % 5; //randomly choose a piece of evidence
   int random_coverup = rand() % 5; //randomly choose a cover-up explanation

   clearScreen(); //clear the screen before displaying the conspiracy theory

   printf("\n\n\t\t\tRANDOM CONSPIRACY THEORY GENERATOR\n");
   printf("\n\t\t\t\tPOST-APOCALYPTIC STYLE\n\n");
   printf("Did you know that...\n");
   printf("\n%s\n", conspiracy[random_conspiracy]); //display the chosen conspiracy theory
   printf("\nThis is supported by evidence such as...\n");
   printf("\n%s\n", evidence[random_evidence]); //display the chosen piece of evidence
   printf("\nHowever, the government is trying to cover it up by...\n");
   printf("\n%s\n\n", coverup[random_coverup]); //display the chosen cover-up explanation

   return 0;
}

void clearScreen(){
    //function to clear the screen
    system("cls||clear");
}