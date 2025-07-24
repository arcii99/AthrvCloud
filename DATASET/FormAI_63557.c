//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: portable
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char *nouns[]={"Chemtrails", "Illuminati", "Big Pharma", "Reptilian Elite", "New World Order", "Deep State", "HAARP", "CERN", "Flat Earth", "Aliens", "Vaccines", "Mandela Effect", "Robot Overlords", "Zombie Apocalypse", "Mayan Calendar", "Nibiru", "Haunting", "Ghost", "Dinosaurs", "Atlantis"};

char *verbs[]={"are controlling", "are manipulating", "are brainwashing", "are hiding the truth about", "are experimenting with", "are creating chaos with", "are planning to use", "are covering up", "are stealing energy from", "are conspiring against", "are sacrificing children for", "are secretly worshiping", "are trying to revive", "are infecting us with", "are merging with", "are destroying evidence of", "are channeling", "are communicating with", "are bringing about"};

char *adjectives[]={"secret", "hidden", "mysterious", "unknown", "unexplainable", "dark", "sinister", "manipulative", "destructive", "powerful", "elusive", "ominous", "frightening", "terrifying", "mind-boggling", "mind-controlling", "mind-bending", "paranormal", "supernatural", "time-traveling"};

char *locations[]={"underground bases", "Area 51", "the Bermuda Triangle", "the Vatican", "the North Pole", "the South Pole", "the moon", "Mars", "Ancient Egypt", "Sumeria", "the Illuminati Headquarters", "the Pentagon", "underwater cities", "Atlantis", "the Hollow Earth", "inner dimensions", "parallel universes", "alternate realities"};

int main()
{
    srand(time(NULL)); //initialize random seed

    printf("Welcome to the Random Conspiracy Theory Generator!\n");

    printf("Press any key to generate a conspiracy theory or 'q' to quit...\n");

    while(getchar()!='q') //keep generating until user quits
    {
        int nounIndex=rand()%20; //choose random index for noun array
        int verbIndex=rand()%18; //choose random index for verb array
        int adjIndex=rand()%20; //choose random index for adjective array
        int locIndex=rand()%18; //choose random index for location array

        printf("\nDid you know that...\n");

        printf("%s %s the %s %s?\n", nouns[nounIndex], verbs[verbIndex], adjectives[adjIndex], locations[locIndex]);

        printf("Wake up sheeple! Don't let them fool you!\n");

        printf("Press any key to generate another conspiracy theory or 'q' to quit...\n");
    }

    printf("Thanks for using the Random Conspiracy Theory Generator!\n");

    return 0;
}