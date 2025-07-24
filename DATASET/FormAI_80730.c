//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include <stdio.h>
#include <stdlib.h>

struct fitness_tracker {
    float weight;
    float height;
    int age;
    char gender;
    int steps;
    float calories;
};

int main(void) {
    // declare a fitness tracker struct variable
    struct fitness_tracker user;

    // prompt user for input
    printf("Enter your weight (in kilograms): ");
    scanf("%f", &user.weight);
    
    printf("Enter your height (in meters): ");
    scanf("%f", &user.height);
    
    printf("Enter your age: ");
    scanf("%d", &user.age);
    
    printf("Enter your gender (M or F): ");
    scanf(" %c", &user.gender);

    printf("Enter the number of steps you've taken today: ");
    scanf("%d", &user.steps);

    // calculate calories burned using a formula based on METs (metabolic equivalents) and user input data
    float METs; 
    if (user.gender == 'M') {
        METs = 0.0175;
    } else if (user.gender == 'F') {
        METs = 0.017;
    } else {
        printf("Invalid gender input!");
    }

    float calories = METs * user.weight * user.steps;

    printf("You have burned %f calories today!\n", calories);

    return 0;
}