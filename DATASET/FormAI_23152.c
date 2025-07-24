//FormAI DATASET v1.0 Category: Physics simulation ; Style: Ada Lovelace
#include <stdio.h>
#include <math.h>

int main() {
  double amplitude, frequency, time;
  printf("Enter the amplitude (in meters): ");
  scanf("%lf", &amplitude);
  printf("Enter the frequency (in hertz): ");
  scanf("%lf", &frequency);
  printf("Enter the time (in seconds): ");
  scanf("%lf", &time);
  double displacement = amplitude * sin(2 * M_PI * frequency * time);
  printf("The displacement of the oscillator is %lf meters.\n", displacement);
  return 0;
}