//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayOpeningMessage(){
    printf("Welcome to the Procedural Space Adventure Game!\n");
    printf("You are the captain of a spaceship on a mission to explore the galaxy.\n");
    printf("Your goal is to find new planets and resources to bring back to Earth.\n");
    printf("Be careful though, the galaxy is full of dangers!\n\n");
}

void displayPlanetInfo(int planetNum){
    printf("Planet %d:\n", planetNum);
    printf("Name: Planet%d\n", planetNum);
    int resource = rand() % 3; //random resource
    switch(resource){
        case 0:
            printf("Resource: Water\n");
            break;
        case 1:
            printf("Resource: Minerals\n");
            break;
        case 2:
            printf("Resource: Gas\n");
            break;
    }
    int danger = rand() % 3; //random danger level
    switch(danger){
        case 0:
            printf("Danger Level: Low\n");
            break;
        case 1:
            printf("Danger Level: Medium\n");
            break;
        case 2:
            printf("Danger Level: High\n");
            break;
    }
    printf("\n");
}

int main(){
    srand(time(NULL)); //initialize random seed
    
    displayOpeningMessage();
    
    int planetCount = 5; //number of planets to explore
    for(int i=1; i<=planetCount; i++){
        printf("Entering orbit around Planet %d...\n", i);
        displayPlanetInfo(i);
        //simulate exploring the planet for a random amount of time
        int explorationTime = rand() % 10 + 1;
        printf("Exploring planet for %d days...\n", explorationTime);
        for(int day=1; day<=explorationTime; day++){
            printf("Day %d: Searching...\n", day);
        }
        printf("Returning to Earth with resources...\n\n");
    }
    
    printf("Mission complete! Returning to Earth...\n");
    
    return 0;
}