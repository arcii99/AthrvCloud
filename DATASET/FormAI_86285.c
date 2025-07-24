//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("Welcome to the Airport Baggage Handling Simulation! \n");
    printf("We will simulate the conveyor belt and baggage system in a hilarious way! \n");

    srand(time(NULL)); // seed random generator

    int conveyor_belt[10];
    int baggage_xray[10];
    
    int passengers = rand() % 50 + 1; // simulate up to 50 passengers
    
    printf("Creating %d passengers and their baggage... \n", passengers);
    
    for(int i = 0; i < passengers; i++){
        int bags = rand() % 5 + 1; // simulate up to 5 bags per passenger
        printf("Passenger %d has %d bags! \n", i+1, bags);
        for(int j = 0; j < bags; j++){
            int bag_weight = rand() % 50 + 1; // simulate bag weights between 1-50 lbs
            conveyor_belt[j] = bag_weight;
            printf("Added bag %d for passenger %d with weight %d lbs to the conveyor belt! \n", j+1, i+1, bag_weight);
        }
    }
    
    printf("Starting conveyor belt and sending baggage to the X-ray machine... \n");

    for(int i = 0; i < passengers; i++){
        int bags = rand() % 5 + 1;
        for(int j = 0; j < bags; j++){
            baggage_xray[j] = conveyor_belt[j]; // send bags to xray
            printf("Bag %d for passenger %d sent to the X-ray machine! \n", j+1, i+1);
        }
    }
    
    printf("Checking baggage for contraband... \n");
    
    for(int i = 0; i < 10; i++){
        int contraband = rand() % 100 + 1; // simulate a 1% chance of contraband
        if(contraband == 1){
            printf("Oh no! Bag %d is flagged for contraband! \n", i+1);
            continue; // skip baggage return process
        }
        else{
            printf("Bag %d is cleared for travel! \n", i+1);
        }
    }
    
    printf("Returning baggage to the conveyor belt... \n");
    
    for(int i = 0; i < passengers; i++){
        int bags = rand() % 5 + 1;
        for(int j = 0; j < bags; j++){
            conveyor_belt[j] = baggage_xray[j]; // return cleared baggage to conveyor
            printf("Bag %d for passenger %d returned to the conveyor belt! \n", j+1, i+1);
        }
    }
    
    printf("Loading cleared baggage onto the plane... \n");
    
    for(int i = 0; i < passengers; i++){
        int bags = rand() % 5 + 1;
        for(int j = 0; j < bags; j++){
            printf("Bag %d for passenger %d loaded onto the plane! \n", j+1, i+1);
        }
    }
    
    printf("========================= \n");
    printf("All passengers boarded! Have a safe flight! \n");
    printf("========================= \n");

    return 0;
}