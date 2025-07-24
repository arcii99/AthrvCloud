//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_LUGGAGE_WEIGHT 60
#define MAX_LUGGAGE_QUANTITY 5
#define MAX_FLIGHTS 10

int main() {
    srand(time(NULL));
    int flights[MAX_FLIGHTS][MAX_LUGGAGE_QUANTITY], i, j, total_weight, flight_weight, temp, sorted;
    for (i = 0; i < MAX_FLIGHTS; i++) {
        total_weight = 0;
        for (j = 0; j < MAX_LUGGAGE_QUANTITY; j++) {
            flights[i][j] = rand() % MAX_LUGGAGE_WEIGHT;
            total_weight += flights[i][j];
        }
        printf("Flight %d total weight: %d kg, luggage weights:", i+1, total_weight);
        for (j = 0; j < MAX_LUGGAGE_QUANTITY; j++) {
            printf(" %d", flights[i][j]);
        }
        printf("\n");
    }
    printf("Sorting flights by total weight...\n");
    do {
        sorted = 1;
        for (i = 0; i < MAX_FLIGHTS-1; i++) {
            flight_weight = 0;
            for (j = 0; j < MAX_LUGGAGE_QUANTITY; j++) {
                flight_weight += flights[i][j];
            }
            if (flight_weight < flights[i+1][0]) {
                for (j = 0; j < MAX_LUGGAGE_QUANTITY; j++) {
                    temp = flights[i][j];
                    flights[i][j] = flights[i+1][j];
                    flights[i+1][j] = temp;
                }
                sorted = 0;
            }
        }
    } while (!sorted);
    printf("Flight order for loading: ");
    for (i = 0; i < MAX_FLIGHTS; i++) {
        printf("%d ", i+1);
    }
    printf("\n");
    return 0;
}