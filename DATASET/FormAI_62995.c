//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Dennis Ritchie
#include <stdio.h> 
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// define variables
#define MAX_BAGGAGE 50
#define MAX_FLIGHTS 5
#define MAX_TERMINALS 3

typedef struct {
    int flight_num;
    int num_bags;
    int arrival_time;
    int departure_time;
} Flight;

typedef struct {
    int terminal_num;
    int num_queued_bags;
    int baggage_list[MAX_BAGGAGE];
} Terminal;

// initialize functions
void generate_flights(Flight flight_list[MAX_FLIGHTS]);
void queue_bags(Terminal terminal_list[MAX_TERMINALS], Flight flight_list[MAX_FLIGHTS]);

int main() {
    // initialize variables
    Flight flight_list[MAX_FLIGHTS];
    Terminal terminal_list[MAX_TERMINALS];

    // generate flights
    generate_flights(flight_list);

    // queue bags
    queue_bags(terminal_list, flight_list);

    return 0;
}

// function to generate random flights
void generate_flights(Flight flight_list[MAX_FLIGHTS]) {
    srand(time(NULL));  
    for(int i=0; i<MAX_FLIGHTS; i++) {
        flight_list[i].flight_num = i+100;
        flight_list[i].num_bags = (rand() % 20) + 1;
        flight_list[i].arrival_time = (rand() % 10) + 1;
        flight_list[i].departure_time = flight_list[i].arrival_time + (rand() % 6) + 1;
    }
}

// function to queue bags for each terminal and flight
void queue_bags(Terminal terminal_list[MAX_TERMINALS], Flight flight_list[MAX_FLIGHTS]) {
    // initialize variables
    int total_bags = 0;
    int flight_num, num_bags, arrival_time, departure_time;
    bool bags_queued = false;

    // loop through each terminal
    for(int t=0; t<MAX_TERMINALS; t++) {
        terminal_list[t].terminal_num = t+1;
        terminal_list[t].num_queued_bags = 0;

        // loop through each flight
        for(int f=0; f<MAX_FLIGHTS; f++) {
            flight_num = flight_list[f].flight_num;
            num_bags = flight_list[f].num_bags;
            arrival_time = flight_list[f].arrival_time;
            departure_time = flight_list[f].departure_time;

            // queue bags if flight is departing from this terminal
            if(departure_time == (t+1)) {
                bags_queued = true;
                for(int b=0; b<num_bags; b++) {
                    if(terminal_list[t].num_queued_bags < MAX_BAGGAGE) {
                        terminal_list[t].baggage_list[terminal_list[t].num_queued_bags] = flight_num;
                        terminal_list[t].num_queued_bags++;
                        total_bags++;
                    } else {
                        printf("Terminal %d baggage queue is full.\n", t+1);
                    }
                }
            }
        }

        // print terminal baggage queue
        if(bags_queued) {
            printf("Terminal %d baggage queue:\n", t+1);
            for(int i=0; i<terminal_list[t].num_queued_bags; i++) {
                printf("Flight %d, Bag %d\n", terminal_list[t].baggage_list[i], i+1);
            }
        } else {
            printf("Terminal %d has no departing flights at this time.\n", t+1);
        }

        // reset bags_queued variable
        bags_queued = false;
    }

    // print total number of bags
    printf("\nTotal number of bags queued: %d", total_bags);
}