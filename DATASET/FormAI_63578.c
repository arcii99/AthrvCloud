//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to simulate baggage handling at airport
void baggage_handling(int num_passengers, int num_bags) {

    int total_bags = num_passengers * num_bags;  // calculate the total number of bags

    int employee_capacity = 10;  // maximum number of bags an employee can handle
    int num_employees = (total_bags / employee_capacity) + 1;  // calculate the number of employees needed
    if (num_employees < 1) {
        num_employees = 1;
    }

    int processing_time = 5;  // number of seconds it takes to process each bag
    int total_time = total_bags * processing_time;  // calculate the total time needed to process all bags

    printf("Number of bags: %d\n", total_bags);
    printf("Number of employees needed: %d\n", num_employees);
    printf("Total time needed: %d seconds\n", total_time);

    // simulate the time it takes to process all bags
    int t;
    for (t = 1; t <= total_time; t++) {
        if (t % processing_time == 0) {
            int num_processed = t / processing_time;
            printf("Processed %d out of %d bags\n", num_processed, total_bags);
        }
    }

    printf("All bags have been processed!\n");
}

// main function to test the baggage_handling function
int main() {

    srand(time(0));  // seed the random number generator

    int num_passengers = rand() % 100 + 1;  // generate a random number of passengers between 1 and 100
    int num_bags = rand() % 5 + 1;  // generate a random number of bags per passenger between 1 and 5

    printf("Number of passengers: %d\n", num_passengers);
    printf("Number of bags per passenger: %d\n", num_bags);

    baggage_handling(num_passengers, num_bags);

    return 0;
}