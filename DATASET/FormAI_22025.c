//FormAI DATASET v1.0 Category: Unit converter ; Style: standalone
#include <stdio.h>

int main() {

  int option; // used to store user-input option
  float value; //used to store user-input value
  
  printf( "Welcome to the Unit Converter.\n\n" );
  printf( "Please select an option:\n" );
  printf( "1. Kilometers to Miles\n" );
  printf( "2. Miles to Kilometers\n" );
  printf( "3. Celsius to Fahrenheit\n" );
  printf( "4. Fahrenheit to Celsius\n" );
  
  scanf( "%d", &option ); // take option input from the user
  
  switch (option)
  {
    case 1: //convert Kilometers to Miles
      printf( "\nEnter the distance in Kilometers: " );
      scanf( "%f", &value );
      printf("%.2f Kilometers = %.2f Miles\n", value, (value/1.609344));
      break;
    
    case 2: //convert Miles to Kilometers
      printf( "\nEnter the distance in Miles: " );
      scanf( "%f", &value );
      printf("%.2f Miles = %.2f Kilometers\n", value, (value*1.609344));
      break;
    
    case 3: //convert Celsius to Fahrenheit
      printf( "\nEnter the temperature in Celsius: " );
      scanf( "%f", &value );
      printf("%.2f Celsius = %.2f Fahrenheit\n", value, (value*(9.0/5.0))+32);
      break;
      
    case 4: //convert Fahrenheit to Celsius
      printf( "\nEnter the temperature in Fahrenheit: " );
      scanf( "%f", &value );
      printf("%.2f Fahrenheit = %.2f Celsius\n", value, (value-32)*(5.0/9.0));
      break;
    
    default: //option other than 1,2,3,4 entered
      printf( "\nInvalid option selected!\n" );
      break;
  }
  
  return 0;
}