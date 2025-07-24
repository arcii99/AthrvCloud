//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_BAGGAGE 1000
#define MAX_FLIGHTS 100
#define MAX_CUSTOMERS 500

struct baggage {
    int customer_id;
    int weight;
};

struct flight {
    int flight_no;
    int total_weight;
    int max_weight;
    int customer_count;
};

struct customer {
    int id;
    int baggage_count;
    struct baggage baggages[MAX_BAGGAGE];
};

struct airport {
    int flight_count;
    struct flight flights[MAX_FLIGHTS];
    int customer_count;
    struct customer customers[MAX_CUSTOMERS];
};

int main()
{
    struct airport airport;
    airport.flight_count = 0;
    airport.customer_count = 0;

    srand(time(NULL));

    for(int i=0; i<MAX_FLIGHTS; i++) {
        int flight_no = i+1;
        int max_weight = (rand() % 20 + 1) * 100;
        int customer_count = rand() % 25 + 1;

        struct flight flight = {flight_no, 0, max_weight, customer_count};

        for(int j=0; j<customer_count; j++) {
            int id = airport.customer_count + 1;
            int baggage_count = rand() % 5 + 1;
            int total_weight = 0;

            struct customer customer = {id, baggage_count};

            for(int k=0; k<baggage_count; k++) {
                int weight = rand() % 30 + 1;
                struct baggage baggage = {id, weight};
                customer.baggages[k] = baggage;
                total_weight += weight;
            }

            if(total_weight > max_weight) {
                printf("Total weight of baggage exceeds maximum weight for flight %d, skipping customer %d.\n", flight_no, id);
                continue;
            }

            flight.total_weight += total_weight;
            airport.customers[airport.customer_count++] = customer;
        }

        airport.flights[airport.flight_count++] = flight;
    }

    printf("Flight\tMax Weight\tTotal Weight\tCustomers\n");

    for(int i=0; i<airport.flight_count; i++) {
        struct flight flight = airport.flights[i];

        printf("%d\t%d\t\t%d\t\t%d\n", flight.flight_no, flight.max_weight, flight.total_weight, flight.customer_count);
    }

    return 0;
}