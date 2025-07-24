//FormAI DATASET v1.0 Category: Data validation ; Style: minimalist
#include <stdio.h>
#include <stdbool.h>

int main() {
  char name[20];
  int age;
  float height;

  printf("Enter your name: ");
  fgets(name, sizeof(name), stdin);

  printf("Enter your age: ");
  scanf("%d", &age);

  printf("Enter your height in meters: ");
  scanf("%f", &height);

  bool valid = true;

  if (age < 0 || age > 150) {
    printf("Invalid age entered\n");
    valid = false;
  }

  if (height < 0.0f || height > 3.0f) {
    printf("Invalid height entered\n");
    valid = false;
  }

  if (valid) {
    printf("\n\nValid Information Entered:\n");
    printf("Name: %s", name);
    printf("Age: %d years old\n", age);
    printf("Height: %.2f meters tall\n", height);
  }

  return 0;
}