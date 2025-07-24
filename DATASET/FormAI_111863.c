//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main() {
   int user_age;
   float user_weight, user_height;
   float user_bmi, user_calories;
   int user_steps, user_hours_slept;

   printf("Welcome to your Future Fitness Tracker!\n");
   printf("Please enter your age: ");
   scanf("%d", &user_age);
   printf("Please enter your weight in kg: ");
   scanf("%f", &user_weight);
   printf("Please enter your height in cm: ");
   scanf("%f", &user_height);
   printf("Please enter the number of steps you took today: ");
   scanf("%d", &user_steps);
   printf("Please enter the number of hours you slept last night: ");
   scanf("%d", &user_hours_slept);

   user_bmi = user_weight / ((user_height/100) * (user_height/100));
   printf("Your BMI is: %.2f\n", user_bmi);

   if(user_bmi < 18.5) {
      printf("You are underweight.\n");
      user_calories = 1800 + (user_steps*0.05) - (user_hours_slept*50);
   } else if(user_bmi >= 18.5 && user_bmi <= 24.9) {
      printf("You are within a healthy weight range.\n");
      user_calories = 2000 + (user_steps*0.04) - (user_hours_slept*40);
   } else if(user_bmi >= 25 && user_bmi <= 29.9) {
      printf("You are overweight.\n");
      user_calories = 1700 + (user_steps*0.03) - (user_hours_slept*30);
   } else {
      printf("You are obese.\n");
      user_calories = 1500 + (user_steps*0.02) - (user_hours_slept*20); 
   }

   printf("You burned %d calories today.\n", (int)user_calories);
   printf("Thank you for using the Future Fitness Tracker! Goodbye!\n");
   return 0;
}