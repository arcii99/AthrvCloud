//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: random
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  int numDays = 0;
  
  printf("Enter the number of days you want to track your fitness: ");
  scanf("%d",&numDays);
  
  int calories[numDays];
  int steps[numDays];
  float distance[numDays];
  float aveDistance = 0.0;
  int totalCalories = 0;
  int totalSteps = 0;
  
  printf("\n----------------------------\n");
  
  for (int i = 0; i < numDays; ++i) {
    printf("\nEnter the calories burned on day %d: ",i+1);
    scanf("%d",&calories[i]);
    printf("Enter the number of steps taken on day %d: ",i+1);
    scanf("%d",&steps[i]);
    printf("Enter the distance covered on day %d (in km): ",i+1);
    scanf("%f",&distance[i]);
    
    totalCalories += calories[i];
    totalSteps += steps[i];
    aveDistance += distance[i];
    
    printf("\n----------------------------\n");
  }
  
  aveDistance /= numDays;
  
  printf("\nTotal calories burned over %d day(s): %d\n",numDays,totalCalories);
  printf("Total steps taken over %d day(s): %d\n",numDays,totalSteps);
  printf("Average distance covered per day: %.2f km\n",aveDistance);
  
  return 0;
}