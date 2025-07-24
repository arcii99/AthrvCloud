//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//Declaration of variables
int total_time = 10;
int total_baggage = 100;
int baggage_counter = 0;
int baggage_claimed = 0;
int conveyor_belt_capacity = 10;
int luggage_counter_capacity = 5;
int available_luggage_counters = 5;
int baggage_waiting_for_pickup[100];
int baggage_on_belt[10];
int bags_claimed_from_conveyor_belt = 0;
int bags_claimed_from_counters = 0;
int lost_luggage_count = 0;

//Function to generate random number within a specified range
int generate_random(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

//Function to display current status
void display_current_status(){
    printf("Total baggage: %d\n", total_baggage);
    printf("Baggage claimed: %d\n", baggage_claimed);
    printf("Baggage still on belt: ");
    for(int i=0; i<conveyor_belt_capacity; i++){
        printf("%d ", baggage_on_belt[i]);
    }
    printf("\n");
    printf("Baggage waiting for pickup: ");
    for(int i=0; i<baggage_counter; i++){
        printf("%d ", baggage_waiting_for_pickup[i]);
    }
    printf("\n");
    printf("Luggage counters available: %d\n\n", available_luggage_counters);
}

int main(){

    //Random seed for generating numbers
    srand(time(NULL));

    //Add baggage to conveyor belt until it is full
    while(baggage_counter < total_baggage && baggage_claimed + lost_luggage_count < total_baggage){
        int new_baggage = generate_random(1,5);
        printf("New baggage added to conveyor belt: %d\n", new_baggage);
        if(baggage_counter < conveyor_belt_capacity){
            baggage_waiting_for_pickup[baggage_counter] = new_baggage;
            baggage_counter++;
        } else {
            printf("Luggage lost due to conveyor belt overflow: %d\n", new_baggage);
            lost_luggage_count++;
        }
        display_current_status();
    }

    //Transfer baggage from conveyor belt to luggage counters
    while(baggage_claimed + lost_luggage_count < total_baggage && available_luggage_counters > 0){
        printf("Baggage transferred from conveyor belt to luggage counter\n");
        bags_claimed_from_counters = 0;
        for(int i=0; i<available_luggage_counters; i++){
            if(baggage_counter > 0){
                bags_claimed_from_counters++;
                int claimed_baggage = baggage_waiting_for_pickup[0];
                baggage_claimed += claimed_baggage;
                baggage_counter--;
                available_luggage_counters--;
                printf("Baggage claimed from luggage counter: %d\n", claimed_baggage);
                int new_baggage_on_belt = generate_random(1,5);
                printf("New baggage added to conveyor belt: %d\n", new_baggage_on_belt);
                baggage_on_belt[i] = new_baggage_on_belt; 
            }
        }

        //Check if baggage on conveyor belt has been claimed by passengers
        for(int i=0; i<conveyor_belt_capacity; i++){
            if(baggage_on_belt[i] > 0){
                printf("Checking baggage on conveyor belt: %d\n", baggage_on_belt[i]);
                if(generate_random(1,10) > 8){
                    printf("Baggage claimed from conveyor belt by passenger: %d\n", baggage_on_belt[i]);
                    bags_claimed_from_conveyor_belt++;
                    baggage_claimed += baggage_on_belt[i];
                    baggage_on_belt[i] = 0;
                }
            }
        }
        available_luggage_counters = bags_claimed_from_counters;
        display_current_status();
    }

    //Display final status
    printf("\nTOTAL BAGGAGE: %d\n", total_baggage);
    printf("BAGGAGE CLAIMED: %d\n", baggage_claimed);
    printf("BAGGAGE STILL ON CONVEYOR BELT: ");
    for(int i=0; i<conveyor_belt_capacity; i++){
        printf("%d ", baggage_on_belt[i]);
    }
    printf("\nBAGGAGE WAITING FOR PICKUP: ");
    for(int i=0; i<baggage_counter; i++){
        printf("%d ", baggage_waiting_for_pickup[i]);
    }
    printf("\nTOTAL LOST LUGGAGE: %d", lost_luggage_count);

    return 0;
}