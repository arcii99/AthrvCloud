//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: recursive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define L 1000
#define R 4000
#define N 500

int traffic_flow(int density, int pos, int time, int speed);

int main() {

    srand(time(0));
    int density, pos, time, speed;

    for (int i = 0; i < 10; i++) {
        density = rand()%50 + 1;
        pos = rand()%(R-L) + L;
        time = rand()%1000 + 1;
        speed = rand()%50 + 1;
        printf("Simulation #%d\n", i+1);
        printf("Initial density = %d\n", density);
        printf("Initial position = %d\n", pos);
        printf("Simulation time = %d\n", time);
        printf("Average speed = %d\n", speed);
        printf("Final density = %d\n\n", traffic_flow(density, pos, time, speed));
    }

    return 0;
}

int traffic_flow(int density, int pos, int time, int speed) {

    int final_density;
    int curr_speed = (N - density)/speed; // current speed of the cars in the lane
    int movement = curr_speed*time; // movement of cars in the given time
    int new_pos = pos + movement; // new position of the cars in the lane

    if (new_pos > R) {
        int overflow = new_pos - R; // if there is overflow from the right side of the road, cars move to the left road
        final_density = density;
        if (pos - overflow >= L) { // if there is space for cars to move to left road
            final_density += traffic_flow(((N-final_density)/2), (pos - overflow), time, speed);
            // recursive call to move cars to left road with new density = (N-current_density)/2
        }
        else { // if there is not enough space in left lane, cars are stuck
            final_density += N;
        }
    }
    else if (new_pos < L) { //similarly, if there is overflow from the left road
        int overflow = L - new_pos;
        final_density = density;
        if (pos + overflow <= R) {
            final_density += traffic_flow(((N-final_density)/2), (pos + overflow), time, speed);
            // recursive call to move cars to right road with new density = (N-current_density)/2
        }
        else {
            final_density += N;
        }
    }
    else { // if cars are within the bounds of the road
        final_density = density;
    }

    return final_density;
}