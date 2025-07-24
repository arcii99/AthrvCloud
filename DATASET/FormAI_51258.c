//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Ken Thompson
#include <stdio.h>
#include <string.h>

struct FitnessTracker {
    char name[20];
    int age;
    float weight;
    float height;
    int steps;
};

float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

int main() {
    struct FitnessTracker person;
    printf("Enter your name: ");
    scanf("%s", person.name);
    printf("Enter your age: ");
    scanf("%d", &person.age);
    printf("Enter your weight in kg: ");
    scanf("%f", &person.weight);
    printf("Enter your height in m: ");
    scanf("%f", &person.height);

    int minutes;
    printf("Enter your total exercise time in minutes: ");
    scanf("%d", &minutes);

    printf("\n%s's Fitness Tracker Report\n", person.name);
    printf("Age: %d\n", person.age);
    printf("Weight: %.2fkg\n", person.weight);
    printf("Height: %.2fm\n", person.height);
    printf("BMI: %.2f\n", calculateBMI(person.weight, person.height));

    float miles = (person.steps * 3 * 0.000189394);
    float calories = 0.5 * person.weight * minutes / 60;
    
    printf("Steps taken: %d\n", person.steps);
    printf("Distance travelled: %.2f miles\n", miles);
    printf("Calories burnt: %.2f\n", calories);

    return 0;
}