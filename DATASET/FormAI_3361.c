//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
   int aliens_detected, time_passed, invasion_probability;
   
   srand(time(0)); //seeding the rand() function with current time
   
   printf("------------------------------------------------------------------\n");
   printf("Alien Invasion Probability Calculator\n");
   printf("------------------------------------------------------------------\n");
   
   printf("Enter the number of aliens detected: ");
   scanf("%d", &aliens_detected);
   
   printf("Enter the time passed since detection (in hours): ");
   scanf("%d", &time_passed);
   
   invasion_probability = ((aliens_detected * 100) / (time_passed * 10)) + rand()%15;
   //calculating the invasion probability with a random factor from 0 to 14
   
   printf("------------------------------------------------------------------\n");
   printf("The probability of an alien invasion is: %d percent.", invasion_probability);
   printf("\n");
   
   if(invasion_probability < 50){
      printf("This indicates a low risk of alien invasion. However, caution is advised.\n");
   }
   
   else if(invasion_probability >= 50 && invasion_probability < 75){
      printf("This indicates a moderate risk of alien invasion. Preparedness measures should be taken immediately.\n");
   }
   
   else{
      printf("This indicates a high risk of alien invasion. Evacuation of the area is advised.\n");
   }
   
   printf("------------------------------------------------------------------\n");
   
   return 0;
}