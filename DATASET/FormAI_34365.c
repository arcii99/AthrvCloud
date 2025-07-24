//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fitnessTracker {
    char name[50];
    int age;
    double weight;
    double height;
    double bmi;
} FitnessTracker;

int main() {
    FitnessTracker user;
    int choice;

    printf("Welcome to the C Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", user.name);
    printf("Please enter your age: ");
    scanf("%d", &user.age);
    printf("Please enter your weight in kilograms: ");
    scanf("%lf", &user.weight);
    printf("Please enter your height in meters: ");
    scanf("%lf", &user.height);

    user.bmi = user.weight / (user.height * user.height);

    printf("Thank you for entering your information.\n");
    printf("Your BMI is %.2lf.\n", user.bmi);

    while(1) {
        printf("What would you like to do next?\n");
        printf("1. View your BMI category\n");
        printf("2. Set a fitness goal\n");
        printf("3. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                if(user.bmi < 18.5) {
                    printf("Your BMI category is underweight.\n");
                } else if(user.bmi >= 18.5 && user.bmi <= 24.9) {
                    printf("Your BMI category is normal weight.\n");
                } else if(user.bmi >= 25 && user.bmi <= 29.9) {
                    printf("Your BMI category is overweight.\n");
                } else {
                    printf("Your BMI category is obese.\n");
                }
                break;
            case 2:
                char goal[100];
                printf("What is your fitness goal?\n");
                scanf("%s", goal);
                printf("Your fitness goal is: %s\n", goal);
                break;
            case 3:
                printf("Thank you for using the C Fitness Tracker! Goodbye.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}