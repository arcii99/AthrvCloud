//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_BAGGAGE 1000

// Function to generate random numbers between the specified range
int generateRandomNum(int low, int high) {
    int num = (rand() % (high - low + 1)) + low;
    return num;
}

// Main function to simulate the baggage handling process at an airport
int main() {
    int num_bags = generateRandomNum(500, MAX_BAGGAGE);// Randomly generate number of bags
    
    // Display the total number of bags
    printf("Total number of bags: %d\n\n", num_bags);
    
    // Initializing variables for different baggage colors
    int red_bags = 0;
    int blue_bags = 0;
    int green_bags = 0;
    
    // Initializing variables for different baggage sizes
    int small_bags = 0;
    int medium_bags = 0;
    int large_bags = 0;
    
    // Loop through all the bags
    for (int i = 0; i < num_bags; i++) {
        int color = generateRandomNum(1, 3);// Randomly generate bag color
        int size = generateRandomNum(1, 3);// Randomly generate bag size
        
        // Check the color of the bag
        if (color == 1) {
            printf("Bag %d is Red. ", i+1);// Print bag details
            red_bags++;// Increment number of red colored bags
            
            // Check the size of the bag
            if (size == 1) {
                printf("It is a Small Bag.\n");
                small_bags++;// Increment number of small bags
            }
            else if (size == 2) {
                printf("It is a Medium Bag.\n");
                medium_bags++;// Increment number of medium bags
            }
            else {
                printf("It is a Large Bag.\n");
                large_bags++;// Increment number of large bags
            }
        }
        else if (color == 2) {
            printf("Bag %d is Blue. ", i+1);// Print bag details
            blue_bags++;// Increment number of blue colored bags
            
            // Check the size of the bag
            if (size == 1) {
                printf("It is a Small Bag.\n");
                small_bags++;// Increment number of small bags
            }
            else if (size == 2) {
                printf("It is a Medium Bag.\n");
                medium_bags++;// Increment number of medium bags
            }
            else {
                printf("It is a Large Bag.\n");
                large_bags++;// Increment number of large bags
            }
        }
        else {
            printf("Bag %d is Green. ", i+1);// Print bag details
            green_bags++;// Increment number of green colored bags
            
            // Check the size of the bag
            if (size == 1) {
                printf("It is a Small Bag.\n");
                small_bags++;// Increment number of small bags
            }
            else if (size == 2) {
                printf("It is a Medium Bag.\n");
                medium_bags++;// Increment number of medium bags
            }
            else {
                printf("It is a Large Bag.\n");
                large_bags++;// Increment number of large bags
            }
        }
    }
    
    // Display the number of bags of each color and size
    printf("\nBaggage Summary:\n");
    printf("---------------------------------------------------------\n");
    printf("Color\t\tSmall Bags\tMedium Bags\tLarge Bags\n");
    printf("---------------------------------------------------------\n");
    printf("Red\t\t%d\t\t%d\t\t%d\n", ((small_bags/red_bags)*100), ((medium_bags/red_bags)*100), ((large_bags/red_bags)*100));
    printf("Blue\t\t%d\t\t%d\t\t%d\n", ((small_bags/blue_bags)*100), ((medium_bags/blue_bags)*100), ((large_bags/blue_bags)*100));
    printf("Green\t\t%d\t\t%d\t\t%d\n", ((small_bags/green_bags)*100), ((medium_bags/green_bags)*100), ((large_bags/green_bags)*100));
    printf("---------------------------------------------------------\n");
    
    return 0;
}