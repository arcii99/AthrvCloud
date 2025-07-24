//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Linus Torvalds
#include<stdio.h>

int main() {
  float fahrenheit, celsius;
  
  printf("Enter temperature in Fahrenheit: ");
  scanf("%f", &fahrenheit);
  
  celsius = (fahrenheit - 32) * 5/9;
  
  printf("%.2f degrees Fahrenheit is equal to %.2f degrees Celsius\n", fahrenheit, celsius);
  
  return 0;
}

/* This is a simple C program to convert temperature from Fahrenheit to Celsius in Linus Torvalds style.
 * Whenever someone asks Linus about the importance of temperature conversion, he always says, "If you have a computer that runs hot, you need to understand temperature."
 * So, given his love for temperature management, this program helps to convert temperature from Fahrenheit to Celsius and keep your computer cool.
 * It takes input in Fahrenheit and uses the formula (F - 32) * 5/9 to convert it into Celsius.
 * The output is then displayed in the format of "degrees Fahrenheit is equal to degrees Celsius".
 * With this program, you can ensure your computer is running at optimal temperature levels.
 * Happy temperature managing, folks!
 */