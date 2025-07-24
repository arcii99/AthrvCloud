//FormAI DATASET v1.0 Category: Syntax parsing ; Style: artistic
#include <stdio.h>

// Here we declare a struct to hold our artistic programming style
typedef struct ArtisticProgrammingStyle {
  char* purpose; // The purpose of this artistic style
  char* description; // A short description of this artistic style
  char* example; // A unique example of this artistic style in action
} APS;

int main() {
  // Here we create an instance of our ArtisticProgrammingStyle struct
  APS aps = {
    .purpose = "To generate code that is both functional and beautiful",
    .description = "We use C syntax to create a visual masterpiece",
    .example = "Behold! An if/else statement that is also a work of art. Enjoy!"
  };

  // Now we begin our artistic program
  printf("Welcome to our artistic programming style.\n");
  printf("Our purpose is: %s\n", aps.purpose);
  printf("Description of our style: %s\n", aps.description);
  printf("Now, to our unique example:\n");

  // Here is where our code snippet begins
  int n = 5;
  int k = 7;

  if (n < k) {
    printf("   /\\\n");
    printf("  /  \\\n");
    printf(" /    \\\n");
    printf("/------\\\n");
    printf("|      |\n");
    printf("|      |\n");
    printf("--------\n");
  } else {
    printf("     /\\\n");
    printf("    /  \\\n");
    printf("   /    \\\n");
    printf("  /      \\\n");
    printf(" /        \\\n");
    printf("/----------\\\n");
    printf("|          |\n");
    printf("|          |\n");
    printf("------------\n");
  }
  // And here is where it ends

  printf("%s\n", aps.example);
  printf("Thank you for experiencing our unique programming style.\n");
  printf("We hope you find inspiration and beauty in your coding endeavors.\n");

  return 0;
}