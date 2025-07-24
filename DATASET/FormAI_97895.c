//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: excited
#include <stdio.h>

int main(){

    printf("Welcome to the GPS Navigation Simulation program!\n");
    printf("Please enter your starting location: ");
    char start[50]; // initializing the starting location variable
    scanf("%s", &start);
    
    printf("Please enter your destination: ");
    char destination[50]; // initializing the destination variable
    scanf("%s", &destination);
    
    printf("\nCalculating route...\n");
    
    // imagining that we have a pre-determined route stored in the program
    printf("Starting at %s, turn left onto Main St.\n", start);
    printf("Continue straight for 2 miles, then turn right onto 5th Ave.\n");
    printf("In 0.5 miles, turn left onto Elm St.\n");
    printf("Continue straight for 1 mile, then turn right onto Oak St.\n");
    printf("In 0.2 miles, turn left onto Maple St.\n");
    printf("Continue straight for 3 miles, then turn left onto Pine St.\n");
    printf("In 0.1 miles, turn right onto Cedar St.\n");
    printf("You have arrived at %s!\n", destination);

    return 0;
}