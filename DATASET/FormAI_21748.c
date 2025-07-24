//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define constants
#define MAX_LUGGAGE 1000
#define MAX_BIN_WEIGHT 1000
#define MAX_BINS 10

// Define structures

// Luggage structure
typedef struct Luggage {
    int id;
    int weight;
} Luggage;

// Bin structure
typedef struct Bin {
    int id;
    int weight;
    int capacity;
    Luggage *luggage[MAX_LUGGAGE];
} Bin;

// Function prototypes
void printBin(Bin bin);
void addLuggageToBin(Luggage *luggage, Bin *bin);
void loadBin(Bin *bin);
void printAllBins(Bin bins[], int num_bins);
void simulateBaggageHandling(int num_luggage, int num_bins, int max_bin_weight);

int main() {
    srand(time(NULL));
    int num_luggage = 50;
    int num_bins = 5;
    int max_bin_weight = 500;
    simulateBaggageHandling(num_luggage, num_bins, max_bin_weight);
    return 0;
}

// Function to print bin
void printBin(Bin bin) {
    printf("Bin ID: %d\n", bin.id);
    printf("Bin Capacity: %d\n", bin.capacity);
    printf("Bin Weight: %d\n", bin.weight);
    printf("Luggage:");
    for (int i = 0; i < MAX_LUGGAGE; i++) {
        if (bin.luggage[i] != NULL) {
            printf("\n\tLuggage ID: %d, Weight: %d", bin.luggage[i]->id, bin.luggage[i]->weight);
        }
    }
    printf("\n\n");
}

// Function to add luggage to bin
void addLuggageToBin(Luggage *luggage, Bin *bin) {
    bin->luggage[bin->weight++] = luggage;
    bin->capacity = bin->capacity - luggage->weight;
}

// Function to load bin
void loadBin(Bin *bin) {
    printf("Loading bin %d...\n", bin->id);
    printf("\tBin capacity: %d\n", bin->capacity);
    printf("\tBin weight: %d\n", bin->weight);

    // Add luggage to bin until it is full or capacity is exceeded
    while (bin->weight < MAX_LUGGAGE && bin->capacity > 0) {
        Luggage *luggage = (Luggage *) malloc(sizeof(Luggage));
        luggage->id = rand() % 1000;
        luggage->weight = rand() % (bin->capacity + 1);
        addLuggageToBin(luggage, bin);
    }

    // Print bin after loading
    printBin(*bin);
}

// Function to print all bins
void printAllBins(Bin bins[], int num_bins) {
    printf("All Bins:\n\n");
    for (int i = 0; i < num_bins; i++) {
        printBin(bins[i]);
    }
}

// Function to simulate baggage handling
void simulateBaggageHandling(int num_luggage, int num_bins, int max_bin_weight) {
    printf("Simulating baggage handling...\n\n");

    // Initialize bins
    Bin bins[MAX_BINS];
    for (int i = 0; i < num_bins; i++) {
        bins[i].id = i + 1;
        bins[i].weight = 0;
        bins[i].capacity = max_bin_weight;
        memset(bins[i].luggage, NULL, sizeof(bins[i].luggage));
    }

    // Initialize luggage
    Luggage luggage[num_luggage];
    for (int i = 0; i < num_luggage; i++) {
        luggage[i].id = rand() % 1000;
        luggage[i].weight = rand() % 100;
    }

    printf("All Luggage:\n\n");
    for (int i = 0; i < num_luggage; i++) {
        printf("Luggage ID: %d, Weight: %d\n", luggage[i].id, luggage[i].weight);
    }

    printf("\n");

    // Load bins with luggage
    for (int i = 0; i < num_bins; i++) {
        loadBin(&bins[i]);
    }

    // Print all bins after loading
    printAllBins(bins, num_bins);
}