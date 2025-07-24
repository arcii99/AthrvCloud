//FormAI DATASET v1.0 Category: Data mining ; Style: funny
#include <stdio.h>
#include <stdlib.h>

// Our funny data mining program
int main(void) {
  printf("Welcome to our hilarious data mining program!\n");

  // Let's collect some data
  float data[10];
  printf("Please enter 10 numbers separated by spaces: ");
  for(int i = 0; i < 10; i++) {
    scanf("%f", &data[i]);
  }

  // Time to dig up some data dirt
  printf("Analyzing data now...\n");
  float total = 0;
  int negative_count = 0;
  for(int i = 0; i < 10; i++) {
    if(data[i] < 0) {
      negative_count++; // Count the negative numbers
    }
    total += data[i]; // Add all the numbers together
  }

  // And now for the grand reveal...
  printf("\n*** DATA MINING RESULTS ***\n");
  printf("Total sum of all data: %.2f\n", total);
  printf("Average of all data: %.2f\n", total/10);
  printf("Number of negative values: %d\n", negative_count);

  // Let's have some fun with the data
  printf("\n*** MAKE SOME WILD PREDICTIONS ***\n");
  int random_index = rand() % 10; // Pick a random index from the data array
  if(data[random_index] < -5) {
    printf("It looks like %f is going to cause a zombie apocalypse!\n", data[random_index]);
  } else if(data[random_index] > 50) {
    printf("Congratulations! %f is going to make you a millionaire!\n", data[random_index]);
  } else {
    printf("We have no idea what to expect from %f. Sorry!\n", data[random_index]);
  }

  printf("\nThanks for using our funny data mining program!\n");
  return 0;
}