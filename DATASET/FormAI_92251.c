//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#define MAX_BAGGAGE 100 //Defines the maximum baggage that can be handled in one round
#define MIN_WEIGHT 1 //Defines the minimum weight of a baggage
#define MAX_WEIGHT 30 //Defines the maximum weight of a baggage

struct Baggage{
    int weight; //Stores the weight of the baggage
    char destination[15]; //Stores the destination of the baggage
}baggage[MAX_BAGGAGE];

//Function to generate random baggage
void generateBaggage(){
    int i;
    for(i=0; i<MAX_BAGGAGE; i++){
        baggage[i].weight = rand()%(MAX_WEIGHT-MIN_WEIGHT+1)+MIN_WEIGHT;
        if(rand()%2 == 0)
            strcpy(baggage[i].destination, "Domestic");
        else
            strcpy(baggage[i].destination, "International");
    }
}

//Function to sort the baggage by weight
void sortByWeight(){
    int i, j;
    struct Baggage temp;
    for(i=0; i<MAX_BAGGAGE; i++){
        for(j=i+1; j<MAX_BAGGAGE; j++){
            if(baggage[i].weight>baggage[j].weight){
                temp = baggage[i];
                baggage[i] = baggage[j];
                baggage[j] = temp;
            }
        }
    }
}

//Function to display the baggage
void displayBaggage(){
    int i;
    printf("Weight\tDestination\n");
    for(i=0; i<MAX_BAGGAGE; i++){
        printf("%d\t%s\n", baggage[i].weight, baggage[i].destination);
    }
}

int main(){
    srand(time(NULL)); //Initialize random number generator
    generateBaggage(); //Generate random baggage
    printf("Baggage Generated\n");
    displayBaggage(); //Display the baggage
    sortByWeight(); //Sort the baggage by weight
    printf("\nBaggage Sorted by Weight\n");
    displayBaggage(); //Display the baggage after sorting by weight
    return 0;
}