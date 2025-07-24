//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    char destination[50];
    int x, y;
    
    // Prompt the user to input the desired destination
    printf("My love, where would you like to go tonight?\n");
    scanf("%s", destination);
    
    // Simulate GPS navigation by prompting the user to input coordinates
    printf("Okay, let's see... Please enter your current x-coordinate and y-coordinate:\n");
    scanf("%d %d", &x, &y);
    
    printf("Great! We are calculating the directions to %s...\n", destination);
    printf("Turn right in 100 meters...\n");
    printf("Left turn ahead, 50 meters...\n");
    printf("You are so close, just a little bit more...\n");
    
    // Display a romantic message upon arrival at the destination
    if (strcmp(destination, "my heart") == 0) {
        printf("Congratulations! You have arrived at your destination. Welcome to my heart, my love. <3\n");
    } else {
        printf("Congratulations! You have arrived at your destination. I hope you enjoy your time there with me.\n");
    }
    
    return 0;
}