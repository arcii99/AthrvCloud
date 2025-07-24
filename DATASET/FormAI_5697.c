//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: detailed
#include <stdio.h>   // for standard input/output
#include <stdlib.h>  // for srand and rand
#include <time.h>    // for time

int main() {
  // initialize random number generator
  srand(time(NULL));

  // declare and initialize array of fortunes
  char *fortunes[] = {"A thrilling time is in your immediate future.",
                      "Your future is looking bright.",
                      "Success will be yours.",
                      "You will find love in unexpected places.",
                      "You will have a long and happy life.",
                      "Good things come to those who wait.",
                      "You will be richly rewarded for your efforts."};
  // calculate number of fortunes
  int num_fortunes = sizeof(fortunes) / sizeof(char *);

  // prompt user for question
  printf("What is your question?\n");

  // read user input into buffer
  char buffer[1024];
  fgets(buffer, 1024, stdin);

  // generate random number to select fortune
  int fortune_index = rand() % num_fortunes;

  // output selected fortune
  printf("\n%s\n", fortunes[fortune_index]);

  return 0;  // exit program
}