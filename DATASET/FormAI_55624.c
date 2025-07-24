//FormAI DATASET v1.0 Category: Computer Biology ; Style: energetic
#include <stdio.h>

// Define a struct to represent a human
typedef struct Human {
  char name[50];
  int age;
  float height_m;
  float weight_kg;
} Human;

// Function to calculate body mass index
float calculate_bmi(float weight_kg, float height_m) {
  return weight_kg / (height_m * height_m);
}

// Main function to run the program
int main() {
  // Create a new human object
  Human me = {"John Doe", 28, 1.8, 78};

  // Calculate my body mass index
  float bmi = calculate_bmi(me.weight_kg, me.height_m);

  // Print out my name, age, and BMI
  printf("Name: %s\n", me.name);
  printf("Age: %d\n", me.age);
  printf("BMI: %f\n", bmi);

  // Print out some motivational messages based on my BMI
  if (bmi < 18.5) {
    printf("You're underweight! Eat more and exercise to gain weight.\n");
  } else if (bmi < 25) {
    printf("You're in a healthy weight range. Keep up the good work!\n");
  } else if (bmi < 30) {
    printf("You're overweight! Consider exercising and eating a healthier diet.\n");
  } else {
    printf("You're obese! Consult a doctor to start a weight-loss program.\n");
  }

  return 0;
}