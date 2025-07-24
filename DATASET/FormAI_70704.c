//FormAI DATASET v1.0 Category: Temperature Converter ; Style: invasive
#include <stdio.h>

int main() {
  float tempC, tempF;
  
  printf("Enter temperature in Celsius: ");
  scanf("%f", &tempC);
  
  // Conversion formula
  tempF = (tempC * 1.8) + 32;
  
  printf("%f Celsius is equal to %f Fahrenheit.\n", tempC, tempF);
  
  printf("Do you want to convert another temperature? (Y/N) ");
  char choice;
  scanf(" %c", &choice);
  
  while (choice == 'Y' || choice == 'y') {
    // Prompt for new temperature
    printf("Enter temperature in Celsius: ");
    scanf("%f", &tempC);
    
    // Conversion formula
    tempF = (tempC * 1.8) + 32;
    
    printf("%f Celsius is equal to %f Fahrenheit.\n", tempC, tempF);
    
    printf("Do you want to convert another temperature? (Y/N) ");
    scanf(" %c", &choice);
  }
  
  printf("Thank you for using the temperature converter!\n");
  
  return 0;
}