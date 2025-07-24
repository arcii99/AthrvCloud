//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

  // Creating arrays of fortune messages
  char *fortunes[] = {
    "You will find success in all your endeavors!",
    "A life-changing opportunity is just around the corner!",
    "Your kindness will be rewarded in the near future!",
    "Love is in your near future!",
    "You will learn something new every day!",
    "Success and happiness are coming your way!",
    "Expect the unexpected today!",
    "You have a bright future ahead of you!",
    "Your dreams will come true this year!",
    "Good fortune will follow you wherever you go!"
  };

  int num_fortunes = 10; // Number of messages in fortunes array

  printf("Welcome to the Automated Fortune Teller!\n\n");
  printf("Enter your name: ");

  char name[100];
  scanf("%s", name);

  printf("\nHi %s! Let's see what the future has in store for you...\n", name);

  // Generating a random number between 0 and num_fortunes-1
  srand(time(NULL));
  int random_index = rand() % num_fortunes;

  // Printing the fortune message
  printf("\n%s\n", fortunes[random_index]);

  printf("Thanks for using the Automated Fortune Teller! Come back soon!\n");

  return 0;
}