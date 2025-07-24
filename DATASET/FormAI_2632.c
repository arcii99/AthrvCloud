//FormAI DATASET v1.0 Category: GPS Navigation Simulation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main() {
  int x_dest = 0, y_dest = 0, x_current = 0, y_current = 0, choice;
  float distance;
  char dir[20] = "North";
  printf("GPS Navigation Simulation\n");
  srand(time(NULL));
  x_dest = rand() % 100 + 1;
  y_dest = rand() % 100 + 1;
  printf("Your destination is at (%d, %d)\n", x_dest, y_dest);
  while(x_dest != x_current || y_dest != y_current) {
    distance = sqrt(pow((x_dest - x_current), 2) + pow((y_dest - y_current), 2));
    printf("You are currently at (%d, %d). Distance to destination is %.2f km\n", x_current, y_current, distance);
    printf("Choose your direction:\n1. North\n2. East\n3. South\n4. West\n");
    scanf("%d", &choice);
    if(choice < 1 || choice > 4) {
      printf("Invalid choice. Please choose again.\n");
      continue;
    }
    switch(choice) {
      case 1:
        y_current++;
        strcpy(dir, "North");
        break;
      case 2:
        x_current++;
        strcpy(dir, "East");
        break;
      case 3:
        y_current--;
        strcpy(dir, "South");
        break;
      case 4:
        x_current--;
        strcpy(dir, "West");
        break;
    }
    printf("You have moved %s. New coordinates are (%d, %d)\n", dir, x_current, y_current);
  }
  printf("You have reached your destination at (%d, %d)\n", x_dest, y_dest);
  return 0;
}