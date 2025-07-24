//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to randomly generate a baggage weight between 10 to 100 kg
int generateWeight(){
    return rand() % 91 + 10; 
}

// function to simulate the arrival of new bags at the conveyor
int newBagArrives(int* conveyor,int capacity){
    int weight = generateWeight();
    for(int i=0;i<capacity;i++){
        if(conveyor[i] == 0){
            conveyor[i] = weight;
            return 1;
        }
    }
    return 0;
}

// function to simulate the removal of bags from the conveyor and loading onto a plane
int removeBag(int* conveyor,int capacity){
    for(int i=0;i<capacity;i++){
        if(conveyor[i] != 0){
            conveyor[i] = 0;
            return 1;
        }
    }
    return 0;
}

// function to display the current status of the conveyor
void displayConveyor(int* conveyor,int capacity){
    printf("Conveyor Status: ");
    for(int i=0;i<capacity;i++){
        printf("%d ",conveyor[i]);
    }
    printf("\n");
}

int main(){
    int capacity = 10;
    int conveyor[capacity];
    int numBagsLoaded = 0;
    srand(time(NULL)); // to seed random number generator with current time
    
    // initialize conveyor with all values as 0
    for(int i=0;i<capacity;i++){
        conveyor[i] = 0;
    }
    
    printf("Airport Baggage Handling Simulation\n\n");
    printf("Conveyor Capacity: %d\n",capacity);
    
    // main simulation loop
    while(1){
        // wait for random time period between 1 to 5 seconds before new bag arrival
        int waitTime = rand() % 5 + 1;
        printf("\nWaiting for %d seconds for new bags to arrive...\n",waitTime);
        sleep(waitTime);
        int bagsArrived = newBagArrives(conveyor,capacity);
        if(bagsArrived){
            printf("%d new bags have arrived at the conveyor\n",bagsArrived);
            displayConveyor(conveyor,capacity);
        }
        
        // wait for random time period between 1 to 3 seconds before removing bags from conveyor
        waitTime = rand() % 3 + 1;
        printf("\nWaiting for %d seconds before removing bags from conveyor...\n",waitTime);
        sleep(waitTime);
        int bagsRemoved = removeBag(conveyor,capacity);
        if(bagsRemoved){
            printf("%d bags have been loaded onto the plane\n",bagsRemoved);
            numBagsLoaded += bagsRemoved;
            displayConveyor(conveyor,capacity);
        }
        
        // check if all bags have been loaded onto the plane
        if(numBagsLoaded == 50){
            printf("\nAll bags have been loaded onto the plane. Simulation ends.\n");
            break;
        }
    }
    
    return 0;
}