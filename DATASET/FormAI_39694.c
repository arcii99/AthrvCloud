//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: curious
#include <stdio.h>
#include <string.h>

int main()
{
    char name[50];
    int age;
    float weight, height, bmi;

    printf("Welcome to the Fitness Tracker!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Please enter your age: ");
    scanf("%d", &age);
    printf("Please enter your weight(in kgs): ");
    scanf("%f", &weight);
    printf("Please enter your height(in meters): ");
    scanf("%f", &height);

    bmi = weight / (height * height);

    printf("\nHello, %s!\n", name);
    printf("Your age is: %d\n", age);
    printf("Your weight is: %.2f kgs\n", weight);
    printf("Your height is: %.2f meters\n", height);
    printf("Your BMI is: %.2f\n", bmi);

    if (bmi < 18.5)
    {
        printf("You are underweight.\n");
    }
    else if (bmi >= 18.5 && bmi < 25)
    {
        printf("You are in the normal weight range.\n");
    }
    else if (bmi >= 25 && bmi < 30)
    {
        printf("You are overweight.\n");
    }
    else
    {
        printf("You are obese.\n");
    }

    return 0;
}