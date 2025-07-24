//FormAI DATASET v1.0 Category: Temperature Converter ; Style: surrealist
#include<stdio.h>
#include<stdlib.h>

int main(){
  float temperature;

  printf("Welcome to the Surrealist Temperature Converter Program!\n");
  printf("Please enter the temperature in Celsius. (The temperature of your dreams) \n");
  scanf("%f", &temperature);

  float converted = (temperature * 1.8) + 32;

  printf("Your temperature in Fahrenheit is %f. (The surreal temperature of your nightmares)\n", converted);
  printf("Do you want to convert the Fahrenheit temperature back to Celsius? (yes/no)\n");

  char response[3];
  scanf("%s", &response);

  if (response[0] == 'y'){
    float reconverted = (converted - 32) / 1.8;
    printf("Your temperature in Celsius is %f. (The temperature of your subconscious)\n", reconverted);
    printf("This program opens up new worlds of temperature conversion beyond our human comprehension and understanding. Thank you for using this program. Surrealism wins again!\n");
  } else {
    printf("This program opens up new worlds of temperature conversion beyond our human comprehension and understanding. Thank you for using this program. Surrealism wins again!\n");
  }
  return 0;
}