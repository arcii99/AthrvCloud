//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: retro
#include<stdio.h>
#include<string.h>

struct fitnessTracker {
    char username[20];
    int age;
    float weight;
    float height;
    float BMI;
};

int main() {
    struct fitnessTracker user;

    printf("Enter your username: ");
    scanf("%s", user.username);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Enter your height (in m): ");
    scanf("%f", &user.height);

    user.BMI = user.weight / (user.height * user.height);
    printf("Your BMI is %.2f\n\n", user.BMI);

    if (user.BMI < 18.5) {
        printf("You are underweight.\n");
    } else if (user.BMI < 24.9) {
        printf("You have a healthy weight.\n");
    } else if (user.BMI < 29.9) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }

    return 0;
}