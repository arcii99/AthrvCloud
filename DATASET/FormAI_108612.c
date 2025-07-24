//FormAI DATASET v1.0 Category: Data validation ; Style: introspective
#include <stdio.h>
#include <string.h>

int main(void) {
  char name[20];
  int age;

  printf("Please enter your name: ");
  fgets(name, 20, stdin);
  name[strcspn(name, "\n")] = 0; // Remove newline character from input

  printf("Please enter your age: ");
  scanf("%d", &age);

  // Ensure age is valid (between 18 and 120)
  if (age < 18 || age > 120) {
    printf("Invalid age. Please enter an age between 18 and 120.\n");
    return 1; // Exit program with error status
  }

  printf("Hello, %s!\n", name);
  printf("You are %d years old.\n", age);

  return 0; // Exit program successfully
}