//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: immersive
#include<stdlib.h>
#include<time.h>
#include<stdio.h>

int main() {

    printf("Welcome to the Alien Invasion Probability Calculator! Are you ready to find out your chances of surviving an alien invasion? Let's get started!\n");

    srand(time(0)); //allows us to generate random numbers based on time

    int numAttacks = rand() % 10 + 1; //generates a random number of attacks between 1 and 10
    int numDays = rand() % 30 + 1; //generates a random number of days between 1 and 30
    float popDensity = (float) (rand() % 10000) / 100; //generates a random population density between 0 and 100

    printf("Based on our calculations, there will be %d attacks over the course of %d days.\n", numAttacks, numDays);
    printf("The population density in your area is %.2f people per square kilometer.\n", popDensity);

    float probSurvival = (float) (numAttacks * numDays) / (popDensity * 1000); //calculates the probability of survival

    printf("Your chance of survival in the event of an alien invasion is %.2f percent.\n", probSurvival);

    printf("Thank you for using the Alien Invasion Probability Calculator. Stay safe out there!\n");

    return 0;
}