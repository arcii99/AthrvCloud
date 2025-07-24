//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
   // Alien Invasion Probability Calculator
   
   printf("========================================\n");
   printf("      Alien Invasion Probability Calculator\n");
   printf("========================================\n");
   printf("\n");
   
   // Getting location data
   char location[100];
   printf("Enter your location (City, Country): ");
   scanf("%[^\n]%*c", location);
   
   // Getting current year
   time_t t = time(NULL);
   struct tm tm = *localtime(&t);
   int current_year = tm.tm_year + 1900;
   
   // Generating random number for probability
   srand(time(0));
   int probability = rand() % 101;
   
   // Displaying results
   printf("\n");
   printf("Calculating...\n");
   printf("\n");
   
   printf("Location: %s\n", location);
   printf("Current Year: %d\n", current_year);
   printf("\n");
   
   printf("Probability of Alien Invasion: %d%%\n", probability);
   printf("\n");
   
   if(probability >= 50) {
      printf("You might want to start preparing for an Alien Invasion!\n");
   } else {
      printf("Looks like you're safe from an Alien Invasion... for now.\n");
   }
   
   return 0;
}