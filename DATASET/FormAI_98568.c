//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>

void main() {
  float weight = 60.0, height = 1.65, bmi;
  int age = 25, target_weight = 55;
  int steps[7] = {5000, 6000, 7000, 8000, 9000, 10000, 12000};
  int heart_rate[7] = {60, 65, 70, 75, 80, 85, 90};
  int index;

  // Calculate BMI
  bmi = weight / (height * height);
  printf("BMI: %.2f\n", bmi);

  // Calculate recommended daily steps
  int daily_steps = (age >= 18 && age <= 64) ? 10000 : 8000;
  printf("Recommended daily steps: %d\n", daily_steps);

  // Calculate progress towards target weight
  int progress = (int) ((weight - target_weight) / (weight / 100));
  printf("Progress towards target weight: %d%%\n", progress);

  // Calculate optimal heart rate zone
  int max_heart_rate = 220 - age;
  int optimal_zone_low = (int) (max_heart_rate * 0.6);
  int optimal_zone_high = (int) (max_heart_rate * 0.8);
  printf("Optimal heart rate zone: %d-%d bpm\n", optimal_zone_low, optimal_zone_high);

  // Determine average steps and heart rate for the week
  int total_steps = 0;
  int average_steps, average_heart_rate;

  for (index = 0; index < 7; index++) {
    total_steps += steps[index];
  }

  average_steps = total_steps / 7;
  printf("Average daily steps: %d\n", average_steps);

  int total_heart_rate = 0;

  for (index = 0; index < 7; index++) {
    total_heart_rate += heart_rate[index];
  }

  average_heart_rate = total_heart_rate / 7;
  printf("Average daily heart rate: %d bpm\n", average_heart_rate);
}