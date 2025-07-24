//FormAI DATASET v1.0 Category: Temperature Converter ; Style: Cryptic
#include<stdio.h>

int main()
{
  int temp,converted_val;
  char choice;

  printf("Cryptic C Temperature Converter\n");
  printf("Enter 'F' to convert Fahrenheit to Celsius\n");
  printf("Enter 'C' to convert Celsius to Fahrenheit\n");

  scanf("%c",&choice);

  switch(choice)
  {
    case 'F':
      printf("Enter temperature in Fahrenheit: ");
      scanf("%d",&temp);
      converted_val = (temp - 32) * 5/9;
      printf("Temperature in Celsius is: %d",converted_val);
      break;

    case 'C':
      printf("Enter temperature in Celsius: ");
      scanf("%d",&temp);
      converted_val = (temp * 9/5) + 32;
      printf("Temperature in Fahrenheit is: %d",converted_val);
      break;

    default:
      printf("Invalid Input");
  }

  return 0;
}