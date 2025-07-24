//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: ultraprecise
#include<stdio.h>
#include<string.h>

struct Fitness {
   char name[50];
   float weight;
   float height;
   float bmi;
   char status[10];
};

int main() {
   struct Fitness person;
   float bmi;

   printf("Enter your name: ");
   scanf("%s", &person.name);

   printf("Enter your weight in kilograms: ");
   scanf("%f", &person.weight);

   printf("Enter your height in meters: ");
   scanf("%f", &person.height);

   bmi = person.weight / (person.height * person.height);

   if (bmi < 18.5) {
      strcpy(person.status, "Underweight");
   }
   else if (bmi >= 18.5 && bmi <= 24.9) {
      strcpy(person.status, "Normal");
   }
   else if (bmi >= 25.0 && bmi <= 29.9) {
      strcpy(person.status, "Overweight");
   }
   else {
      strcpy(person.status, "Obese");
   }

   person.bmi = bmi;

   printf("\nName: %s\n", person.name);
   printf("Weight: %.2f kilograms\n", person.weight);
   printf("Height: %.2f meters\n", person.height);
   printf("BMI: %.2f\n", person.bmi);
   printf("Status: %s\n", person.status);

   return 0;
}