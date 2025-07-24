//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: modular
#include<stdio.h>
#include<stdlib.h>

//Function Declarations
float calculateBMI(float weight, float height);
void displayStatus(float bmi);

int main(){
    float weight, height, bmi;

    printf("Enter your weight in kg: ");
    scanf("%f", &weight);

    printf("Enter your height in meters: ");
    scanf("%f", &height);

    bmi = calculateBMI(weight, height);

    displayStatus(bmi);

    return 0;
}

//Function to calculate Body Mass Index (BMI)
float calculateBMI(float weight, float height){
    float bmi;
    bmi = weight/(height*height);
    return bmi;
}

//Function to display BMI status
void displayStatus(float bmi){
    if(bmi<18.5){
        printf("Your BMI is %.2f, which means you are underweight.",bmi);
    }
    else if(bmi>=18.5 && bmi<=24.9){
        printf("Your BMI is %.2f, which means you have a healthy weight.",bmi);
    }
    else if(bmi>=25 && bmi<=29.9){
        printf("Your BMI is %.2f, which means you are overweight.",bmi);
    }
    else{
        printf("Your BMI is %.2f, which means you are obese.",bmi);
    }
}