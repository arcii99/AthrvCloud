//FormAI DATASET v1.0 Category: Smart home automation ; Style: beginner-friendly
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));
    
    // Get initial temperature from user input
    int current_temp;
    printf("Enter current temperature: ");
    scanf("%d", &current_temp);
    
    // Set target temperature randomly between 68-72 degrees
    int target_temp = (rand() % 5) + 68;
    printf("Target temperature set to %d degrees\n", target_temp);
    
    // Begin smart home automation loop
    while(1) {
        // Check if current temp is above or below target temp
        if(current_temp < target_temp) {
            printf("Temperature is below target. Turning on heat.\n");
            // Code to turn on heat would go here
        } else if(current_temp > target_temp) {
            printf("Temperature is above target. Turning on AC.\n");
            // Code to turn on AC would go here
        } else {
            printf("Temperature is at target.\n");
            // Code to turn off both heat and AC would go here
        }
        
        // Wait 5 minutes before checking temperature again
        sleep(300);
        // Update current temperature with new reading
        current_temp = (rand() % 9) + 62;
    }
    
    return 0;
}