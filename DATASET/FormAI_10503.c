//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGS 30
#define MAX_BOX_SIZE 60

//defining a structure for box
typedef struct{
    int width;
    int height;
    int depth;
}Box;

//defining a structure for bag
typedef struct{
    int weight;
    Box box;
}Bag;

//This function returns a random bag weight between 5 and 50 kgs
int getRandomWeight(){
    return (rand() % 46) + 5;
}

//This function generates a random box with random dimensions
Box getRandomBox(){
    Box box;
    box.width = rand() % MAX_BOX_SIZE + 1;
    box.height = rand() % MAX_BOX_SIZE + 1;
    box.depth = rand() % MAX_BOX_SIZE + 1;
    return box;
}

//This function generates a random bag with random weight and random box dimensions
Bag getRandomBag(){
    Bag bag;
    bag.weight = getRandomWeight();
    bag.box = getRandomBox();
    return bag;
}


int main(){
    srand(time(NULL)); //seeding the random number generator
    int bagsCount = rand() % MAX_BAGS + 1; //Generating a random number of bags between 1 and MAX_BAGS
    
    printf("Number of bags to simulate: %d\n", bagsCount);

    Bag bags[bagsCount]; //Initializing an array of Bags
    
    //Populating the bags array with random bags
    for(int i=0; i<bagsCount; i++){
        bags[i] = getRandomBag();
        printf("Bag %d - Weight: %d kgs, Box Dimensions: %dx%dx%d\n", i+1, bags[i].weight, bags[i].box.width, bags[i].box.height, bags[i].box.depth);
    }

    //Simulating the baggage handling process
    int totalWeight = 0;
    int totalVolume = 0;
    for(int i=0; i<bagsCount; i++){
        totalWeight += bags[i].weight;
        totalVolume += bags[i].box.width * bags[i].box.height * bags[i].box.depth;
    }

    printf("\n\nTotal Weight of the bags: %d kgs\n", totalWeight);
    printf("Total Volume of the bags: %d cubic meters\n", totalVolume);
    
    return 0;
}