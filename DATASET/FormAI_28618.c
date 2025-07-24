//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int weight, height;
    float bmi, target_weight;
    char name[50];
    
    printf("Welcome to the C Fitness Tracker!\n\n");
    
    printf("Please enter your name: ");
    scanf("%s", name);
    
    printf("\n%s, please enter your weight in kilograms: ", name);
    scanf("%d", &weight);
    
    printf("\n%s, please enter your height in centimeters: ", name);
    scanf("%d", &height);
    
    bmi = weight / ((float)height/100 * (float)height/100);
    
    if(bmi < 18.5)
    {
        printf("\n%s, your BMI is %.2f which is underweight.\n", name, bmi);
        target_weight = ((float)18.5/10000) * (float)height * (float)height;
        printf("\nYour ideal weight is %.2f kg.\n", target_weight);
    }
    else if(bmi >= 18.5 && bmi < 25.0)
        printf("\n%s, your BMI is %.2f which is healthy.\n", name, bmi);
    else if(bmi >= 25.0 && bmi < 30.0)
    {
        printf("\n%s, your BMI is %.2f which is overweight.\n", name, bmi);
        target_weight = ((float)25.0/10000) * (float)height * (float)height;
        printf("\nYour ideal weight is %.2f kg.\n", target_weight);
    }
    else
    {
        printf("\n%s, your BMI is %.2f which is obese.\n", name, bmi);
        target_weight = ((float)18.5/10000) * (float)height * (float)height;
        printf("\nYour ideal weight is %.2f kg.\n", target_weight);
    }
    
    return 0;
}