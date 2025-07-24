//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 1000 //maximum number of cars

int main(){
    int traffic[MAX_CARS]; //array to represent traffic flow
    int i, j, temp, total_cars, direction, count;
    float average_speed;

    /*Initial Setup*/
    srand(time(0)); //initialize random number generator
    total_cars = rand() % MAX_CARS + 1; //random number of total cars
    direction = rand() % 2; //random initial direction of traffic (0 for left to right, 1 for right to left)

    //randomly assign speeds to cars
    for(i=0; i<total_cars; i++){
        traffic[i] = rand() % 60 + 40; //random speed between 40 and 100 km/h
    }

    /*Simulation*/
    count = 0;
    while(count < 5){ //simulate traffic for 5 minutes
        printf("Minute %d\n", count+1);

        //display traffic flow
        if(direction == 0){
            printf("Left to Right:\n");
        } else {
            printf("Right to Left:\n");
        }
        for(i=0; i<total_cars; i++){
            printf("%d km/h\n", traffic[i]);
        }

        //calculate average speed
        average_speed = 0;
        for(i=0; i<total_cars; i++){
            average_speed += traffic[i];
        }
        average_speed /= total_cars;
        printf("Average speed: %.2f km/h\n", average_speed);

        //simulate movement of cars
        if(direction == 0){
            //sort cars by speed to simulate faster cars passing slower cars
            for(i=0; i<total_cars-1; i++){
                for(j=i+1; j<total_cars; j++){
                    if(traffic[i] > traffic[j]){
                        temp = traffic[i];
                        traffic[i] = traffic[j];
                        traffic[j] = temp;
                    }
                }
            }

            //allow cars to move
            for(i=0; i<total_cars-1; i++){
                if(traffic[i] < traffic[i+1]){
                    temp = traffic[i];
                    traffic[i] = traffic[i+1];
                    traffic[i+1] = temp;
                }
            }
        } else {
            //sort cars by speed to simulate faster cars passing slower cars
            for(i=total_cars-1; i>0; i--){
                for(j=0; j<i; j++){
                    if(traffic[j] > traffic[j+1]){
                        temp = traffic[j];
                        traffic[j] = traffic[j+1];
                        traffic[j+1] = temp;
                    }
                }
            }

            //allow cars to move
            for(i=total_cars-1; i>0; i--){
                if(traffic[i] < traffic[i-1]){
                    temp = traffic[i];
                    traffic[i] = traffic[i-1];
                    traffic[i-1] = temp;
                }
            }
        }

        //change direction of traffic randomly
        if(rand() % 5 == 0){
            direction = !direction;
        }

        //pause for 1 second to simulate real-time traffic flow
        sleep(1);
        count++;
    }

    printf("Simulation complete.\n");

    return 0;
}