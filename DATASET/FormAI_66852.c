//FormAI DATASET v1.0 Category: Temperature monitor ; Style: visionary
#include <stdio.h>

int main() {
  float temperature;
  int hours, minutes;
  char meridian[3];

  printf("Welcome to the Temperature Monitor App\n\n");

  printf("Please enter the current temperature in Celsius: ");
  scanf("%f", &temperature);

  printf("Please enter the current time in 24 hour format (HH:MM): ");
  scanf("%d:%d", &hours, &minutes);

  if (hours < 12) {
    strcpy(meridian, "AM");
  } else {
    strcpy(meridian, "PM");
  }

  printf("\n\n");
  printf("-------------------------------\n");
  printf("| Temperature: %.2f Celsius |\n", temperature);
  printf("| Time: %02d:%02d %s             |\n", hours%12, minutes, meridian);
  printf("-------------------------------\n");

  if (temperature >= 100) {
    printf("WARNING: High temperature detected!\n");
  } else if (temperature <= 0) {
    printf("WARNING: Low temperature detected!\n");
  }

  return 0;
}