//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGGAGE_CAPACITY 100
#define MAX_FLIGHT_CAPACITY 1000
#define MIN_BAGS_PER_PASSENGER 1
#define MAX_BAGS_PER_PASSENGER 3

struct Passenger {
    int id;
    int num_bags;
    int bags[MAX_BAGGAGE_CAPACITY];
};

struct BaggageBelt {
    int bags[MAX_BAGGAGE_CAPACITY];
    int num_bags;
};

struct Flight {
    int id;
    int num_passengers;
    struct Passenger passengers[MAX_FLIGHT_CAPACITY];
};

int main() {
    // Initialize random seed
    srand(time(NULL));
    
    // Initialize baggage belt
    struct BaggageBelt baggage_belt;
    baggage_belt.num_bags = 0;
    
    // Create flight
    struct Flight flight;
    flight.id = 1;
    flight.num_passengers = rand() % MAX_FLIGHT_CAPACITY + 1;
    
    // Add passengers to flight
    for (int i = 0; i < flight.num_passengers; i++) {
        struct Passenger passenger;
        passenger.id = i + 1;
        passenger.num_bags = rand() % (MAX_BAGS_PER_PASSENGER - MIN_BAGS_PER_PASSENGER + 1) + MIN_BAGS_PER_PASSENGER;
        
        // Add bags to passenger
        for (int j = 0; j < passenger.num_bags; j++) {
            // Generate random bag number
            int bag_num = rand() % MAX_BAGGAGE_CAPACITY + 1;
            
            // Check if bag number is already used by another passenger
            int bag_exists = 0;
            for (int k = 0; k < i; k++) {
                for (int l = 0; l < flight.passengers[k].num_bags; l++) {
                    if (flight.passengers[k].bags[l] == bag_num) {
                        bag_exists = 1;
                        break;
                    }
                }
                if (bag_exists) {
                    break;
                }
            }
            
            // Add bag to passenger if not already used
            if (!bag_exists) {
                passenger.bags[j] = bag_num;
            } else {
                j--;
            }
        }
        
        // Add passenger to flight
        flight.passengers[i] = passenger;
        
        // Add bags to baggage belt
        for (int j = 0; j < passenger.num_bags; j++) {
            baggage_belt.bags[baggage_belt.num_bags] = passenger.bags[j];
            baggage_belt.num_bags++;
        }
    }
    
    // Sort bags on baggage belt
    for (int i = 0; i < baggage_belt.num_bags - 1; i++) {
        for (int j = i + 1; j < baggage_belt.num_bags; j++) {
            if (baggage_belt.bags[i] > baggage_belt.bags[j]) {
                int temp = baggage_belt.bags[i];
                baggage_belt.bags[i] = baggage_belt.bags[j];
                baggage_belt.bags[j] = temp;
            }
        }
    }
    
    // Print baggage belt contents
    printf("Baggage belt contents for Flight %d:\n", flight.id);
    for (int i = 0; i < baggage_belt.num_bags; i++) {
        printf("Bag %d\n", baggage_belt.bags[i]);
    }
    
    return 0;
}