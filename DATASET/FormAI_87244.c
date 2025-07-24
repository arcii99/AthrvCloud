//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CARR 5 // maximum number of carousels
#define MAX_PASSENGERS 300 // maximum number of passengers
#define MAX_DELAY 10 // maximum delay time in minutes

struct passenger
{
    int flight_no;
    int arrival_time;
    int baggage_count;
    int baggage_carousel;
    int wait_time;
};

int carousels[MAX_CARR]; // holds the capacity of each carousel
struct passenger passengers[MAX_PASSENGERS]; // holds passenger data
int carousel_queues[MAX_CARR][MAX_PASSENGERS]; // holds the queue of passengers waiting for each carousel
int delays[MAX_PASSENGERS]; // holds the delay time for each passenger

int main()
{
    srand(time(NULL)); // initialize random seed

    // initialize variables
    int num_carousels = rand() % MAX_CARR + 1; // number of carousels
    int num_passengers = rand() % MAX_PASSENGERS + 1; // number of passengers
    int baggage_arrival_time = rand() % 5 + 1; // time taken for baggage to arrive at the carousel
    int baggage_collect_time = rand() % 3 + 1; // time taken for passengers to collect their baggage
    int total_simulation_time = rand() % 120 + 1; // total duration of the simulation in minutes
    int avg_wait_time = 0; // average waiting time for passengers to receive baggage
    int on_time_pct = 0; // percentage of passengers who received baggage on time
    int run_count = 10; // number of runs to simulate
    int run; // current run number

    // loop through multiple runs of the simulation
    for (run = 1; run <= run_count; run++)
    {
        // initialize carousels and queues
        int i, j;
        for (i = 0; i < num_carousels; i++)
        {
            carousels[i] = rand() % 10 + 1; // initialize carousel capacity
            for (j = 0; j < num_passengers; j++)
                carousel_queues[i][j] = -1; // initialize carousel queue
        }

        // generate passenger data
        for (i = 0; i < num_passengers; i++)
        {
            passengers[i].flight_no = rand() % 100 + 1; // random flight number between 1 and 100
            passengers[i].arrival_time = rand() % total_simulation_time; // random arrival time during simulation
            passengers[i].baggage_count = rand() % 3 + 1; // random number of bags between 1 and 3
            passengers[i].baggage_carousel = -1; // initialize carousel location as unknown
            passengers[i].wait_time = 0; // initialize wait time
            delays[i] = rand() % MAX_DELAY; // random delay time
        }

        // simulate the events
        int current_time, c, p, q, carousel_space, collect_time;
        for (current_time = 0; current_time < total_simulation_time; current_time++)
        {
            // process any arrivals at the carousels
            for (p = 0; p < num_passengers; p++)
            {
                if (passengers[p].arrival_time == current_time)
                {
                    // assign the passenger to the appropriate carousel queue
                    for (c = 0; c < num_carousels; c++)
                    {
                        if (passengers[p].flight_no % num_carousels == c)
                        {
                            for (q = 0; q < num_passengers; q++)
                            {
                                if (carousel_queues[c][q] == -1)
                                {
                                    carousel_queues[c][q] = p;
                                    break;
                                }
                            }
                            break;
                        }
                    }
                }
            }

            // process any passengers collecting baggage
            for (c = 0; c < num_carousels; c++)
            {
                for (q = 0; q < num_passengers; q++)
                {
                    if (carousel_queues[c][q] != -1)
                    {
                        p = carousel_queues[c][q];

                        // check if the passenger can collect their baggage
                        if (passengers[p].baggage_carousel == c)
                        {
                            collect_time = baggage_collect_time + delays[p]; // calculate the actual collect time
                            passengers[p].wait_time += collect_time; // add wait time
                            carousel_queues[c][q] = -1; // remove passenger from queue
                        }
                    }
                }
            }

            // update carousel status and allocate space to waiting passengers
            for (c = 0; c < num_carousels; c++)
            {
                carousel_space = carousels[c];
                for (q = 0; q < num_passengers; q++)
                {
                    if (carousel_queues[c][q] != -1)
                    {
                        p = carousel_queues[c][q];

                        // allocate carousel space to waiting passengers
                        if (carousel_space >= passengers[p].baggage_count)
                        {
                            carousel_space -= passengers[p].baggage_count;
                            passengers[p].baggage_carousel = c;
                            passengers[p].wait_time += baggage_arrival_time + delays[p]; // add wait time
                        }
                    }
                }

                // update carousel availability based on departing flights
                if ((current_time + baggage_collect_time) % num_carousels == c)
                {
                    carousels[c] += carousel_space;
                    carousel_space = carousels[c];
                }
            }
        }

        // calculate averages for the current run
        int total_wait_time = 0, on_time_count = 0;
        for (p = 0; p < num_passengers; p++)
        {
            total_wait_time += passengers[p].wait_time;
            if (passengers[p].arrival_time + baggage_arrival_time + delays[p] == passengers[p].wait_time)
                on_time_count++;
        }

        // add results for the current run to the cumulative totals
        avg_wait_time += total_wait_time / num_passengers;
        on_time_pct += 100 * on_time_count / num_passengers;
    }

    // calculate final averages over all runs
    avg_wait_time /= run_count;
    on_time_pct /= run_count;

    // output results
    printf("Simulation complete.\n");
    printf("Number of carousels: %d\n", num_carousels);
    printf("Number of passengers: %d\n", num_passengers);
    printf("Baggage arrival time: %d minutes\n", baggage_arrival_time);
    printf("Baggage collect time: %d minutes\n", baggage_collect_time);
    printf("Simulation duration: %d minutes\n", total_simulation_time);
    printf("Average passenger wait time: %d minutes\n", avg_wait_time);
    printf("Percentage of passengers receiving baggage on time: %d%%\n", on_time_pct);

    return 0;
}