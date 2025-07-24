//FormAI DATASET v1.0 Category: Smart home light control ; Style: lively
#include <stdio.h>

int main() {
  int lightIntensity = 0;
  char choice;

  printf("Welcome to your Smart Home Light Control!\n");

  while (1) {
    printf("Current Light Intensity: %d%%\n", lightIntensity);
    printf("What do you want to do? (I)ncrease (D)ecrease (O)ff: ");
    scanf(" %c", &choice);

    if (choice == 'I') {
      if (lightIntensity < 100) {
        lightIntensity += 10;
        printf("Light intensity increased!\n");
      } else {
        printf("Light already at maximum intensity!\n");
      }
    } else if (choice == 'D') {
      if (lightIntensity > 0) {
        lightIntensity -= 10;
        printf("Light intensity decreased!\n");
      } else {
        printf("Light already off!\n");
      }
    } else if (choice == 'O') {
      lightIntensity = 0;
      printf("Light turned off!\n");
    } else {
      printf("Invalid choice, try again!\n");
    }
  }

  return 0;
}