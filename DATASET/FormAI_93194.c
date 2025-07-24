//FormAI DATASET v1.0 Category: Traffic Flow Simulation ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROAD_LENGTH 100
#define MAX_SPEED 10
#define MAX_TRAFFIC_DENSITY 100

int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    int road_length, speed, density, i, car_position, num_cars, time_step, j;
    int traffic_jam = 0;
    
    srand(time(NULL));
    
    printf("Enter the length of the road: ");
    scanf("%d", &road_length);
    
    printf("Enter the speed limit: ");
    scanf("%d", &speed);
    
    printf("Enter the traffic density: ");
    scanf("%d", &density);
    
    if (road_length > MAX_ROAD_LENGTH || speed > MAX_SPEED || density > MAX_TRAFFIC_DENSITY) {
        printf("Error: Invalid road length, speed limit or traffic density\n");
        
        return 1;
    }
    
    num_cars = (int)((road_length * density) / 100.0);
    
    int road[road_length];
    
    for (i = 0; i < road_length; i++) {
        road[i] = 0;
    }
    
    for (i = 0; i < num_cars; i++) {
        car_position = random_number(0, road_length - 1);
        
        if (road[car_position] == 0) {
            road[car_position] = 1;
        }
        else {
            i--;
        }
    }
    
    printf("\n");
    
    for (time_step = 0; time_step < 10; time_step++) {
        printf("Time Step: %d\n", time_step);
        
        for (i = 0; i < road_length; i++) {
            if (road[i] == 0) {
                printf(".");
            }
            else {
                printf("X");
            }
        }
        
        printf("\n");
        
        for (i = 0; i < road_length; i++) {
            if (road[i] == 1) {
                j = i + 1;
                
                while (road[j] == 0 && j < road_length) {
                    j++;
                }
                
                if (j == road_length) {
                    road[i] = 0;
                }
                else if (j - i > speed) {
                    road[i] = 0;
                    road[i + speed] = 1;
                }
                else {
                    road[j - 1] = 1;
                    road[i] = 0;
                }
            }
        }
        
        printf("\n");
        
        for (i = 0; i < road_length; i++) {
            if (road[i] == 1 && road[i + 1] == 1) {
                traffic_jam++;
            }
        }
        
        if (traffic_jam > 0) {
            printf("Traffic jam ahead! Reduce speed.\n");
        }
        
        traffic_jam = 0;
    }
    
    return 0;
}