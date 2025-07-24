//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10

struct Bag {
    int number;
    int weight; 
};

void printBag(struct Bag *b)
{
    printf("Bag number: %d, Weight: %d kg\n", b->number, b->weight);
}

int main()
{
    srand(time(NULL));
    struct Bag bags[MAX_BAGS];
    int numOfBags = 0;
    int i, j;

    for(i = 0; i < MAX_FLIGHTS; i++){
        printf("\n~~~~~~~~~~~Processing Flight %d~~~~~~~~~~~~~\n", i+1);

        // Generate random number of bags for each flight
        int numOfBagsForFlight = rand() % 20 + 1;
        printf("%d bags have arrived for this flight.\n", numOfBagsForFlight);

        // Randomly generate weights for each bag
        for(j = 0; j < numOfBagsForFlight; j++){
            bags[numOfBags].number = numOfBags+1;
            bags[numOfBags].weight = rand() % 30 + 1;
            printBag(&bags[numOfBags]);
            numOfBags++;
        }

        printf("\nSorting bags by weight...\n");
        // Sorting bags in ascending order of weight
        for(j = 0; j < numOfBagsForFlight; j++){
            int smallest = j;
            int k;

            for(k = j+1; k < numOfBagsForFlight; k++){
                if(bags[k].weight < bags[smallest].weight){
                    smallest = k;
                }
            }

            struct Bag temp = bags[j];
            bags[j] = bags[smallest];
            bags[smallest] = temp;
        }

        // Loading bags onto plane in reverse order of weight
        printf("\nLoading bags onto plane...\n");
        for(j = numOfBagsForFlight - 1; j >= 0; j--){
            printBag(&bags[j]);
        }

        printf("\n~~~~~~~Flight %d Departing~~~~~~~\n", i+1);
    }

    printf("\nAll flights have departed. Goodbye!\n");

    return 0;
}