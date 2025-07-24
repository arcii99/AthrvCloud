//FormAI DATASET v1.0 Category: Temperature Converter ; Style: cheerful
#include<stdio.h>

int main(){
  printf("Welcome to the Temperature Converter!\n");
  int choice;
  float temperature;
  char unit;

  printf("Enter the conversion you would like to make:\n");
  printf("1. Celsius to Fahrenheit\n");
  printf("2. Fahrenheit to Celsius\n");

  scanf("%d",&choice);

  if(choice == 1){
    printf("Enter the temperature in Celsius: ");
    scanf("%f",&temperature);
    unit = 'C';
    float result = (temperature * 9 / 5) + 32;
    printf("%.2f%c is equivalent to %.2fF.\n",temperature,unit,result);
  }
  else if(choice == 2){
    printf("Enter the temperature in Fahrenheit: ");
    scanf("%f",&temperature);
    unit = 'F';
    float result = (temperature - 32) * 5 / 9;
    printf("%.2f%c is equivalent to %.2fC.\n",temperature,unit,result);
  }
  else{
    printf("Invalid choice. Please enter 1 or 2.\n");
  }

  printf("Thanks for using the Temperature Converter!\n");

  return 0;
}