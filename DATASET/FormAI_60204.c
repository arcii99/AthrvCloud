//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Alan Touring
#include <stdio.h>

// define the structure for fitness tracker data
struct FitnessTracker {
   int steps;
   float calories;
   float distance;
};

int main() {
    
    // create a new instance of FitnessTracker
    struct FitnessTracker myFitnessTracker;
    myFitnessTracker.steps = 0;
    myFitnessTracker.calories = 0;
    myFitnessTracker.distance = 0;
    
    // prompt the user for input
    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter the number of steps taken today: ");
    scanf("%d", &myFitnessTracker.steps);

    // calculate calories burned
    myFitnessTracker.calories = myFitnessTracker.steps * 0.05;

    // calculate distance travelled
    myFitnessTracker.distance = myFitnessTracker.steps * 0.000762;

    // output the results
    printf("You took %d steps today.\n", myFitnessTracker.steps);
    printf("You burned %.2f calories today.\n", myFitnessTracker.calories);
    printf("You travelled %.2f miles today.\n", myFitnessTracker.distance);

    return 0;
}