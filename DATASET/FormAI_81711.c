//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_FLIGHTS 20
#define MAX_NUM_PASSENGERS 200
#define MAX_NUM_BAGS 500

//Struct for bags
typedef struct Baggage {
    int bag_id;
    int passenger_id;
    int flight_id;
} Baggage;

//Struct for flights
typedef struct Flight {
    int flight_id;
    int num_bags;
    Baggage baggage[MAX_NUM_BAGS];
} Flight;

//Struct for passenger
typedef struct Passenger {
    int passenger_id;
    int num_bags;
    Baggage baggage[MAX_NUM_BAGS];
} Passenger;

//Function declarations
void assign_bags_to_flights(Flight flights[], int num_flights, Passenger passengers[], int num_passengers);
void print_passenger_bags(Passenger passengers[], int num_passengers);
void print_flight_bags(Flight flights[], int num_flights);

int main(void) {
    //Seed the random number generator
    srand(time(NULL));
    
    //Create sample flights and passengers
    Flight flights[MAX_NUM_FLIGHTS];
    Passenger passengers[MAX_NUM_PASSENGERS];
    
    for(int i = 0; i < MAX_NUM_FLIGHTS; i++) {
        flights[i].flight_id = i + 1;
        flights[i].num_bags = 0;
    }
    
    for(int i = 0; i < MAX_NUM_PASSENGERS; i++) {
        passengers[i].passenger_id = i + 1;
        passengers[i].num_bags = rand() % 4 + 1; //Assign random number of bags between 1 and 4
    }
    
    //Assign bags to flights
    assign_bags_to_flights(flights, MAX_NUM_FLIGHTS, passengers, MAX_NUM_PASSENGERS);
    
    //Print passenger and flight bags
    print_passenger_bags(passengers, MAX_NUM_PASSENGERS);
    print_flight_bags(flights, MAX_NUM_FLIGHTS);
    
    return 0;
}

void assign_bags_to_flights(Flight flights[], int num_flights, Passenger passengers[], int num_passengers) {
    //Assign bags to flights
    for(int i = 0; i < num_passengers; i++) {
        int random_flight_index = rand() % num_flights;
        int num_bags_to_assign = passengers[i].num_bags;
        
        for(int j = 0; j < num_bags_to_assign; j++) {
            if(flights[random_flight_index].num_bags < MAX_NUM_BAGS) { //Check if flight still has space for more bags
                Baggage new_bag;
                new_bag.bag_id = flights[random_flight_index].num_bags + 1;
                new_bag.passenger_id = passengers[i].passenger_id;
                new_bag.flight_id = flights[random_flight_index].flight_id;
                
                flights[random_flight_index].baggage[flights[random_flight_index].num_bags] = new_bag;
                flights[random_flight_index].num_bags++;
                
                passengers[i].baggage[passengers[i].num_bags - num_bags_to_assign + j] = new_bag;
            }
            else {
                printf("Flight %d has no more space for bags.\n", flights[random_flight_index].flight_id);
                break;
            }
        }
    }
}

void print_passenger_bags(Passenger passengers[], int num_passengers) {
    printf("Passenger bags:\n");
    
    for(int i = 0; i < num_passengers; i++) {
        printf("Passenger %d: %d bags\n", passengers[i].passenger_id, passengers[i].num_bags);
        
        for(int j = 0; j < passengers[i].num_bags; j++) {
            printf("    Bag %d, Flight %d\n", passengers[i].baggage[j].bag_id, passengers[i].baggage[j].flight_id);
        }
        
        printf("\n");
    }
}

void print_flight_bags(Flight flights[], int num_flights) {
    printf("Flight bags:\n");
    
    for(int i = 0; i < num_flights; i++) {
        printf("Flight %d: %d bags\n", flights[i].flight_id, flights[i].num_bags);
        
        for(int j = 0; j < flights[i].num_bags; j++) {
            printf("    Bag %d, Passenger %d\n", flights[i].baggage[j].bag_id, flights[i].baggage[j].passenger_id);
        }
        
        printf("\n");
    }
}