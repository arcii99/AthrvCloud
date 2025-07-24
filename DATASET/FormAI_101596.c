//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BAGS 50               // maximum number of bags in the system
#define MAX_CONVEYOR 20           // maximum number of bags on the conveyor belt
#define NUM_TICKETS 100           // total number of tickets issued
#define TICKET_PROB 0.85          // probability of a passenger having a ticket
#define ARRIVAL_PROB 0.7          // probability of a passenger arriving at the conveyor belt
#define BAGS_PER_PASS 3           // number of bags each passenger is carrying
#define FLIGHT_TIME 15            // time taken for one flight cycle in minutes
#define BAG_TRANSFER_TIME 2       // time taken to transfer one bag to the airplane in minutes
#define CONVEYOR_TRANSFER_TIME 1  // time taken to transfer one bag on the conveyor belt in minutes
#define SIMULATION_TIME 180       // total simulation time in minutes

int main()
{
    srand(time(NULL));           // seed the random number generator
    
    // Declare and initialize variables
    int i, j, k, t, num_bags, bags_on_conveyor, bags_transferred;
    int bags_in_system[MAX_BAGS];
    int tickets_issued = 0;
    int passengers_arrived = 0;
    int total_bags_transferred = 0;
    int flight_cycles = 0;

    // Initialize the bags in the system to 0
    for (i = 0; i < MAX_BAGS; i++) {
        bags_in_system[i] = 0;
    }
    
    // Simulation loop
    for (t = 0; t < SIMULATION_TIME; t += FLIGHT_TIME) {
        printf("Flight Cycle %d\n", flight_cycles + 1);
        printf("=====================\n");

        // Generate passengers and bags
        num_bags = 0;
        for (i = 0; i < NUM_TICKETS; i++) {
            if ((double) rand() / (double) RAND_MAX < TICKET_PROB) {
                tickets_issued++;
                num_bags += BAGS_PER_PASS;
                if ((double) rand() / (double) RAND_MAX < ARRIVAL_PROB) {
                    passengers_arrived++;
                }
            }
        }
        printf("%d passengers arrive for this flight.\n", passengers_arrived);
        printf("%d bags to be loaded onto the plane.\n", num_bags);

        // Load bags onto the conveyor belt
        bags_on_conveyor = 0;
        for (i = 0; i < passengers_arrived; i++) {
            for (j = 0; j < BAGS_PER_PASS; j++) {
                if (num_bags > 0 && bags_on_conveyor < MAX_CONVEYOR) {
                    bags_in_system[num_bags - 1] = t;
                    num_bags--;
                    bags_on_conveyor++;
                }
            }
        }
        printf("%d bags loaded onto the conveyor belt.\n", bags_on_conveyor);

        // Transfer bags to the airplane
        bags_transferred = 0;
        for (i = 0; i < MAX_BAGS; i++) {
            if (bags_in_system[i] != 0 && (t - bags_in_system[i]) >= BAG_TRANSFER_TIME) {
                bags_transferred++;
                bags_in_system[i] = 0;
            }
        }
        printf("%d bags transferred to the airplane.\n", bags_transferred);

        // Transfer bags on the conveyor belt
        bags_transferred = 0;
        for (i = 0; i < MAX_BAGS; i++) {
            if (bags_in_system[i] != 0 && (t - bags_in_system[i]) >= CONVEYOR_TRANSFER_TIME) {
                bags_on_conveyor--;
                bags_transferred++;
                bags_in_system[i] = 0;
            }
        }
        printf("%d bags transferred on the conveyor belt.\n", bags_transferred);

        // Calculate statistics for this flight cycle
        printf("Statistics for this flight cycle:\n");
        printf("Total bags transferred: %d\n", bags_transferred);
        printf("Total bags in system: %d\n", MAX_BAGS - num_bags);
        printf("Total bags on conveyor belt: %d\n", bags_on_conveyor);

        // Update overall statistics
        total_bags_transferred += bags_transferred;
        flight_cycles++;
        passengers_arrived = 0;

        printf("\n");
    }

    // Output final statistics
    printf("Simulation complete.\n");
    printf("Total bags transferred: %d\n", total_bags_transferred);
    printf("Total flights: %d\n", flight_cycles);
    printf("Average bags transferred per flight cycle: %.2lf\n", (double) total_bags_transferred / (double) flight_cycles);
    printf("Tickets issued for all flight cycles: %d\n", tickets_issued);
    printf("Passengers arrived for all flight cycles: %d\n", passengers_arrived * flight_cycles);

    return 0;
}