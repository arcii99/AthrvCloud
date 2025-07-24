//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: beginner-friendly
#include <stdio.h>

struct FitnessTracker {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
};

int main() {
    struct FitnessTracker user;

    printf("Enter your name: ");
    fgets(user.name, 50, stdin);

    printf("Enter your age: ");
    scanf("%d", &user.age);

    printf("Enter your weight in kg: ");
    scanf("%f", &user.weight);

    printf("Enter your height in m: ");
    scanf("%f", &user.height);

    user.bmi = user.weight / (user.height * user.height);

    printf("\nFitness Tracker for %s", user.name);
    printf("\nAge: %d", user.age);
    printf("\nWeight: %.2f kg", user.weight);
    printf("\nHeight: %.2f m", user.height);
    printf("\nBMI: %.2f", user.bmi);

    return 0;
}