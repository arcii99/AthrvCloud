//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random room
int generateRoom(){
    int room = rand() % 5;
    return room;
}

// Function to simulate a haunted house
void simulateHauntedHouse(){
    // Initialize variables
    int currentRoom = 0;
    int turn = 0;
    
    // Print initial message
    printf("Welcome to the Haunted House simulator!\n");
    printf("You have entered the house, and you are in the living room.\n");
    
    // Loop until player exits house or dies
    while(1){
        // Increment turn count
        turn++;
        
        // Generate random event
        int event = rand() % 5;
        
        // Determine which event occurred and print appropriate message
        switch(event){
            case 0:
                printf("You hear a strange noise coming from the kitchen...\n");
                break;
            case 1:
                printf("The lights flicker, then go out...\n");
                break;
            case 2:
                printf("You feel a cold breeze brush past you...\n");
                break;
            case 3:
                printf("You smell something rotten coming from the basement...\n");
                break;
            case 4:
                printf("You see a shadow move across the hallway...\n");
                break;
        }
        
        // Generate random action
        int action = rand() % 3;
        
        // Determine which action the player takes and print appropriate message
        switch(action){
            case 0:
                printf("You decide to investigate.\n");
                break;
            case 1:
                printf("You try to ignore it and continue exploring...\n");
                break;
            case 2:
                printf("You run back to the previous room.\n");
                break;
        }
        
        // Only move to a new room if the player decided to investigate and didn't run back
        if(action != 2){
            // Generate random room
            int newRoom = generateRoom();
            
            // Print message indicating new location
            switch(newRoom){
                case 0:
                    printf("You have entered the living room.\n");
                    break;
                case 1:
                    printf("You have entered the kitchen.\n");
                    break;
                case 2:
                    printf("You have entered the dining room.\n");
                    break;
                case 3:
                    printf("You have entered the bedroom.\n");
                    break;
                case 4:
                    printf("You have entered the basement.\n");
                    break;
            }
            
            // Update current room
            currentRoom = newRoom;
        }
        
        // Check if player has won or lost
        if(currentRoom == 0 && turn > 10){
            printf("You have successfully escaped the house!\n");
            break;
        }
        else if(event == 2 && action == 0){
            printf("The cold breeze was actually the ghost of the previous homeowner. You have died!\n");
            break;
        }
        else if(event == 3 && action == 0){
            printf("You have found a hidden room filled with treasure! You have won!\n");
            break;
        }
    }
}

// Main function
int main(){
    // Seed the random number generator
    srand(time(NULL));
    
    // Call the haunted house simulation function
    simulateHauntedHouse();
    
    return 0;
}