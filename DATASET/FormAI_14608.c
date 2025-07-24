//FormAI DATASET v1.0 Category: Typing Speed Test ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (){
  printf("Welcome to the Typing Speed Test!\n");
  printf("Let's see how fast you can type in C!\n");
  printf("Type the following sentence as fast as you can, and press ENTER when you're done:\n\n");
  
  const char* sentence = "The quick brown fox jumps over the lazy dog.";
  printf("%s\n\n", sentence);
  
  // Start timer
  clock_t start = clock();
  
  // User input
  char typed[100];
  fgets(typed, 100, stdin);
  
  // End timer
  clock_t end = clock();
  double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
  
  // Check for accuracy and speed
  int errors = 0;
  
  for (int i = 0; sentence[i] != '\0'; i++){
    if (sentence[i] != typed[i])
      errors++;
  }
  
  int len = strlen(sentence);
  double accuracy = 1.0 - (double)errors/len;
  double speed = (double)len / 5 / time_spent; // assumes 5 characters per word
  
  // Print results
  printf("\n--- RESULTS ---\n");
  printf("Time: %.2lf seconds\n", time_spent);
  printf("Accuracy: %.2lf%%\n", accuracy * 100);
  printf("Speed: %.2lf words per minute\n", speed);
  
  return 0;
}