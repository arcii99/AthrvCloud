//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define TOTAL_SECONDS 3600       // total number of seconds for simulation
#define TOTAL_LANES 4            // total number of lanes for simulation
#define MAX_SPEED 60             // max speed limit in mph

void initialize_flow(int flow[][TOTAL_SECONDS]) {
    int i, j;

    for(i=0; i<TOTAL_LANES; i++) {
        for(j=0; j<TOTAL_SECONDS; j++) {
            flow[i][j] = 0;
        }
    }
}

void print_flow(int flow[][TOTAL_SECONDS]) {
    int i, j;

    for(i=0; i<TOTAL_LANES; i++) {
        printf("Lane %d: ", i+1);
        for(j=0; j<TOTAL_SECONDS; j++) {
            printf("%d ", flow[i][j]);
        }
        printf("\n");
    }
}

void simulate_traffic(int flow[][TOTAL_SECONDS]) {
    int i, j, car_density, car_speed;

    srand(time(0));   // seed the random number generator

    // set initial car density
    for(i=0; i<TOTAL_LANES; i++) {
        car_density = rand() % 51 + 50; // car density between 50 and 100 cars per mile
        for(j=0; j<car_density; j++) {
            flow[i][j] = 1;  // set car at position
        }
    }

    // simulating each second in the hour
    for(i=1; i<TOTAL_SECONDS; i++) {
        for(j=0; j<TOTAL_LANES; j++) {
            if(flow[j][i-1] == 0) {  // check if position is empty
                if(rand()%100 < 10) { // 10% chance of new car entering
                    flow[j][i] = 1;
                }
            }
            else {  // if position is occupied by car
                car_speed = rand() % (MAX_SPEED+1); // assign random speed to car
                if(car_speed <= 30) {  // 50% chance speed is less than 30mph
                    if(j == 0) {  // if car is in leftmost lane
                        flow[j][i] = 0;  // car does not move
                    }
                    else if(flow[j-1][i-1] == 0) { // if lane to left is empty
                        flow[j-1][i] = 1;  // move car to left lane
                        flow[j][i] = 0;
                    }
                    else {
                        flow[j][i] = 1;  // car does not move
                    }
                }
                else if(car_speed > 30 && car_speed <= 50) { // 30% chance speed is between 30 and 50mph
                    if(flow[j][i-1] == 0) { // if position ahead is empty
                        flow[j][i] = 1; // car moves forward
                    }
                    else {
                        flow[j][i] = 0; // car does not move
                    }
                }
                else { // 20% chance speed is greater than 50mph
                    if(j == TOTAL_LANES-1) { // if car is in rightmost lane
                        flow[j][i] = 0; // car does not move
                    }
                    else if(flow[j+1][i-1] == 0) { // if lane to right is empty
                        flow[j+1][i] = 1; // move car to right lane
                        flow[j][i] = 0;
                    }
                    else {
                        flow[j][i] = 1; // car does not move
                    }
                }
            }
        }
    }
}

int main(void) {
    int flow[TOTAL_LANES][TOTAL_SECONDS];

    initialize_flow(flow);
    simulate_traffic(flow);
    print_flow(flow);

    return 0;
}