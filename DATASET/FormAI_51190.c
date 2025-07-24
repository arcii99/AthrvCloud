//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include<stdio.h>
#include<math.h>

int main()
{
    float weight,height,bmi;
    int age, steps;

    printf("Welcome to your fitness tracker!\n");
    printf("Please enter your weight in kilograms: ");
    scanf("%f",&weight);

    printf("Please enter your height in meters: ");
    scanf("%f",&height);

    printf("Please enter your age in years: ");
    scanf("%d",&age);

    printf("Please enter the number of steps taken today: ");
    scanf("%d",&steps);

    bmi = weight/(pow(height,2));

    printf("Your BMI is: %.2f\n",bmi);

    if(bmi<18.5){
        printf("You are underweight.\n");
    }
    else if(bmi>=18.5 && bmi<=24.9){
        printf("You are within a healthy weight range.\n");
    }
    else if(bmi>=25.0 && bmi<=29.9){
        printf("You are overweight.\n");
    }
    else{
        printf("You are obese.\n");
    }

    //Assuming 1km = 1250 steps and 1km = 0.62 miles
    float distance = (steps/1250)*0.62;
    printf("You have walked %.2f miles today\n",distance);

    int calories_burnt = (age*0.2017)-(weight*0.09036)+(distance*1000*0.035)+(steps*0.000473);
    printf("You have burnt approximately %d calories today\n",calories_burnt);

    return 0;
}