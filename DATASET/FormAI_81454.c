//FormAI DATASET v1.0 Category: Weather simulation ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
  srand(time(NULL));    //setting a seed for random number generation
  int temperature, humidity, cloudiness, windSpeed;    //declaring variables

  temperature = rand() % 30 + 10;    //generating random values for the variables
  humidity = rand() % 90 + 10;
  cloudiness = rand() % 100 + 1;
  windSpeed = rand() % 40 + 1;

  //displaying the weather simulation
  printf("Today's Weather Simulation:\n");
  printf("Temperature: %d degrees Celsius\n", temperature);
  
  if(humidity>=80)    //deciding the weather condition based on humidity level
    printf("It's quite humid today!\n");
  else if(humidity>=60)
    printf("It's a bit humid today\n");
  else if(humidity>=40)
    printf("It's moderately humid today\n");
  else if(humidity>=20)
    printf("It's quite dry today\n");
  else
    printf("It's very dry today\n");

  if(cloudiness>=80)    //deciding the weather condition based on cloudiness level
    printf("It's quite cloudy today!\n");
  else if(cloudiness>=60)
    printf("It's a bit cloudy today\n");
  else if(cloudiness>=40)
    printf("It's moderately cloudy today\n");
  else if(cloudiness>=20)
    printf("It's quite clear today\n");
  else
    printf("It's very clear today\n");

  printf("Wind Speed: %d km/h\n", windSpeed);
  
  if(windSpeed>=30)    //deciding the weather condition based on wind speed level
    printf("It's very windy today!\n");
  else if(windSpeed>=20)
    printf("It's quite windy today\n");
  else if(windSpeed>=10)
    printf("It's moderately windy today\n");
  else
    printf("It's quite calm today\n");

  return 0;
}