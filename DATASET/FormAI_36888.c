//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGGAGE 20

int main(){
    srand(time(0)); //for generating random numbers

    int passenger_baggage[MAX_BAGGAGE];
    int total_baggage = 0;

    //Generate random baggage for each passenger
    for(int i=0; i<MAX_BAGGAGE; i++){
        passenger_baggage[i] = rand() % 5 + 1; //each passenger can have 1 to 5 bags
        total_baggage += passenger_baggage[i]; //sum up the total baggage
    }

    //Display the total number of baggage
    printf("Total number of baggage in the airport: %d\n", total_baggage);

    //Simulate the baggage handling process
    int baggage_checked = 0;
    int baggage_left = total_baggage;

    while(baggage_left != 0){
        int baggage_to_check = rand() % 6; //check up to 5 baggage at a time
        if(baggage_to_check > baggage_left){ //make sure we don't check more than we have
            baggage_to_check = baggage_left;
        }

        printf("\n%d baggage checked.", baggage_to_check);
        baggage_left -= baggage_to_check;
        baggage_checked += baggage_to_check;

        if(baggage_left == 0){
            printf("\nAll baggage has been checked and loaded onto the plane.");
        }
        else{
            printf("\n%d baggage left to be checked and loaded onto the plane.", baggage_left);
            printf("\nContinue checking baggage.\n");
        }
    }

    return 0;
}