//FormAI DATASET v1.0 Category: Temperature monitor ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  srand(time(0));
  char celsius[10];
  int temp = rand() % 101; // random temperature from 0-100
  
  printf("Celsius Temperature Monitor:\n");
  printf("Current temperature: %dC\n\n", temp);
  
  while(1) { // loops forever until program is stopped
    printf("Enter a maximum temperature: ");
    fgets(celsius, 10, stdin); // read user input
    
    int max_temp = atoi(celsius);
    
        if (max_temp <= 0) { // check if input is valid
            printf("Invalid input. Please enter a positive integer.\n\n");
            continue;
        }
        else { // valid input
            if (temp > max_temp) { // high temperature
                printf("Warning: Temperature is currently %dC, which is higher than the maximum of %dC.\n\n", temp, max_temp);
            }
            else { // normal temperature
                printf("Temperature is normal at %dC.\n\n", temp);
            }
        }
    }
    return 0;
}