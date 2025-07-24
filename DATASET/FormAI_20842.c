//FormAI DATASET v1.0 Category: Temperature monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float temperature;
  srand(time(NULL));

  printf("Welcome to the Happy Temperature Monitor!\n");

  while(1) {
    temperature = (float)(rand() % 50) + 10;
    printf("-------------------\n");
    if(temperature < 20) {
      printf("Brrr! It's cold in here!\n");
    } else if(temperature > 30) {
      printf("Whoa! It's getting hot in here!\n");
    } else {
      printf("Just the right temperature!\n");
    }
    printf("Temperature is: %.1f degrees Celsius\n", temperature);
    printf("-------------------\n");
    sleep(1);
  }

  return 0;
}