//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: creative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//structure for representing bags in the airport
typedef struct bag{
    int id; //unique identifier for the bag
    int weight; //weight of the bag
    char airline[10]; //name of the airline to which the bag belongs
    char destination[50]; //destination of the bag
}Bag;

//function to generate a random bag
Bag generateBag(){
    Bag b;
    static int id = 1; //static variable to keep track of bag ids
    b.id = id++;
    b.weight = rand()%30 + 10; //generating a random weight between 10 and 40 kgs
    char airlines[5][10] = {"Indigo", "Air India", "SpiceJet", "Vistara", "GoAir"}; //an array of airlines
    int air = rand()%5; //randomly selecting an airline from the array
    strcpy(b.airline, airlines[air]);
    char destinations[5][50] = {"Mumbai", "Delhi", "Chennai", "Kolkata", "Bangalore"}; //an array of destinations
    int dest = rand()%5; //randomly selecting a destination from the array
    strcpy(b.destination, destinations[dest]);
    return b;
}

int main(){
    srand(time(NULL));
    //creating an array of 100 bags
    Bag bags[100];
    for(int i=0; i<100; i++){
        bags[i] = generateBag();
    }

    //sorting the bags based on their weight and printing the bags to the console
    printf("Bags in the airport:\n");
    printf("ID  Weight  Airline     Destination\n");
    for(int i=0; i<100; i++){
        for(int j=i+1; j<100; j++){
            if(bags[i].weight > bags[j].weight){
                Bag temp = bags[i];
                bags[i] = bags[j];
                bags[j] = temp;
            }
        }
        printf("%-4d%-8d%-12s%s\n", bags[i].id, bags[i].weight, bags[i].airline, bags[i].destination);
    }

    //sending the bags to the appropriate conveyors based on their airline and destination
    for(int i=0; i<100; i++){
        printf("\nSending bag with ID %d to conveyor ", bags[i].id);
        if(strcmp(bags[i].airline, "Indigo") == 0){
            if(strcmp(bags[i].destination, "Mumbai") == 0)
                printf("1A\n");
            else
                printf("1B\n");
        }
        else if(strcmp(bags[i].airline, "Air India") == 0){
            if(strcmp(bags[i].destination, "Delhi") == 0)
                printf("2A\n");
            else
                printf("2B\n");
        }
        else if(strcmp(bags[i].airline, "SpiceJet") == 0){
            if(strcmp(bags[i].destination, "Chennai") == 0)
                printf("3A\n");
            else
                printf("3B\n");
        }
        else if(strcmp(bags[i].airline, "Vistara") == 0){
            if(strcmp(bags[i].destination, "Kolkata") == 0)
                printf("4A\n");
            else
                printf("4B\n");
        }
        else{
            if(strcmp(bags[i].destination, "Bangalore") == 0)
                printf("5A\n");
            else
                printf("5B\n");
        }
    }

    return 0;
}