//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ada Lovelace
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGGAGE 50
#define MAX_FLIGHTS 10

int main(){
    int num_flights, i, j, num_bags;
    int baggage[MAX_FLIGHTS][MAX_BAGGAGE] = {0};

    srand(time(NULL));

    printf("Enter number of flights: ");
    scanf("%d", &num_flights);

    for(i=0; i<num_flights; i++){
        num_bags = rand() % 50 + 1; //random number of bags for each flight
        printf("Flight %d has %d bags\n", i+1, num_bags);
        for(j=0; j<num_bags; j++){
            baggage[i][j] = rand() % 1000 + 1; //random baggage weights
        }
    }

    for(i=0; i<num_flights; i++){
        printf("Flight %d baggage:\n", i+1);
        for(j=0; j<MAX_BAGGAGE; j++){
            if(baggage[i][j] != 0){
                printf("%d ", baggage[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}