//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CAPACITY 100 // maximum capacity of the conveyor belt
#define MAX_WEIGHT 50 // maximum weight of a baggage
#define MIN_WEIGHT 5 // minimum weight of a baggage
#define MAX_DELAY 10 // maximum delay time for a baggage
#define MIN_DELAY 2 // minimum delay time for a baggage

int main(){

    int belt[MAX_CAPACITY]; // Initializing the conveyor belt array
    int head = 0, tail = 0; // head and tail pointers for the conveyor belt 
    int weight = 0, delay = 0; // variables to hold baggage weight and delay time
    int i, j, count = 0; // variables to keep track of baggage count

    srand(time(NULL)); // seeding the random number generator

    printf("Airport Baggage Handling Simulation\n");

    // Loop to simulate the operation of the conveyor belt
    while(head != MAX_CAPACITY){

        // Checking if there is space on the conveyor belt to add baggage
        if(tail < MAX_CAPACITY){

            weight = rand() % (MAX_WEIGHT - MIN_WEIGHT + 1) + MIN_WEIGHT; // generating a random weight for the baggage
            delay = rand() % (MAX_DELAY - MIN_DELAY + 1) + MIN_DELAY; // generating a random delay for the baggage
            belt[tail] = weight; // adding the baggage to the conveyor belt
            tail++; // incrementing the tail pointer
            count++; // incrementing the baggage count
            printf("\nBaggage with weight %d kg added to the conveyor belt\n", weight);
        }

        // Loop to simulate the movement of the conveyor belt and delivery of baggage
        for(i=head; i<tail; i++){
            printf("*"); // each "*" represents a baggage on the conveyor belt
            belt[i]--; // reducing the weight of the baggage as it moves
            if(belt[i] == 0){
                printf("\nBaggage with weight %d kg delivered from the conveyor belt\n", weight);
                count--; // decrementing the baggage count
                // Loop to shift remaining baggage on the conveyor belt to fill the gap
                for(j=i; j<tail-1; j++){
                    belt[j] = belt[j+1]; // shifting the baggage
                }
                tail--; // decrementing the tail pointer
            }
        }

        // Adding a delay between baggage deliveries
        if(head != tail){
            printf("\n");
        }
        for(i=0; i<delay; i++){
            printf(".");
            sleep(1);
        }

        // Checking if the baggage handling is complete
        if(count == 0){
            printf("\nBaggage handling complete\n");
            break;
        }
    }
    return 0;
}