//FormAI DATASET v1.0 Category: Temperature Converter ; Style: retro
#include<stdio.h>
//retro style temperature converter program

int main(){
  int choice;
  float temp;
  printf("Welcome to the Retro Temperature Converter Program!\n");
  printf("Enter 1 to convert Celsius to Fahrenheit\n");
  printf("Enter 2 to convert Fahrenheit to Celsius\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  switch(choice){
    case 1:
      printf("Input temperature in Celsius: ");
      scanf("%f", &temp);
      float fahrenheit = (temp * 9)/5 + 32;
      printf("%.2fC is equal to %.2fF\n", temp, fahrenheit);
      break;
  
    case 2:
      printf("Input temperature in Fahrenheit: ");
      scanf("%f", &temp);
      float celsius = (temp - 32) * 5/9;
      printf("%.2fF is equal to %.2fC\n", temp, celsius);
      break;
  
    default:
      printf("Invalid choice!\n");
  }
  printf("Thanks for using the Retro Temperature Converter Program!");
  return 0;
}