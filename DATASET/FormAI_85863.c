//FormAI DATASET v1.0 Category: Data mining ; Style: detailed
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* A structure to represent a person */
struct Person {
   char name[20];
   int age;
   double height;
   double weight;
};

/* A function to generate a random age between minAge and maxAge */
int generateRandomAge(int minAge, int maxAge) {
   return (rand() % (maxAge - minAge + 1)) + minAge;
}

/* A function to generate a random height between minHeight and maxHeight */
double generateRandomHeight(double minHeight, double maxHeight) {
   double range = maxHeight - minHeight;
   double randomFraction = (double) rand() / RAND_MAX;
   return minHeight + (range * randomFraction);
}

/* A function to generate a random weight between minWeight and maxWeight */
double generateRandomWeight(double minWeight, double maxWeight) {
   double range = maxWeight - minWeight;
   double randomFraction = (double) rand() / RAND_MAX;
   return minWeight + (range * randomFraction);
}

int main() {
   /* Declare variables */
   int numPeople = 100;
   struct Person people[numPeople];
   char names[10][20] = {"John", "Mary", "Tom", "Jenny", "Jack", "Emily", "David", "Sophie", "Adam", "Grace"};
   int i;
   
   /* Generate people with random data */
   for (i = 0; i < numPeople; i++) {
      strcpy(people[i].name, names[rand() % 10]);
      people[i].age = generateRandomAge(18, 65);
      people[i].height = generateRandomHeight(1.5, 2.0);
      people[i].weight = generateRandomWeight(50.0, 100.0);
   }
   
   /* Print data about people */
   printf("People:\n");
   for (i = 0; i < numPeople; i++) {
      printf("- Name: %s, Age: %d, Height: %lf, Weight: %lf\n", people[i].name, people[i].age, people[i].height, people[i].weight);
   }
   
   /* Data mining: Find the person with the highest BMI */
   double highestBMI = 0.0;
   int indexHighestBMI = 0;
   for (i = 0; i < numPeople; i++) {
      double bmi = people[i].weight / (people[i].height * people[i].height);
      if (bmi > highestBMI) {
         highestBMI = bmi;
         indexHighestBMI = i;
      }
   }
   
   /* Print data about person with highest BMI */
   printf("Person with highest BMI: %s (BMI = %lf)\n", people[indexHighestBMI].name, highestBMI);
   
   return 0;
}