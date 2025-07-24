//FormAI DATASET v1.0 Category: Error handling ; Style: surprised
#include <stdio.h>

int main() {
  int age;

  printf("Enter your age: ");
  scanf("%d", &age);

  if(age < 0) {
    printf("Oh no! You entered a negative age! What are the odds?\n");
    printf("This is not allowed!\n");
    printf("Please try again and enter a positive age.\n");
    return 1;
  }

  if(age > 120) {
    printf("Wow, you must be a record holder! But I'm afraid that's beyond the scope of this program.\n");
    printf("Please enter a more reasonable age.\n");
    return 1;
  }

  printf("Congratulations! You entered a valid age: %d years old.\n", age);

  return 0;
}