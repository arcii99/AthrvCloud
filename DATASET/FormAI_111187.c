//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int num_luggage;
   printf("Enter the number of luggage pieces in the flight: ");
   scanf("%d", &num_luggage);
   
   int num_baggage = num_luggage * 2;
   printf("\nTotal number of baggage in the flight: %d", num_baggage);
   
   int conveyor_belt[num_baggage];
   int index = 0;
   
   for (int i = 1; i <= num_luggage; i++) {
      conveyor_belt[index] = i;
      conveyor_belt[index + 1] = i;
      index += 2;
   }
   
   printf("\nLuggage on the conveyor belt:\n");
   for (int i = 0; i < num_baggage; i++) {
      printf("%d ", conveyor_belt[i]);
   }
   
   printf("\n\nProcessing luggage...\n");
   for (int i = 0; i < num_baggage; i++) {
      printf("Processing baggage %d...\n", conveyor_belt[i]);
   }
   
   printf("\nAll baggage processed successfully!");
   return 0;
}