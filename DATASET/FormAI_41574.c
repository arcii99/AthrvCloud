//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surprised
#include <stdio.h>

int main() {
  printf("Welcome to the Temperature Converter!\n");
  printf("Enter the temperature in Celsius: ");
  double celsius;
  scanf("%lf", &celsius);
  double fahrenheit = (celsius * 9/5) + 32;
  printf("%lf degrees Celsius is %lf degrees Fahrenheit!\n", celsius, fahrenheit);
  printf("Can you believe it? That's hot!\n");
  
  printf("But wait, there's more!\n");
  printf("Enter the temperature in Fahrenheit: ");
  double f_temp;
  scanf("%lf", &f_temp);
  double c_temp = (f_temp - 32) * 5/9;
  printf("%lf degrees Fahrenheit is %lf degrees Celsius!\n", f_temp, c_temp);
  printf("Surprise! It's much cooler in Celsius.\n");
  
  printf("Do you want to convert another temperature? (y/n) ");
  char choice;
  scanf(" %c", &choice);
  if (choice == 'y') {
    printf("Great! Here we go again!\n");
    main(); // loop back to beginning
  } else {
    printf("Thanks for using my Temperature Converter! Stay cool. :)\n");
  }
  
  return 0;
}