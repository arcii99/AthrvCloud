//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: configurable
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

// configuration constants
#define NUM_BELTS 3
#define MAX_BELT_CAPACITY 10
#define MAX_BAG_PROCESS_TIME 6
#define MAX_NUM_BAGS 20
#define MIN_BAG_ARRIVAL_TIME 2
#define MAX_BAG_ARRIVAL_TIME 5
#define SIMULATION_TIME 30

// global variables
int bagsArrived = 0;
int bagsProcessed = 0;
int totalTimeSpent = 0;
int bagsOnBelts[NUM_BELTS];
int nextBagArrivalTime = 0;

// function prototypes
void initializeBelts();
void processBag(int bagId, int beltId);
void addBagToBelt(int beltId);
void handleBagArrival();
bool isBeltFull(int beltId);
void runSimulation();
int generateRandomNumber(int min, int max);

int main()
{
    srand(time(NULL)); // seed the random number generator
    initializeBelts();
    runSimulation();
    printf("Simulation summary:\n");
    printf("%d bags arrived, %d bags processed.\n", bagsArrived, bagsProcessed);
    printf("Average processing time per bag = %d seconds.\n", totalTimeSpent / bagsProcessed);
    return 0;
}

// Initializes all the belts to have no bags initially.
void initializeBelts()
{
    for (int i = 0; i < NUM_BELTS; i++)
    {
        bagsOnBelts[i] = 0;
    }
}

// Simulates the processing of a single bag by a belt.
void processBag(int bagId, int beltId)
{
    int processingTime = generateRandomNumber(1, MAX_BAG_PROCESS_TIME); // simulate bag processing time
    printf("Bag %d is being processed on belt %d for %d seconds.\n", bagId, beltId, processingTime);
    for (int i = 0; i < processingTime; i++)
    {
        printf("."); // simulate progress
        fflush(stdout); // ensure it is printed immediately
        bagsOnBelts[beltId]--;
        totalTimeSpent++;
        sleep(1); // wait for 1 second to simulate real time
    }
    printf("\nBag %d has been processed on belt %d.\n", bagId, beltId);
    bagsProcessed++;
}

// Adds a new bag to a non-full belt.
void addBagToBelt(int beltId)
{
    bagsOnBelts[beltId]++;
    int bagId = bagsArrived + 1;
    printf("Bag %d has arrived on belt %d.\n", bagId, beltId);
    bagsArrived++;
    processBag(bagId, beltId);
}

// Handles the arrival of a new bag.
void handleBagArrival()
{
    if (bagsArrived >= MAX_NUM_BAGS)
    {
        return;
    }
    int currentTime = bagsArrived * generateRandomNumber(MIN_BAG_ARRIVAL_TIME, MAX_BAG_ARRIVAL_TIME);
    int deltaT = currentTime - nextBagArrivalTime;
    if (deltaT > 0)
    {
        printf("%d seconds until next bag arrives.\n", deltaT);
        sleep(deltaT); // wait to simulate real time
    }
    nextBagArrivalTime = currentTime;
    int emptyBeltFound = false;
    for (int i = 0; i < NUM_BELTS; i++)
    {
        if (!isBeltFull(i))
        {
            addBagToBelt(i);
            emptyBeltFound = true;
            break;
        }
    }
    if (!emptyBeltFound)
    {
        printf("All belts are full. Bag %d has been lost.\n", bagsArrived + 1);
        bagsArrived++;
    }
}

// Determines if a belt is full.
bool isBeltFull(int beltId)
{
    return bagsOnBelts[beltId] >= MAX_BELT_CAPACITY;
}

// Runs the simulation for the specified amount of time.
void runSimulation()
{
    printf("Starting simulation for %d seconds.\n", SIMULATION_TIME);
    for (int i = 0; i < SIMULATION_TIME; i++)
    {
        handleBagArrival();
    }
}

// Generates a random integer between min and max (inclusive).
int generateRandomNumber(int min, int max)
{
    return rand() % (max - min + 1) + min;
}