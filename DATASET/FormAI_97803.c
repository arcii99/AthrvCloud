//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: optimized
#include <stdio.h>

int main(void)
{
  int steps_count = 0;
  int calories_burned = 0;
  int heart_rate = 0;

  while(1) // endless loop (until user exits)
  {
    printf("Please enter the number of steps you have taken today: ");
    scanf("%d", &steps_count);

    calories_burned = steps_count * 0.05; // calculate calories burned based on number of steps
    printf("You have burned %d calories today.\n", calories_burned);

    printf("Please enter your current heart rate: ");
    scanf("%d", &heart_rate);

    if(heart_rate < 60)
    {
      printf("Your heart rate is below the recommended range.\n");
    }
    else if(heart_rate < 100)
    {
      printf("Your heart rate is within the recommended range.\n");
    }
    else
    {
      printf("Your heart rate is above the recommended range.\n");
    }
  }

  return 0;
}