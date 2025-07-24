//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGS 1000

// Structure for Bag
typedef struct {
    int id;
    bool isPriority;
} Bag;

// Function to generate a random bag
Bag generateBag(int id) {
    Bag bag;
    bag.id = id;
    bag.isPriority = rand() % 2;
    return bag;
}

// Function to check if two bags are equal
bool isEqual(Bag b1, Bag b2) {
    return b1.id == b2.id && b1.isPriority == b2.isPriority;
}

// Function to print the details of a bag
void printBag(Bag bag) {
    printf("Bag %d: Priority - %s\n", bag.id, bag.isPriority ? "Yes" : "No");
}

// Function to sort the bags based on priority
void sortBags(Bag bags[], int n) {
    int i, j;
    Bag temp;
    for(i = 0; i < n-1; i++) {
        for(j = i + 1; j < n; j++) {
            if(bags[i].isPriority < bags[j].isPriority) {
                temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
    }
}

// Function to simulate the airport baggage handling system
void simulateAirportSystem(int n) {
    // Generate n random bags
    Bag bags[MAX_BAGS];
    int i;
    for(i = 0; i < n; i++) {
        bags[i] = generateBag(i+1);
    }
    
    // Display the details of the bags
    printf("Details of the bags:\n");
    for(i = 0; i < n; i++) {
        printBag(bags[i]);
    }
    
    // Sort the bags based on priority
    sortBags(bags, n);
    
    // Display the details of the bags after sorting
    printf("\nDetails of the bags after sorting:\n");
    for(i = 0; i < n; i++) {
        printBag(bags[i]);
    }
}

// Driver function
int main() {
    srand(time(0)); // Seed the random number generator
    int n = 10; // Number of bags to generate
    simulateAirportSystem(n);
    return 0;
}