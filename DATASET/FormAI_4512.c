//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>

int main(){
    // Declare User's data points 
    float weight;
    float height;
    int age;
    char gender;

    // Prompt user for input and collect data points
    printf("Please enter your weight (kg): ");
    scanf("%f", &weight);

    printf("Please enter your height (cm): ");
    scanf("%f", &height);

    printf("Please enter your age: ");
    scanf("%d", &age);

    printf("Please enter your gender (M/F):");
    scanf("%*c%c", &gender);

    // Calculate user's body mass index (BMI) using data points collected
    float bmi = weight / ((height/100) * (height/100));

    // Print out user's data and BMI
    printf("\nYour weight is %.1fkg, ", weight);
    printf("your height is %.1fcm, ", height);
    printf("your age is %d and ", age);
    printf("your gender is %c.\n", gender);
    printf("Your body mass index (BMI) is %.2f.\n", bmi);

    // Provide interpretation of user's BMI value
    if(bmi < 18.5){
        printf("You are underweight. Consider increasing your daily calorie intake.");
    } else if(bmi >= 18.5 && bmi <= 24.9){
        printf("You are within the healthy weight range. Great job!");
    } else if(bmi >= 25 && bmi <= 29.9){
        printf("You are overweight. Consider reducing your daily calorie intake and/or increasing your physical activity.");
    } else {
        printf("You are obese. It is important to make lifestyle changes to improve your overall health and reduce your risk of chronic diseases.");
    }

    return 0;
}