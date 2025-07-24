//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: real-life
#include<stdio.h>
#define N 10
#define M 6

int main()
{
    int i,j,k,tag1,tag2;
    int weight[N],location[N],flight[N],pickup[M][N];
    int checkin[N],security[N],boarding[N],arrival[N];
    int time, count, progress;
    int total_weight=0, total_luggage=0, total_flights=0;
    int total_checkin_time=0, total_security_time=0, total_boarding_time=0, total_arrival_time=0;
    int max_checkin_time=0, max_security_time=0, max_boarding_time=0, max_arrival_time=0;
    float average_weight, average_luggage, average_flights, average_wait_time;

    /* Set up initial values for the simulation */

    for (i=0; i<N; i++) {
        weight[i] = 30;
        location[i] = 0;
        flight[i] = i+1;
        checkin[i] = security[i] = boarding[i] = arrival[i] = -1;
    }

    /* Start the simulation for each 5 minutes */

    for (time=0; time<=1440; time+=5) {
        printf("\n\nSimulating at time %d\n\n", time);

        /* Randomly assign flights to luggage */

        for (i=0; i<N; i++) {
            if (flight[i] != -1) continue;
            flight[i] = rand()%5 + 1;
            total_weight += weight[i];
            total_luggage += 1;
        }

        /* Assign luggage to check-in counters */

        count = 0;
        for (i=0; i<N; i++) {
            if (location[i] != 0) continue;
            if (checkin[count] == -1) {
                checkin[count] = i;
                count += 1;
                if (count >= M) break;
            }
        }

        /* Calculate check-in time and update the progress */

        for (i=0; i<M; i++) {
            if (checkin[i] == -1) continue;
            checkin[checkin[i]] = time;
            total_checkin_time += time;
            if (time - max_checkin_time > max_checkin_time) max_checkin_time = time;
            progress += 1;
        }

        /* Assign luggage to security check counters */

        count = 0;
        for (i=0; i<N; i++) {
            if (location[i] != 1) continue;
            if (security[count] == -1) {
                security[count] = i;
                count += 1;
                if (count >= M) break;
            }
        }

        /* Calculate security check time and update the progress */

        for (i=0; i<M; i++) {
            if (security[i] == -1) continue;
            security[security[i]] = time;
            total_security_time += time;
            if (time - max_security_time > max_security_time) max_security_time = time;
            progress += 1;
        }

        /* Assign luggage to boarding gates */

        count = 0;
        for (i=0; i<N; i++) {
            if (location[i] != 2) continue;
            if (boarding[count] == -1) {
                boarding[count] = i;
                count += 1;
                if (count >= M) break;
            }
        }

        /* Calculate boarding time and update the progress */

        for (i=0; i<M; i++) {
            if (boarding[i] == -1) continue;
            boarding[boarding[i]] = time;
            total_boarding_time += time;
            if (time - max_boarding_time > max_boarding_time) max_boarding_time = time;
            progress += 1;
        }

        /* Assign luggage to arrival area */

        count = 0;
        for (i=0; i<N; i++) {
            if (location[i] != 3) continue;
            if (arrival[count] == -1) {
                arrival[count] = i;
                count += 1;
                if (count >= M) break;
            }
        }

        /* Calculate arrival time and update the progress */

        for (i=0; i<M; i++) {
            if (arrival[i] == -1) continue;
            arrival[arrival[i]] = time;
            total_arrival_time += time;
            if (time - max_arrival_time > max_arrival_time) max_arrival_time = time;
            progress += 1;
        }

        /* Get the next event in the simulation */

        tag1 = tag2 = -1;
        for (i=0; i<N; i++) {
            if (flight[i] != -1 && checkin[i] > -1) {
                if (tag1 == -1 || checkin[i] < checkin[tag1]) tag1 = i;
            }
            if (location[i] == 0 && (checkin[i] == -1 || time-checkin[i] >= 20)) {
                tag2 = i;
                break;
            }
            if (location[i] == 1 && (security[i] == -1 || time-security[i] >= 15)) {
                tag2 = i;
                break;
            }
            if (location[i] == 2 && (boarding[i] == -1 || time-boarding[i] >= 10)) {
                tag2 = i;
                break;
            }
            if (location[i] == 3 && (arrival[i] == -1 || time-arrival[i] >= 5)) {
                tag2 = i;
                break;
            }
        }

        /* Move the luggage from location A to B */

        if (tag1 != -1 && tag2 != -1) {
            location[tag1] = 1;
            location[tag2] = 0;
            printf("Luggage #%d has been checked in and is now moving to the security check counter.\n", tag1+1);
            printf("Luggage #%d has passed the security check and is now moving to the boarding gate.\n", tag1+1);
            printf("Luggage #%d has boarded the flight and is now moving to the arrival area.\n", tag1+1);
            printf("Luggage #%d has arrived at the arrival area and is ready for pickup.\n", tag1+1);
        }

        /* Move the luggage from location B to C */

        if (tag2 != -1) {
            if (location[tag2] == 0) {
                location[tag2] = 1;
                printf("Luggage #%d has been moved to the security check counter.\n", tag2+1);
            } else if (location[tag2] == 1) {
                location[tag2] = 2;
                printf("Luggage #%d has passed the security check and is now moving to the boarding gate.\n", tag2+1);
            } else if (location[tag2] == 2) {
                location[tag2] = 3;
                printf("Luggage #%d has boarded the flight and is now moving to the arrival area.\n", tag2+1);
            } else if (location[tag2] == 3) {
                location[tag2] = 4;
                printf("Luggage #%d has been picked up from the arrival area.\n", tag2+1);
                pickup[pickup[tag2][0]+1][pickup[tag2][0]] = tag2;
                pickup[tag2][0] += 1;
            }
        }

        /* Let the customer pick up the luggage */

        if (time % 60 == 0) {
            for (i=1; i<=5; i++) {
                if (pickup[i][0] == 0) continue;
                count = pickup[i][0];
                for (j=1; j<=count; j++) {
                    tag2 = pickup[i][j];
                    for (k=0; k<N; k++) {
                        if (flight[k] != i || location[k] != 4) continue;
                        if (weight[k] > i*5 || weight[k] <= (i-1)*5) continue;
                        tag1 = k;
                        break;
                    }
                    printf("Customer has picked up luggage #%d.\n", tag2+1);
                    location[tag2] = -1;
                    weight[tag2] = 0;
                    flight[tag2] = -1;
                    pickup[i][j] = -1;
                }
                pickup[i][0] = 0;
            }
        }

        /* Display the simulation output */

        printf("\nSimulation report at time %d:\n\n", time);
        printf("Total weight of luggage = %d\n", total_weight);
        printf("Total number of luggage = %d\n", total_luggage);
        printf("Total number of flights = %d\n", total_flights);
        printf("Average weight of luggage = %.2f\n", total_weight/total_luggage);
        printf("Average number of luggage per flight = %.2f\n", total_luggage/total_flights);
        printf("Average check-in time per luggage = %.2f\n", total_checkin_time*1.0/total_luggage);
        printf("Average security check time per luggage = %.2f\n", total_security_time*1.0/total_luggage);
        printf("Average boarding time per luggage = %.2f\n", total_boarding_time*1.0/total_luggage);
        printf("Average arrival time per luggage = %.2f\n", total_arrival_time*1.0/total_luggage);
        printf("Maximum wait time at check-in counter = %d\n", max_checkin_time);
        printf("Maximum wait time at security check counter = %d\n", max_security_time);
        printf("Maximum wait time at boarding gate = %d\n", max_boarding_time);
        printf("Maximum wait time at arrival area = %d\n", max_arrival_time);
        printf("Average wait time per luggage = %.2f\n", (total_checkin_time+total_security_time+total_boarding_time+total_arrival_time)*1.0/total_luggage);
        printf("Total number of events in simulation = %d\n", progress);
    }

    return 0;
}