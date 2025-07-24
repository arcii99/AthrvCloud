//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: scalable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_CARS 10
#define MAX_SPEED 5

int main() {
    int cars[MAX_CARS] = {0}; //array to store cars on the road
    int speed[MAX_CARS] = {0}; //array to store speed of each car
    int time1 = 0; //variable to store current time
    int time2 = 0; //variable to store previous time
    int distance = 0; //variable to store distance between cars
    int i = 0; //counter variable for loops
    int j = 0; //counter variable for loops
    int k = 0; //counter variable for loops
    char road[101] = {'|'}; //array to store road
    srand(time(NULL)); //to generate random values
    
    printf("\n\t***TRAFFIC SIMULATION***");
    printf("\n\nRoad:");
    for(i = 1; i < 100; i++) {
        road[i] = '-';
    }
    printf("%s", road);
    
    //adding cars to the road
    for(i = 0; i < MAX_CARS; i++) {
        if(rand()%2 == 0) {
            cars[i] = 1;
            road[i+1] = 'C';
        }
    }
    
    //starting simulation
    while(1) {
        //calculating time difference
        time2 = time1;
        time1 = time(NULL);
        printf("\n\nTime: %d", time1);
        
        //moving cars
        for(i = 0; i < MAX_CARS; i++) {
            if(cars[i] == 1) {
                speed[i] = rand()%MAX_SPEED + 1;
                for(j = i+1; j < MAX_CARS; j++) {
                    if(cars[j] == 1) {
                        distance = j - i;
                        break;
                    }
                }
                if(distance > speed[i]) {
                    //moving car
                    cars[i+speed[i]] = 1;
                    cars[i] = 0;
                    road[i+speed[i]+1] = 'C';
                    road[i+1] = '-';
                }
            }
        }
        printf("\n%s", road);
        
        //checking for end of simulation
        for(k = 0; k < MAX_CARS; k++) {
            if(cars[k] == 1 && k+1 == MAX_CARS) {
                return 0;
            }
        }
    }
    return 0;
}