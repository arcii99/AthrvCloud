//FormAI DATASET v1.0 Category: Temperature Converter ; Style: irregular
#include <stdio.h>

int main() {
  int choice;
  float temperature;
  
  printf("Welcome to the Temperature Converter program!\n");
  
  while (1) {
    printf("\nWhat do you want to convert?\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Exit\n");
    
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
      printf("Enter temperature in Celsius: ");
      scanf("%f", &temperature);
      
      float convertedTemp = (temperature * 9/5) + 32;
      printf("%.2f°C is equal to %.2f°F.\n", temperature, convertedTemp);
    }
    
    else if(choice == 2) {
      printf("Enter temperature in Fahrenheit: ");
      scanf("%f", &temperature);
      
      float convertedTemp = (temperature - 32) * 5/9;
      printf("%.2f°F is equal to %.2f°C.\n", temperature, convertedTemp);
    }
    
    else if(choice == 3) {
      printf("Thank you for using Temperature Converter! Goodbye!\n");
      break;
    }
    
    else {
      printf("Invalid choice! Please try again.\n");
    }
  }
  
  return 0;
}