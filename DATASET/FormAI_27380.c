//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Romeo and Juliet
#include<stdio.h>

// Romeo is in love with Fahrenheit, but Juliet only speaks Celsius
int main(){

  int fahrenheit, celsius;

  // Romeo, the lover of Fahrenheit, initiates the conversation
  printf("My love, please tell me the temperature in Fahrenheit: ");
  scanf("%d", &fahrenheit);

  // Juliet, feeling a bit intimidated, takes a deep breath and calculates Celsius
  celsius = (fahrenheit - 32) * 5 / 9;

  // Juliet, feeling proud of herself, answers the question
  printf("Romeo, my dear, the temperature in Celsius is: %d\n", celsius);

  // Romeo, feeling determined, wants to impress Juliet with a knowledge of Celsius
  printf("Juliet, my love, please tell me the temperature in Celsius: ");
  scanf("%d", &celsius);

  // Romeo, feeling happy with himself, converts Celsius to Fahrenheit
  fahrenheit = celsius * 9 / 5 + 32;

  // Romeo, feeling confident, shares his newfound knowledge with Juliet
  printf("Juliet, my love, the temperature in Fahrenheit is: %d\n", fahrenheit);

  // Romeo and Juliet, feeling good about their newfound knowledge, declare their love for each other
  printf("My love, Juliet. I never knew temperature could bring us so close.\n");
  printf("I am forever in your debt. Thank you for teaching me about Celsius.\n");

  // Romeo and Juliet, feeling happy, live happily ever after
  return 0;
}