//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROAD_LENGTH 30
#define CAR_INTERVAL 5
#define MAX_SPEED 5
#define SIMULATION_TIME 30

int random_speed(int max_speed){
    return rand() % (max_speed + 1);
}

int main(){

    srand(time(NULL));

    int road[ROAD_LENGTH];
    int time_elapsed, car_counter, speed, i, j;

    // initialize road and car counter
    for(i = 0; i < ROAD_LENGTH; i++){
        road[i] = -1;
    }
    car_counter = 0;

    // time loop
    for(time_elapsed = 0; time_elapsed <= SIMULATION_TIME; time_elapsed++){
        printf("Time Elapsed: %d\n", time_elapsed);

        // handling each interval
        if(time_elapsed % CAR_INTERVAL == 0){
            speed = random_speed(MAX_SPEED);
            printf("New car with speed %d\n", speed);

            // adding new car in the first cell
            road[0] = car_counter;
            car_counter++;
        }

        // moving cars forward
        for(j = ROAD_LENGTH - 1; j >= 0; j--){
            if(road[j] != -1){
                if(j + speed >= ROAD_LENGTH){
                    road[j] = -1;
                }else{
                    road[j + speed] = road[j];
                    road[j] = -1;
                }
            }
        }

        // displaying road state
        for(i = 0; i < ROAD_LENGTH; i++){
            if(road[i] == -1){
                printf("-");
            }else{
                printf("%d", road[i] % 10); // to handle double digit cars
            }
        }
        printf("\n\n");
    }

    return 0;
}