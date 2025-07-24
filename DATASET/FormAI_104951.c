//FormAI DATASET v1.0 Category: Educational ; Style: immersive
#include <stdio.h>

int main() {
  char name[20];
  int age, birthYear, currentYear, yearDiff;
  
  printf("Welcome to the age calculator!\n");
  printf("Please enter your name: ");
  scanf("%s", name);
  printf("Hi %s! What is your age?\n", name);
  scanf("%d", &age);
  printf("What is the current year?\n");
  scanf("%d", &currentYear);
  
  birthYear = currentYear - age;
  yearDiff = currentYear - birthYear;
  
  printf("So %s, you were born in %d.\n", name, birthYear);
  
  if (yearDiff == age) {
    printf("Did you know that this is also your birth year?\n");
  } else {
    printf("You're currently %d years old.\n", age);
  }
  
  printf("Thanks for using the age calculator, %s! Goodbye!\n", name);
  
  return 0;
}