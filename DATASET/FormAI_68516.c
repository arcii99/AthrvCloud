//FormAI DATASET v1.0 Category: Firewall ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int age;
char gender;

bool isAllowed(int age, char gender) {
  // Firewall rules
  if (age < 18 && gender == 'M') {
    printf("Sorry dude, you can't pass through this firewall.\n");
    return false;
  }

  if (age < 21 && gender == 'F') {
    printf("Sorry lady, you're not old enough to pass through this firewall either.\n");
    return false;
  }

  // If all is good, pass through the firewall!
  printf("Welcome to the forbidden part of the internet!\n");
  return true;
}

int main() {
  printf("Welcome to the Firewall Checkpoint!\n");
  printf("Please enter your age: ");
  scanf("%d", &age);
  printf("Please enter your gender (M/F): ");
  scanf(" %c", &gender); // note the space before %c to avoid capturing the newline character
  
  // Check if the user is allowed to pass
  bool result = isAllowed(age, gender);
  
  if (result) {
    printf("Hey, you're pretty cool! Here's a bonus super-secret code that will let you access the top-secret files: 123456.\n");
  } else {
    printf("Sorry, but you don't get the super-secret code. Better luck next time!\n");
  }

  return 0;
}