//FormAI DATASET v1.0 Category: Temperature monitor ; Style: puzzling
#include <stdio.h>

int main() {
  int temp, previousTemp = -999;
  int count = 0;
  char status[20] = "normal";
  
  printf("Welcome to the mysterious C Temperature monitor...\n\n");
  
  while (1) {
    printf("Enter the current temperature (in Celsius): ");
    scanf("%d", &temp);
    
    if (temp < previousTemp) {
      count++;
      if (count >= 2) {
        printf("*ALERT* Temperature is dropping rapidly!\n");
        strcpy(status, "dangerous");
      } else {
        printf("*WARNING* Temperature is starting to drop!\n");
        strcpy(status, "warning");
      }
    } else if (temp > previousTemp) {
      count--;
      if (count <= -2) {
        printf("*ALERT* Temperature is rising rapidly!\n");
        strcpy(status, "dangerous");
      } else {
        printf("*WARNING* Temperature is starting to rise!\n");
        strcpy(status, "warning");
      }
    } else {
      count = 0;
    }
    
    previousTemp = temp;
    
    printf("Current temperature status: %s\n\n", status);
    
    if (count == -5) {
      printf("You have reached the end of the mysterious C Temperature monitor...\n");
      break;
    }
  }
  
  return 0;
}