//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGGAGE 100 // Maximum number of baggage in the system
#define MAX_CAPACITY 25 // Maximum baggage capacity of each conveyer belt
#define MAX_INJECTION 5 // Maximum number of injection points
#define MAX_GATE 3 // Maximum number of gate for aircraft
#define MAX_DELAY 10 // Maximum delay time for each injection point and gate

// Function to generate a random integer between min and max values
int generateRandomInt(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// Function to simulate the baggage handling system in an airport
void airportBaggageHandlingSimulation(){
    int injection[MAX_INJECTION][MAX_CAPACITY]; // Array for injection points
    int gate[MAX_GATE][MAX_CAPACITY]; // Array for gate
    int injectionIndex[MAX_INJECTION] = {0}; // Array for current index of injection points
    int gateIndex[MAX_GATE] = {0}; // Array for current index of gates
    int baggageCount = 0; // Counter for number of baggage in the system
    int currentBaggage = 1; // Counter for current baggage
    int injectionDelay[MAX_INJECTION] = {0}; // Array to store random delay time for each injection point
    int gateDelay[MAX_GATE] = {0}; // Array to store random delay time for each gate

    // Seed for random number generation
    srand(time(NULL));

    // Simulation loop for 1 hour
    for(int i = 0; i < 60; i++){
        // Check if there is any baggage in the system
        if(baggageCount < MAX_BAGGAGE){
            // Loop through all injection points to check if there is an empty slot
            for(int j = 0; j < MAX_INJECTION; j++){
                // Check if the current injection point has an empty slot
                if(injectionIndex[j] < MAX_CAPACITY){
                    // Generate random delay time for the injection point
                    if(injectionDelay[j] == 0)
                        injectionDelay[j] = generateRandomInt(1, MAX_DELAY);
                    else if(injectionDelay[j] == 1){
                        // Add a baggage in the injection point
                        injection[j][injectionIndex[j]] = currentBaggage++;
                        baggageCount++;
                        // Reset the delay time for the injection point
                        injectionDelay[j] = 0;
                        // Increment the index for the injection point
                        injectionIndex[j]++;
                        // Check if the maximum capacity of the injection point is reached
                        if(injectionIndex[j] == MAX_CAPACITY)
                            printf("Injection point %d is full.\n", j+1);
                    }
                    else
                        injectionDelay[j]--;
                }
            }
        }

        // Loop through all gates to check if there is any baggage
        for(int j = 0; j < MAX_GATE; j++){
            // Check if the current gate has a baggage
            if(gateIndex[j] > 0){
                // Generate random delay time for the gate
                if(gateDelay[j] == 0)
                    gateDelay[j] = generateRandomInt(1, MAX_DELAY);
                else if(gateDelay[j] == 1){
                    // Remove the baggage from the gate
                    gate[j][0] = 0;
                    for(int k = 1; k < gateIndex[j]; k++)
                        gate[j][k-1] = gate[j][k];
                    gateIndex[j]--;
                    baggageCount--;
                    // Reset the delay time for the gate
                    gateDelay[j] = 0;
                }
                else
                    gateDelay[j]--;
            }
        }

        // Loop through all gates to check if there is any empty slot
        for(int j = 0; j < MAX_GATE; j++){
            // Check if the current gate has an empty slot
            if(gateIndex[j] < MAX_CAPACITY){
                // Loop through all injection points to check if there is any baggage
                for(int k = 0; k < MAX_INJECTION; k++){
                    // Check if the current injection point has any baggage
                    if(injectionIndex[k] > 0){
                        // Generate random delay time for the injection point
                        if(injectionDelay[k] == 0)
                            injectionDelay[k] = generateRandomInt(1, MAX_DELAY);
                        else if(injectionDelay[k] == 1){
                            // Add the baggage to the gate
                            gate[j][gateIndex[j]] = injection[k][0];
                            // Remove the baggage from the injection point
                            injection[k][0] = 0;
                            for(int l = 1; l < injectionIndex[k]; l++)
                                injection[k][l-1] = injection[k][l];
                            injectionIndex[k]--;
                            // Reset the delay time for the injection point
                            injectionDelay[k] = 0;
                            // Increment the index for the gate
                            gateIndex[j]++;
                            // Check if the maximum capacity of the gate is reached
                            if(gateIndex[j] == MAX_CAPACITY)
                                printf("Gate %d is full.\n", j+1);
                            // Check if there is no baggage in the system
                            if(baggageCount == 0)
                                break;
                        }
                        else
                            injectionDelay[k]--;
                    }
                }
            }
        }
    }
}

// Main function to run the airport baggage handling simulation
int main(){
    airportBaggageHandlingSimulation();
    return 0;
}