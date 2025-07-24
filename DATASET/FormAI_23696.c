//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Struct to hold Baggage details
typedef struct {
    int id;
    int weight;
}Baggage;

//Function to generate random baggage for simulation
void generateRandomBaggage(Baggage *baggage){
    int id = rand()%1000 + 1; //Generate random id
    int weight = rand()%50 + 1; //Generate random weight
    baggage->id = id;
    baggage->weight = weight;
}

int main(){

    //Initialize variables
    int n, i, total_weight = 0;
    printf("Enter number of baggage to simulate: ");
    scanf("%d", &n);

    Baggage *baggage_list = (Baggage*)malloc(n*sizeof(Baggage)); //Allocate memory for baggage struct array
    srand(time(0)); //Seed random generator

    //Generate random baggage
    for(i=0; i<n; i++){
        generateRandomBaggage(&baggage_list[i]);
        printf("Generated Baggage %d with id %d and weight %d\n", i+1, baggage_list[i].id, baggage_list[i].weight);
        total_weight += baggage_list[i].weight;
    }

    printf("Total weight of baggage generated: %d\n", total_weight);

    free(baggage_list); //Free memory

    return 0;
}