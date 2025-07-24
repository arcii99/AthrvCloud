//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: accurate
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// structure to represent the traffic signal
struct signal{
    int red; // time duration of red light
    int green; // time duration of green light
    int yellow; // time duration of yellow light
};

typedef struct signal Signal;

void simulate_traffic_flow(Signal s, int num_of_cars, int avg_time_bw_cars, int simulation_time){
    int time_elapsed = 0; // variable to track time elapsed
    int cars_passed = 0; // variable to track number of cars passed
    int curr_time = 0; // variable to track current time on traffic signal

    while(time_elapsed < simulation_time){
        if(curr_time < s.red){ // red light
            printf("Red Light | Passed Cars: %d | Time Elapsed: %d\n", cars_passed, time_elapsed);
            curr_time += s.red;
        }
        else if(curr_time < s.red + s.green){ // green light
            printf("Green Light | Passed Cars: %d | Time Elapsed: %d\n", cars_passed, time_elapsed);
            int num_of_new_cars = (rand() % 4) + 1; // generate number of new cars
            for(int i=0; i<num_of_new_cars; i++){
                cars_passed++;
                printf("Car %d passed | Time Elapsed %d\n", cars_passed, time_elapsed);
            }
            curr_time += s.green;
        }
        else{ // yellow light
            printf("Yellow Light | Passed Cars: %d | Time Elapsed: %d\n", cars_passed, time_elapsed);
            curr_time += s.yellow;
        }
        time_elapsed += curr_time;
        printf("-----------------------------------------\n");
    }
}

int main(){
    srand(time(0)); // seed the random number generator with current time
    Signal s;
    s.red = 20;
    s.green = 15;
    s.yellow = 5;
    simulate_traffic_flow(s, 50, 10, 300);
    return 0;
}