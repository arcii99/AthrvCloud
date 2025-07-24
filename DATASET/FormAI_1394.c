//FormAI DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
  // Initializing variables
  int signal_strength = 0;
  int previous_strength = 0;
  float avg_strength = 0.0;
  int count = 0;
  char input[10];
  
  srand(time(NULL)); // Setting the seed for random number generation
  
  printf("Welcome to Wi-Fi Signal Strength Analyzer!\n\n");
  
  // Loop to continuously simulate the signal strength
  while(1) {
    
    // Generating a random number between 1 to 100 to simulate signal strength
    signal_strength = rand() % 100 + 1;
    
    // Checking if the signal strength has changed from the previous reading
    if(signal_strength != previous_strength) {
      printf("Signal strength: %d\n", signal_strength);
      
      // Calculating the average signal strength
      avg_strength = ((avg_strength * count) + signal_strength) / ++count;
      printf("Average signal strength: %.2f\n", avg_strength);
      
      // Updating previous strength to current strength
      previous_strength = signal_strength;
      
      // Checking if the signal strength is weak
      if (signal_strength <= 30) {
        printf("The signal strength is very weak!\n\n");
      }
      else {
        printf("\n");
      }
    }
    
    // Prompting the user for input
    printf("Enter 'exit' to quit or press any other key to continue: ");
    fgets(input, 10, stdin);
    strtok(input, "\n"); // Removing the newline character from the input
    
    // Checking if user wants to exit
    if (strcmp(input, "exit") == 0) {
      printf("\nExiting Wi-Fi Signal Strength Analyzer...\n");
      break;
    }
    
    // Adding a delay to simulate real-time data
    printf("\n");
    for (int i = 0; i < 100000000; i++);
  }
  
  return 0;
}