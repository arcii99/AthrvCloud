//FormAI DATASET v1.0 Category: Data validation ; Style: lively
#include <stdio.h>
#include <ctype.h>

int main() {
  char name[20];
  int age;
  float height;

  printf("Welcome to the data validation program!\n");

  // Name Validation
  printf("Enter your name (up to 20 characters): ");
  fgets(name, 20, stdin);
  // Remove newline character from the name
  for(int i = 0; name[i] != '\0'; i++) {
    if(name[i] == '\n') {
      name[i] = '\0';
      break;
    }
  }
  // Check if name contains only letters or spaces
  for(int i = 0; name[i] != '\0'; i++) {
    if(!isalpha(name[i]) && name[i] != ' ') {
      printf("Invalid name! Please enter a name with only letters and spaces.\n");
      return 0;
    }
  }

  // Age Validation
  printf("Enter your age: ");
  if(scanf("%d", &age) == 0 || age <= 0 || age > 120) {
    printf("Invalid age! Please enter a valid age between 1 and 120.\n");
    return 0;
  }

  // Height Validation
  printf("Enter your height in meters: ");
  if(scanf("%f", &height) == 0 || height <= 0) {
    printf("Invalid height! Please enter a valid height greater than 0 meters.\n");
    return 0;
  }

  // Print Valid Data
  printf("\nThank you for providing valid data!\n\n");
  printf("Name: %s\nAge: %d\nHeight: %.2f meters\n", name, age, height);

  return 0;
}