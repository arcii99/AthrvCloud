//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int total_cars = 0;
    int total_cars_generated = 0;
    int total_cars_passed = 0;
    int current_hour = 0;
    int current_minute = 0;
    int current_second = 0;

    srand(time(NULL));

    while(total_cars<1000){

        // Based on time of day, generate cars based on probability
        if(current_hour >= 5 && current_hour < 7){
            // Rush hour - higher probability of generating cars
            if(rand()%10 < 8){
                total_cars++;
                total_cars_generated++;
            }
        }
        else{
            // Non-rush hour - lower probability of generating cars
            if(rand()%10 < 2){
                total_cars++;
                total_cars_generated++;
            }
        }

        // Update time
        current_second++;
        if(current_second >= 60){
            current_second = 0;
            current_minute++;
        }
        if(current_minute >= 60){
            current_minute = 0;
            current_hour++;
        }

        // If a car reaches the end of the road, count it as passed
        // Remove it from the total number of cars on the road
        if(rand()%10 < 4){
            total_cars_passed++;
            total_cars--;
        }

    }

    printf("Total cars generated: %d\n", total_cars_generated);
    printf("Total cars passed: %d\n", total_cars_passed);
    printf("Total cars still on the road: %d\n", total_cars);

    return 0;

}