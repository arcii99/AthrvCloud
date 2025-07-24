//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: careful
#include <stdio.h>

//struct to hold fitness data for a single day
typedef struct {
  int steps;
  double distance; //in kilometers
  int caloriesBurned;
} FitnessData;

//function to calculate distance based on number of steps taken
double calculateDistance(int steps) {
  return steps * 0.000762; //approximate stride length for an average person in kilometers
}

int main() {
  int numDays;
  
  printf("How many days of fitness data do you want to track? ");
  scanf("%d", &numDays);
  
  FitnessData data[numDays];
  
  //loop to input data for each day
  for(int i=0; i<numDays; i++) {
    printf("Enter fitness data for Day %d\n", i+1);
    printf("Number of steps: ");
    scanf("%d", &data[i].steps);
    data[i].distance = calculateDistance(data[i].steps);
    printf("Calories burned: ");
    scanf("%d", &data[i].caloriesBurned);
  }
  
  //loop to display data for each day
  printf("\nFitness Data\n");
  printf("Day\tSteps\tDistance (km)\tCalories Burned\n");
  for(int i=0; i<numDays; i++) {
    printf("%d\t%d\t%.2lf\t\t%d\n", i+1, data[i].steps, data[i].distance, data[i].caloriesBurned);
  }
  
  return 0;
}