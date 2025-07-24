//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

int main(void){

    float weight;
    float height;
    float bmi;

    printf("Type in your weight in kilogram: ");
    scanf("%f", &weight);

    printf("Type in your height in meters: ");
    scanf("%f", &height);

    bmi = weight/(height*height);

    printf("Your Body Mass Index is: %.2f\n", bmi);

    if(bmi<18.5){
        printf("You are underweight. Consider gaining some weight.\n");
    }
    else if(bmi>=18.5 && bmi<=24.9){
        printf("You are in a healthy weight range. Keep up the good work!\n");
    }
    else if(bmi>=25 && bmi<=29.9){
        printf("You are overweight. Consider shedding some pounds.\n");
    }
    else{
        printf("You are obese. Consider consulting a doctor for weight loss advice.\n");
    }

    return EXIT_SUCCESS;

}