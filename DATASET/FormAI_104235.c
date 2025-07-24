//FormAI DATASET v1.0 Category: Temperature monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  float temp;
  time_t t;
  srand((unsigned) time(&t));
  int num = rand() % 101;
  
  printf("Please enter the current temperature: ");
  scanf("%f", &temp);
  printf("You entered %.1f degrees Celsius.\n", temp);
  
  if (temp < -273.15) {
    printf("The temperature you entered is impossible. Please try again.\n");
    return 0;
  }
  else if (temp < 0) {
    printf("The temperature is below freezing! Are you wearing a coat?\n");
  }
  else if (temp > 100) {
    printf("The temperature is boiling! Be careful not to burn yourself.\n");
  }
  else {
    printf("The temperature is within normal range.\n");
  }
  
  if (num < temp) {
    printf("The temperature has increased since the last reading!\n");
  }
  else if (num > temp) {
    printf("The temperature has decreased since the last reading.\n");
  }
  else {
    printf("The temperature is the same as the last reading.\n");
  }
  
  printf("The actual temperature is %.1f degrees Celsius.\n", num);
  if (temp == num) {
    printf("Phew, you entered the correct temperature. You may leave now.\n");
  }
  else {
    printf("You entered the wrong temperature. The authorities have been notified.\n");
  }
  
  return 0;
}