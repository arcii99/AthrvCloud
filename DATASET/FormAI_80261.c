//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SPEED 100
#define MIN_SPEED 0

// Function to calculate the new speed of the vehicle based on the input signal
int calculate_speed(int current_speed, int input_signal) {
    int new_speed = current_speed + input_signal;
    if(new_speed > MAX_SPEED) {
        new_speed = MAX_SPEED;
    } else if(new_speed < MIN_SPEED) {
        new_speed = MIN_SPEED;
    }
    return new_speed;
}

int main() {
    // Initialize current speed of the vehicle to 0
    int current_speed = 0;
    
    printf("Enter the input signal (from -100 to 100):\n");
    int input_signal;
    scanf("%d", &input_signal);
    
    // Calculate the new speed based on the input signal
    current_speed = calculate_speed(current_speed, input_signal);
    
    // Print the updated speed of the vehicle
    printf("Updated speed of the vehicle is: %d", current_speed);
    
    return 0;
}