//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE 50
#define MAX_FLIGHTS 20
#define MAX_TERMINALS 5

void printBaggageStatus(int baggage[MAX_BAGGAGE]);
void printFlightStatus(char flights[MAX_FLIGHTS][10]);

int main()
{
    // Initialize variables and arrays
    int baggage[MAX_BAGGAGE] = {0};
    char flights[MAX_FLIGHTS][10] = {"UA123", "AA456", "DL789", "WN012", "AS345", "B6678", "NK901", "F9432", "G4765", "VS321",
                                     "EI874", "EY567", "LH432", "QR187", "TK456", "BA345", "AF567", "KL321", "CP123", "NH987" };
    int nFlights = sizeof(flights) / sizeof(flights[0]);
    int nTerminals = MAX_TERMINALS;
    srand(time(NULL));

    // Assign flights to random terminals
    int terminalAssignments[MAX_TERMINALS][MAX_FLIGHTS] = {0};
    for(int i = 0; i < nFlights; i++)
    {
        int t = rand() % nTerminals;
        terminalAssignments[t][i] = 1;
    }

    // Simulate baggage handling
    printf("Simulating baggage handling...\n\n");
    for(int i = 0; i < nTerminals; i++)
    {
        printf("Terminal %d:\n", i + 1);
        for(int j = 0; j < nFlights; j++)
        {
            if(terminalAssignments[i][j])
            {
                printf("Flight %s:\n", flights[j]);
                int nBags = rand() % MAX_BAGGAGE;
                for(int k = 0; k < nBags; k++)
                {
                    int bagIndex = rand() % MAX_BAGGAGE;
                    baggage[bagIndex]++;
                }
                printf("Added %d bags\n", nBags);
            }
        }
        printf("\n");
    }

    // Print final baggage status
    printf("Final baggage status:\n");
    printBaggageStatus(baggage);

    return 0;
}

// Print a formatted table of baggage status
void printBaggageStatus(int baggage[MAX_BAGGAGE])
{
    printf("+-------+-----------+\n");
    printf("| Bag # | # Flights |\n");
    printf("+-------+-----------+\n");
    for(int i = 0; i < MAX_BAGGAGE; i++)
    {
        if(baggage[i] > 0)
        {
            printf("| %5d | %9d |\n", i + 1, baggage[i]);
        }
    }
    printf("+-------+-----------+\n");
}

// Print a list of flights and their assigned terminals
void printFlightStatus(char flights[MAX_FLIGHTS][10])
{
    int nFlights = sizeof(flights) / sizeof(flights[0]);
    printf("Flight schedule:\n");
    for(int i = 0; i < nFlights; i++)
    {
        printf("%s: Terminal %d\n", flights[i], rand() % MAX_TERMINALS + 1);
    }
}