//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct baggage{
    char id[10];
    int weight;
    char destination[20];
};

void printBaggage(struct baggage b){
    printf("Baggage ID: %s\n", b.id);
    printf("Weight: %d kg\n", b.weight);
    printf("Destination: %s\n", b.destination);
}

void loadBaggage(struct baggage b){
    printf("Loading baggage with ID %s...\n", b.id);
    printf("Destination: %s\n", b.destination);
    printf("Weight: %d kg\n", b.weight);
    printf("Baggage loaded successfully!\n");
}

int main(){
    srand(time(NULL)); //To seed random number generator with time
    
    int numOfBaggage = rand()%50 + 1; //Randomly generate number of baggage
    
    struct baggage baggageList[numOfBaggage]; //Creating the Baggage list
    
    char destinations[][20] = {"Paris", "New York", "Tokyo", "Sydney", "Dubai", "Singapore", "London", "Barcelona", "Los Angeles", "Hong Kong"};
    int totalWeight = 0;
    
    //Filling in the details of each baggage
    for(int i=0; i<numOfBaggage; i++){
        sprintf(baggageList[i].id, "BAG-%04d", i+1);
        baggageList[i].weight = rand()%31 + 1;
        totalWeight += baggageList[i].weight;
        strcpy(baggageList[i].destination, destinations[rand()%10]);
    }
    
    //Printing the total number of baggage and the total weight
    printf("Total Baggage: %d\n", numOfBaggage);
    printf("Total Weight: %d kg\n\n", totalWeight);
    
    //Printing the details of all the baggage
    printf("Details of all Baggage:\n");
    for(int i=0; i<numOfBaggage; i++){
        printBaggage(baggageList[i]);
        printf("\n");
    }
    
    //Loading the baggage one by one
    printf("Baggage Loading:\n");
    for(int i=0; i<numOfBaggage; i++){
        loadBaggage(baggageList[i]);
        printf("\n");
    }
    
    return 0;
}