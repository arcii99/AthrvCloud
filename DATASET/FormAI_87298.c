//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

int main() {
  int day, choice;
  float weight, calories_burned, distance, total_distance = 0, total_calories = 0, total_weight = 0;
  printf("Enter number of days: ");
  scanf("%d", &day);
  
  for(int i=1; i<=day; i++){
    
    printf("==== Day %d ====\n", i);
    printf("Enter your weight: ");
    scanf("%f", &weight);
    printf("Enter distance travelled: ");
    scanf("%f", &distance);
    printf("Enter calories burned: ");
    scanf("%f", &calories_burned);
    
    // Calculate the averages of all inputs
    total_weight += weight;
    total_distance += distance;
    total_calories += calories_burned;
    float avg_weight = total_weight / day;
    float avg_distance = total_distance / day;
    float avg_calories = total_calories / day;
    
    printf("Average Weight: %.2f\n", avg_weight);
    printf("Average Distance: %.2f\n", avg_distance);
    printf("Average Calories Burned: %.2f\n", avg_calories);

    printf("Do you want to continue? (Yes-1/No-2): ");
    scanf("%d", &choice);
    if(choice == 2) {
        break;
    }
  }
  return 0;
}