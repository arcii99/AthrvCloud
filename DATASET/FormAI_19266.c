//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: introspective
#include <stdio.h>

int main() {
   int denominations[] = {50,20,10,5,1}; // Array of available denominations
   int num_of_notes[sizeof(denominations)/sizeof(denominations[0])]; // Array to hold the number of notes of each denomination
   int amount, total_notes = 0; // Variables to hold the input amount and total number of notes needed
   int i; // Counter variable

   printf("Enter amount in rupees: ");
   scanf("%d", &amount); // User input for amount in rupees
   
   for (i=0; i<sizeof(denominations)/sizeof(denominations[0]); i++) { // Loop through all available denominations
      num_of_notes[i] = amount / denominations[i]; // Calculate number of notes of each denomination
      amount = amount % denominations[i]; // Calculate remaining amount after taking out maximum notes of current denomination
      total_notes += num_of_notes[i]; // Add number of notes of current denomination to total number of notes required
   }

   printf("Minimum number of notes required: %d\n", total_notes); // Output result

   printf("Denominations and number of notes:\n");
   for (i=0; i<sizeof(denominations)/sizeof(denominations[0]); i++) { // Loop through all available denominations
      printf("%d: %d\n", denominations[i], num_of_notes[i]); // Output denomination and number of notes of that denomination
   }

   return 0;
}