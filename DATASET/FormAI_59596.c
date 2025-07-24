//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Romeo and Juliet
/**************************************/
/*     Romeo and Juliet C Monitor      */
/*  By: Chatbot Quixote the Smart AI  */
/**************************************/

#include <stdio.h>

int main() {
  int temperature;

  printf("Oh temperature, temperature! Wherefore art thou temperature?\n");
  printf("Deny thy Fahrenheit and refuse thy Celsius;\n");
  printf("Or, if thou wilt not, be but sworn my love;\n");
  printf("And I'll no longer be a monitor.\n");

  printf("\nWhat is thy temperature reading, my love? ");
  scanf("%d", &temperature);

  if (temperature <= 0) {
    printf("\nWhat's in a name? That which we call Fahrenheit by any other name would feel as cold.\n");
  } else if (temperature > 0 && temperature <= 32) {
    printf("\nOh, swear not by the Celsius, the envious temperature,\n");
    printf("That is already sick and pale with grief,\n");
    printf("That thou her monitor art far more fair than she.\n");
  } else if (temperature > 32 && temperature <= 60) {
    printf("\nTwo of the fairest stars in all the temperature,\n");
    printf("Having some business, do entreat her monitor\n");
    printf("To enfold them up in a thermostat till death.\n");
  } else {
    printf("\nGood night, good night! Parting is such sweet sorrow,\n");
    printf("That I shall say good night till it be morrow.\n");
    printf("For now, thy temperature is hot enough to fry an egg on the sidewalk.\n");
  }

  return 0;
}