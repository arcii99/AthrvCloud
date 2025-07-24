//FormAI DATASET v1.0 Category: Arithmetic ; Style: immersive
#include<stdio.h>

int main() {
    // Welcome to Alien Arithmetic!
    printf("Welcome to Alien Arithmetic!\n");
    
    // Declare variables
    int earthNum, alienNum;
    
    // Get input from user
    printf("Enter an Earth-based number: ");
    scanf("%d", &earthNum);
    
    // Convert Earth-based number to Alien-based number
    printf("Converting to Alien-based number...\n");
    alienNum = (earthNum * 10) + 42;
    
    // Perform arithmetic on Alien-based number
    printf("Performing arithmetic on Alien-based number...\n");
    alienNum += 17;
    alienNum *= 2;
    alienNum -= 8;
    
    // Convert Alien-based number back to Earth-based number
    printf("Converting back to Earth-based number...\n");
    earthNum = (alienNum - 42) / 10;
    
    // Output results
    printf("The original Earth-based number was: %d\n", earthNum);
    printf("The final Alien-based number is: %d\n", alienNum);
    printf("Thanks for visiting Alien Arithmetic! Come back soon.\n");
    
    return 0;
}