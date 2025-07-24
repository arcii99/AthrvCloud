//FormAI DATASET v1.0 Category: Data validation ; Style: energetic
#include <stdio.h>
#include <ctype.h>

int main() {
  char name[20];
  int age;
  float height;

  printf("Welcome to the data validation program!\n");
  printf("Please enter your name: ");
  scanf("%s", &name);

  // Check if name only contains letters
  for (int i = 0; i < strlen(name); i++) {
    if (isdigit(name[i])) {
      printf("Error: Name must only contain letters!\n");
      return 1;
    }
  }

  printf("Please enter your age: ");
  scanf("%d", &age);

  // Check if age is between 0 and 120
  if (age < 0 || age > 120) {
    printf("Error: Invalid age! Age must be between 0 and 120.\n");
    return 1;
  }

  printf("Please enter your height in meters: ");
  scanf("%f", &height);

  // Check if height is positive
  if (height < 0) {
    printf("Error: Invalid height! Height must be positive.\n");
    return 1;
  }

  printf("\nThank you for entering your information!\n");
  printf("Name: %s\n", name);
  printf("Age: %d\n", age);
  printf("Height in meters: %.2f\n", height);

  return 0;
}