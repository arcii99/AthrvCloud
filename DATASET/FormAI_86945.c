//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

double calculateBMI(int height, int weight)
{
    double BMI = weight / ((height / 100.0) * (height / 100.0));
    return BMI;
}

int main()
{
    int height, weight, age, target_weight;
    double BMI;
    printf("Welcome to Fitness Tracker, please enter your details\n");
    printf("Height (in cm): ");
    scanf("%d", &height);
    printf("Weight (in kg): ");
    scanf("%d", &weight);
    BMI = calculateBMI(height, weight);
    printf("Your BMI is %.2f\n", BMI);
    printf("Age: ");
    scanf("%d", &age);
    printf("Target Weight (in kg): ");
    scanf("%d", &target_weight);
    int daily_calorie_intake = 10 * weight + 6 * height - 5 * age + 5;
    printf("Your daily calorie intake should be %d calories/day\n", daily_calorie_intake);

    double weight_to_lose = weight - target_weight;
    printf("You need to lose %.2f kg to reach your target weight\n", weight_to_lose);

    double weeks_to_lose_weight = weight_to_lose / 0.5; // assuming 0.5 kg/week weight loss
    printf("You need to maintain a calorie deficit of 500 calories/day to lose %.2f kg in %.2f weeks\n", weight_to_lose, weeks_to_lose_weight);

    return 0;
}