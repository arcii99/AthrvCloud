//FormAI DATASET v1.0 Category: Temperature Converter ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  // Code for temperature converter
  float temp_C, temp_F;
  int choice;
  
  printf("Enter a temperature value in Celsius: ");
  scanf("%f", &temp_C);
  
  printf("\nSelect an option:\n1. Convert to Fahrenheit\n2. Convert to Kelvin\n3. Exit\n\nYour choice: ");
  scanf("%d", &choice);
  
  switch(choice) {
    case 1:
      temp_F = (temp_C * 9/5) + 32;
      printf("\nThe temperature in Fahrenheit is %.2fF.", temp_F);
      break;
      
    case 2:
      temp_F = (temp_C * 9/5) + 32;
      float temp_K = temp_C + 273.15;
      printf("\nThe temperature in Fahrenheit is %.2fF and in Kelvin is %.2fK.", temp_F, temp_K);
      break;
      
    case 3:
      printf("\nExiting program...");
      break;
      
    default:
      printf("\nInvalid choice. Please try again.");
  }
  
  return 0;
}