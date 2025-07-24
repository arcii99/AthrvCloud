//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// Function Prototypes
void initBaggage(int baggage[], int size);
void printBaggage(int baggage[], int size);
void shuffleArray(int array[], int size);
void handleBaggage(int baggage[], int size);

int main()
{
    srand(time(NULL)); // Set random seed
    
    int baggage[10]; // Array of baggage
    int size = sizeof(baggage) / sizeof(baggage[0]); // Calculate array size
    
    initBaggage(baggage, size); // Initialize baggage with values
    printBaggage(baggage, size); // Print initial order of baggage
    
    shuffleArray(baggage, size); // Shuffle the array
    printBaggage(baggage, size); // Print shuffled order of baggage
    
    handleBaggage(baggage, size); // Handle the baggage based on flight departure times
    
    return 0;
}

// Function to initialize baggage array with values
void initBaggage(int baggage[], int size)
{
    for(int i = 0; i < size; i++)
    {
        baggage[i] = i + 1; // Set baggage values as integers 1 through 10
    }
}

// Function to print baggage array
void printBaggage(int baggage[], int size)
{
    printf("Baggage Order: ");
    for(int i = 0; i < size; i++)
    {
        printf("%d ", baggage[i]); // Print each baggage number
    }
    printf("\n");
}

// Function to shuffle the baggage array
void shuffleArray(int array[], int size)
{
    for(int i = size - 1; i > 0; i--)
    {
        int randomIndex = rand() % (i + 1); // Calculate a random index between 0 and i
        int temp = array[i]; // Swap elements at index i and the random index 
        array[i] = array[randomIndex];
        array[randomIndex] = temp;
    }
}

// Function to handle baggage based on flight departure times
void handleBaggage(int baggage[], int size)
{
    printf("Handling Baggage...\n");
    for(int i = 0; i < size; i++)
    {
        int departureTime = rand() % 24; // Calculate a random departure time between 0 and 23
        printf("Baggage %d is being handled for flight departing at %d:00\n", baggage[i], departureTime);
    }
    printf("All baggage has been handled!\n");
}