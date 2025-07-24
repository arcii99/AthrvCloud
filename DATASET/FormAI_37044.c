//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_BAGS 100
#define MAX_FLIGHTS 10
#define MAX_BAG_WEIGHT 50

void check_in();
void security_check();
void baggage_claim();

int main(){

    int flights[MAX_FLIGHTS];
    for(int i = 0; i < MAX_FLIGHTS; i++){
        flights[i] = rand() % 500;
        printf("The flight number for flight %d is %d\n", i+1,flights[i]);
    }

    check_in();
    security_check();
    baggage_claim();

    return 0;
}

void check_in(){

    int num_bags;
    int bag_weight;
    int total_weight = 0;

    for(int flight = 0; flight < MAX_FLIGHTS; flight++){
        printf("Checking in for flight %d\n", flight+1);
        for(int i = 0; i < MAX_BAGS; i++){    
            num_bags = rand() % 10;
            for(int j = 0; j < num_bags; j++){
                bag_weight = rand() % MAX_BAG_WEIGHT;
                total_weight += bag_weight;
            }
            printf("Passenger %d has checked in %d bags with a total weight of %d kg\n", i+1, num_bags, total_weight);
        }
    }
}

void security_check(){
    int num_bags;
    int has_bomb;
    for(int flight = 0; flight < MAX_FLIGHTS; flight++){
        printf("Security check for flight %d\n", flight+1);
        for(int i = 0; i < MAX_BAGS; i++){
            num_bags = rand() % 10;
            for(int j = 0; j < num_bags; j++){
                has_bomb = rand() % 2;
                if(has_bomb){
                    printf("Passenger %d's bag is flagged for additional screening\n", i+1);
                }
            }
        }
    }
}

void baggage_claim(){
    int num_bags;
    int total_weight = 0;

    for(int flight = 0; flight < MAX_FLIGHTS; flight++){
        printf("Baggage claim for flight %d\n", flight+1);
        for(int i = 0; i < MAX_BAGS; i++){
            num_bags = rand() % 10;
            for(int j = 0; j < num_bags; j++){
                total_weight += rand() % MAX_BAG_WEIGHT;
            }
            printf("Passenger %d has %d bags with a total weight of %d kg\n", i+1, num_bags, total_weight);
        }
    }
}