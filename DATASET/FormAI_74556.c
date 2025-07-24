//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void printIntro(){
    printf("Welcome to Procedural Space Adventure!\n");
    printf("Your mission is to explore the uncharted regions of space and discover new planets and species.\n");
    printf("Get ready for a thrilling adventure ahead!\n\n");
}

int generateNum(int min, int max){
    int num = rand() % (max - min + 1) + min;
    return num;
}

void travelToPlanet(){
    int planetNum = generateNum(1, 10);
    printf("Travelling to planet %d...\n\n", planetNum);
    printf("You have landed on planet %d!\n", planetNum);
    printf("The atmosphere is %s and the temperature is %d degrees Celsius.\n",
            (generateNum(0, 1) == 0) ? "safe" : "hazardous", generateNum(-150, 60));
    printf("You have discovered a new species on this planet.\n");
    printf("The %s are friendly and offer you some valuable resources.\n\n", (generateNum(0, 1) == 0) ? "Trogles" : "Gorgons");
}

void exploreSystem(int systemNum){
    int numPlanets = generateNum(2, 8);
    printf("Exploring system %d...\n\n", systemNum);
    printf("This system has %d planets to explore.\n", numPlanets);
    for(int i=1;i<=numPlanets;i++){
        travelToPlanet();
    }
    printf("All planets in system %d have been explored.\n", systemNum);
}

void main()
{
    srand(time(0));
    int numSystems = generateNum(3, 6);
    printIntro();
    printf("Your ship can explore %d systems before running out of resources.\n\n", numSystems);
    for(int i=1;i<=numSystems;i++){
        exploreSystem(i);
    }
    printf("Mission complete! You have discovered many new planets and species, and your findings will help advance space exploration.\n");
}