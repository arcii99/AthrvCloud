//FormAI DATASET v1.0 Category: Data validation ; Style: funny
#include <stdio.h>
#include <stdbool.h>

void main() {
  int age;

  printf("Hello there! How old are you?\n");
  scanf("%d", &age);

  if (age < 0 || age > 150) {
    printf("Haha, nice try! But that can't be your age.\n");
    printf("Please try again and enter your real age this time.\n");
    return;
  }

  if (age == 69) {
    printf("Hey, nice. \n");
    printf("But let's be serious now, is that really your age?\n");
    printf("If yes, please try again with an actual age. If no, congrats on the sense of humor!\n");
    return;
  }

  if (age % 2 == 0) {
    printf("Wow, you're even!\n");
  } else {
    printf("Looks like you're odd...\n");
  }

  bool hasPet;

  printf("Do you have a pet? (yes/no)\n");

  char response[3];
  scanf("%s", &response);

  if (strcmp(response, "yes") == 0) {
    hasPet = true;
  } else if (strcmp(response, "no") == 0) {
    hasPet = false;
  } else {
    printf("Sorry, I didn't get that. Please try again.\n");
    return;
  }

  printf("Thank you for answering those questions!\n");
  printf("You are %d years old and you %s have a pet.\n", age, hasPet ? "" : "don't");
}