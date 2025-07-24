//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE_COUNT 1000  // maximum luggage count for a flight
#define MAX_LUGGAGE_WEIGHT 50   // maximum weight for a single luggage in kg

// structure for luggage
typedef struct {
    int id;
    int weight;
} Luggage;

// function to generate random luggage weight
int generateLuggageWeight() {
    return (rand() % MAX_LUGGAGE_WEIGHT) + 1;
}

// function to print the luggage details
void printLuggageDetails(Luggage luggage) {
    printf("Luggage Id: %d, Weight: %d kg\n", luggage.id, luggage.weight);
}

int main() {
    srand(time(0));
    Luggage luggageList[MAX_LUGGAGE_COUNT];
    int totalLuggageCount = rand() % MAX_LUGGAGE_COUNT;
    int currentLuggageCount = 0;
    
    // add luggage to the list
    for (int i = 0; i < totalLuggageCount; i++) {
        Luggage luggage;
        luggage.id = i+1;
        luggage.weight = generateLuggageWeight();
        luggageList[i] = luggage;
        currentLuggageCount++;
    }
    
    // simulate the baggage handling process
    printf("Total Luggage Count: %d\n", totalLuggageCount);
    printf("--------------------------------------------------\n");
    printf("Starting baggage handling simulation...\n");
    printf("--------------------------------------------------\n");
    
    for (int i = 0; i < currentLuggageCount; i++) {
        printf("\nProcessing Luggage %d - ", luggageList[i].id);
        
        // check luggage weight
        if (luggageList[i].weight > MAX_LUGGAGE_WEIGHT) {
            printf("Rejected: Luggage weight exceeds the maximum weight limit.\n");
            continue;
        }
        
        // move luggage to the loading area
        printf("Moving luggage to the loading area...");
        
        // simulate loading onto the conveyor belt
        printf("\nLoading luggage onto the conveyor belt...");
        
        // simulate unloading from the conveyor belt
        printf("\nUnloading luggage from the conveyor belt...");
        
        // move luggage to the flight
        printf("\nMoving luggage to the flight...");
        
        // confirm the luggage has been added to the flight
        printf("\nLuggage %d added to the flight successfully!\n", luggageList[i].id);
        
        // delay for the next luggage processing
        int delay = (rand() % 5) + 1;
        printf("Next luggage processing in %d seconds...\n", delay);
        sleep(delay);
    }
    
    printf("\n--------------------------------------------------\n");
    printf("Baggage handling simulation completed!\n");
    printf("Total luggage processed: %d\n", currentLuggageCount);
    printf("--------------------------------------------------\n");
    
    return 0;
}