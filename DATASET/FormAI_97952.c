//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
const int MAX_BAGS = 50; // Maximum number of bags that can be handled by the system
const int MAX_TIME = 10; // Maximum time a customer can wait before they get restless
const int NUM_CUSTOMERS = 5; // Number of customers

// Struct to represent a customer
typedef struct Customer {
    int id;
    int num_bags;
    int arrival_time;
    int processing_time;
    int is_restless;
} Customer;

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Initialize array of customers
    Customer customers[NUM_CUSTOMERS];

    // Generate customer data
    for (int i = 0; i < NUM_CUSTOMERS; i++) {
        customers[i].id = i;
        customers[i].num_bags = random_number(1, MAX_BAGS);
        customers[i].arrival_time = random_number(0, MAX_TIME);
        customers[i].processing_time = random_number(customers[i].num_bags * 2, customers[i].num_bags * 4);
    }

    // Simulate baggage handling
    int total_time = 0;
    int num_customers_processed = 0;
    while (num_customers_processed < NUM_CUSTOMERS) {
        // Find the next customer in the queue
        int next_customer = -1;
        int earliest_arrival_time = MAX_TIME + 1;
        for (int i = 0; i < NUM_CUSTOMERS; i++) {
            if (customers[i].processing_time > 0 && customers[i].arrival_time < earliest_arrival_time) {
                next_customer = i;
                earliest_arrival_time = customers[i].arrival_time;
            }
        }

        // If no customers are left, exit the loop
        if (next_customer == -1) {
            break;
        }

        // Process the next customer
        total_time += customers[next_customer].processing_time;
        customers[next_customer].processing_time = 0;
        num_customers_processed++;

        // Check if the customer was restless
        if (total_time - customers[next_customer].arrival_time > MAX_TIME) {
            customers[next_customer].is_restless = 1;
        }

        // Print information about the customer and their bags
        printf("Customer %d had %d bags and took %d minutes to process.\n", customers[next_customer].id, customers[next_customer].num_bags, customers[next_customer].processing_time);
        if (customers[next_customer].is_restless) {
            printf("This customer was restless.\n");
        }
    }

    return 0;
}