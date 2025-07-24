//FormAI DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateConspiracyTheory(){
    char *people[5] = {"Illuminati", "The New World Order", "Reptilians", "Freemasons", "The Deep State"};
    char *events[5] = {"The Moon Landing", "9/11", "The JFK Assassination", "COVID-19", "The Titanic Disaster"};
    char *actions[5] = {"Creating a pandemic", "Controlling the media", "Hiding the truth from the public", "Brainwashing the masses", "Stealing elections"};
    char *locations[5] = {"Area 51", "Bermuda Triangle", "The Vatican", "Antarctica", "The Moon"};
    
    srand(time(NULL));
    int p = rand() % 5;
    int e = rand() % 5;
    int a = rand() % 5;
    int l = rand() % 5;
    
    printf("The %s is responsible for %s by %s in %s.\n", people[p], events[e], actions[a], locations[l]);
}

int main(){
    printf("Random Conspiracy Theory Generator:\n");
    printf("-----------------------------------\n");
    printf("Have fun with your tin foil hat!\n\n");
    
    char response;
    do{
        generateConspiracyTheory();
        printf("\nGenerate another conspiracy theory? (y/n): ");
        scanf(" %c", &response);
        printf("\n");
    } while (response == 'y');
    
    printf("Thank you for using the Random Conspiracy Theory Generator.\n");
    return 0;
}