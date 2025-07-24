//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

int main(){
    int speed = 0; //initial speed
    int direction = 0; //initial direction
    printf("Remote Control Car Simulation Program\n");

    //simulate user control input
    printf("Enter speed (0-10): ");
    scanf("%d", &speed);
    printf("Enter direction (0-360 degrees): ");
    scanf("%d", &direction);

    //simulate vehicle movement
    printf("Vehicle moving at %d km/h towards %d degrees direction.\n", speed*10, direction);
    
    //simulate obstacles
    int obstacles;
    printf("Enter number of obstacles on the track: ");
    scanf("%d", &obstacles);

    //simulate avoidance of obstacles
    int i;
    for(i = 1; i<=obstacles; i++){
        int obstacle_distance;
        printf("Enter distance of obstacle %d: ", i);
        scanf("%d", &obstacle_distance);

        if(obstacle_distance < speed*10){
            printf("Obstacle %d at %d meters, slowing down...\n", i, obstacle_distance);
            speed -=1;
        }else{
            printf("Obstacle %d at %d meters, keep moving...\n", i, obstacle_distance);
        }
    }
    
    //simulate arrival
    if(speed <= 0){
        printf("Vehicle stopped due to obstacles. Please clear obstacles before continue the trip.\n");
    }else{
        printf("Vehicle arrived at the destination at %d km/h towards %d degrees direction.\n", speed*10, direction);
    }

    return 0;
}