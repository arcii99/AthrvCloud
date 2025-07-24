//FormAI DATASET v1.0 Category: Temperature Converter ; Style: configurable
#include<stdio.h>
#include<stdlib.h>

int main()
{
  float fahr, cels; char option;
  printf("This program converts temperature ");
  printf("from Celsius to Fahrenheit or Fahrenheit to Celsius\n");
  
  printf("Enter 'C' to convert from Celsius to Fahrenheit\n");
  printf("Enter 'F' to convert from Fahrenheit to Celsius\n");
  scanf("%c", &option);

  if(option == 'C' || option == 'c')
  {
      printf("\nEnter temperature in Celsius: ");
      scanf("%f", &cels);
      
      //Formula for temperature conversion
      fahr = (cels * 9/5) + 32;

      printf("\n%.1f degrees Celsius is equal to %.1f degrees Fahrenheit\n", cels, fahr);
  }
  else if(option == 'F' || option == 'f')
  {
      printf("\nEnter temperature in Fahrenheit: ");
      scanf("%f", &fahr);

      //Formula for temperature conversion
      cels = (fahr - 32) * 5/9;

      printf("\n%.1f degrees Fahrenheit is equal to %.1f degrees Celsius\n", fahr, cels);
  }
  else
  {
      printf("Invalid Input!");
  }

  return 0;
}