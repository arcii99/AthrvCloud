//FormAI DATASET v1.0 Category: Data validation ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main() {
  int age;
  char name[20];

  printf("Enter your name: ");
  scanf("%s", name);

  // Ensure name is not empty
  if (!strlen(name)) {
    printf("Invalid input. Name cannot be empty.\n");
    return 1;
  }

  printf("Enter your age: ");
  scanf("%d", &age);

  // Ensure age is between 18 and 120
  if (age < 18 || age > 120) {
    printf("Invalid input. Age must be between 18 and 120.\n");
    return 1;
  }

  printf("Name: %s\nAge: %d\n", name, age);

  return 0;
}