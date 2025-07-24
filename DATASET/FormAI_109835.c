//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // setting the seed for rand()

    char *surveillance_keywords[] = {"NSA", "CIA", "FBI", "ASIO", "MI6", "Mossad"};
    char *political_party[] = {"Democrats", "Republicans", "Libertarians", "Green Party", "Socialists"};
    char *aliens[] = {"Reptilians", "Greys", "Nordics", "Annunaki", "Pleiadians"};
    char *disasters[] = {"9/11", "JFK Assassination", "COVID-19 Pandemic", "Hurricane Katrina", "Chernobyl Disaster"};
    char *action[] = {"rigged", "manipulated", "orchestrated", "covertly controlled", "conspired"};

    // randomly selecting items from the arrays
    int surveillanceIndex = rand() % 6;
    int partyIndex = rand() % 5;
    int alienIndex = rand() % 5;
    int disasterIndex = rand() % 5;
    int actionIndex = rand() % 5;

    // forming the conspiracy theory
    printf("Did you know that the %s %s the %s into the %s disaster to further their agenda to control the %s?\n", surveillance_keywords[surveillanceIndex], action[actionIndex], aliens[alienIndex], disasters[disasterIndex], political_party[partyIndex]);

    // adding a spooky ending
    printf("Stay vigilant, because the truth is out there.\n");

    return 0;
}