//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: configurable
#include <stdio.h>

struct User {
    char name[50];
    int age;
    float weight;
    float height;
};

// Calculates the user's BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// Displays the user's BMI category
void displayBMICategory(float bmi) {
    if (bmi < 18.5) {
        printf("Your BMI is %.2f, which means you are underweight.\n", bmi);
    } else if (bmi < 25) {
        printf("Your BMI is %.2f, which means you have a normal weight.\n", bmi);
    } else if (bmi < 30) {
        printf("Your BMI is %.2f, which means you are overweight.\n", bmi);
    } else {
        printf("Your BMI is %.2f, which means you are obese.\n", bmi);
    }
}

int main() {
    struct User user;
    
    // Get user input
    printf("Enter your name: ");
    fgets(user.name, 50, stdin);
    printf("Enter your age: ");
    scanf("%d", &user.age);
    printf("Enter your weight (in kg): ");
    scanf("%f", &user.weight);
    printf("Enter your height (in meters): ");
    scanf("%f", &user.height);
    
    // Calculate and display the user's BMI
    float bmi = calculateBMI(user.weight, user.height);
    displayBMICategory(bmi);
    
    return 0;
}