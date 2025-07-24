//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

//defining the function to calculate the BMI
float calculate_bmi(float weight, float height){
    float bmi;
    bmi = weight/(height*height);
    return bmi;
}

//defining the main function
int main(){

    float weight, height, bmi;
    int age, step_count, calories;

    //asking for the input from the user
    printf("Enter your weight in kgs: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your step count: ");
    scanf("%d", &step_count);

    //calculating the BMI using the function
    bmi = calculate_bmi(weight, height);

    //printing the BMI
    printf("\nYour BMI is: %.2f\n", bmi);

    //calculating the approximate calories burned
    calories = (0.035 * weight) + (1.45 * ((height * 100)/2.54) - (0.018 * age) - 0.385) * step_count;

    //printing the calories burned
    printf("You have burned approximately %d calories.\n", calories);

    return 0;
}