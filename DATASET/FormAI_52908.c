//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

#define MAX_SPEED 100 

// Function to generate a random number between 0 and 1
float rand_float(){
    return ((float)rand())/((float)RAND_MAX);
}

// Function to calculate the distance from the origin
float distance(int x, int y){
    return sqrt(x*x + y*y);
}

// Main function
int main(){
    int x = 0, y = 0;
    int dx, dy;
    int speed;
    srand(time(NULL)); // Seed the random number generator
    printf("Welcome to Remote Control Vehicle Simulation\n");
    while(1){
        printf("Current Position: (%d,%d)\n", x, y);
        printf("Enter the speed of the vehicle (1-%d):", MAX_SPEED);
        scanf("%d", &speed);
        if(speed < 1 || speed > MAX_SPEED){
            printf("Invalid speed. Please enter a speed between 1 and %d\n", MAX_SPEED);
            continue;
        }
        dx = (int)(2*rand_float() - 1)*speed;
        dy = (int)(2*rand_float() - 1)*speed;
        x += dx;
        y += dy;
        printf("New Position: (%d,%d)\n", x, y);
        if(distance(x,y) > 100){
            printf("Out of range. Returning to origin\n");
            x = 0;
            y = 0;
        }
    }
    return 0;
}