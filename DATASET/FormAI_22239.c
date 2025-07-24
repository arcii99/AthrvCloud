//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: puzzling
// Welcome to the Fitness Tracker!

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>

// Function to calculate body mass index
float bmi(float weight, float height) {
    float bmi;
    bmi = weight / pow(height, 2);
    return bmi;
}

// Function to convert inches to centimeters
float inch_to_cm(float inch) {
    float cm;
    cm = inch * 2.54;
    return cm;
}

// Function to convert pounds to kilograms
float lbs_to_kg(float lbs) {
    float kg;
    kg = lbs / 2.205;
    return kg;
}

int main() {
    float weight, height, goal_weight;
    int age, goal_time;
    char gender[6], activity_level[10], goal[10], response[10];

    printf("\nWelcome to the Fitness Tracker!");
    printf("\nPlease provide the following information to get started.");
    printf("\nWhat is your age? ");
    scanf("%d", &age);
    printf("\nWhat is your gender (male/female)? ");
    scanf("%s", gender);
    printf("\nWhat is your weight (lbs)? ");
    scanf("%f", &weight);
    printf("\nWhat is your height (inches)? ");
    scanf("%f", &height);
    printf("\nWhat is your activity level (sedentary, lightly active, moderately active, very active, extra active)? ");
    scanf("%s", activity_level);

    float cm = inch_to_cm(height);
    float kg = lbs_to_kg(weight);
    float bmi_value = bmi(kg, cm / 100);

    printf("\nYour BMI is %.2f\n", bmi_value);

    if(bmi_value < 18.5) {
        printf("You are underweight.\n");
    }
    else if(bmi_value >= 18.5 && bmi_value <= 24.9) {
        printf("You are in a healthy weight range.\n");
    }
    else if(bmi_value >= 25 && bmi_value <= 29.9) {
        printf("You are overweight.\n");
    }
    else {
        printf("You are obese.\n");
    }

    printf("\nWould you like to set a fitness goal? (yes/no) ");
    scanf("%s", response);

    if(strcmp(response, "yes") == 0) {
        printf("\nWhat is your goal (gain weight, lose weight, maintain weight)? ");
        scanf("%s", goal);

        if(strcmp(goal, "gain weight") == 0) {
            printf("\nHow much weight do you want to gain (lbs)? ");
            scanf("%f", &goal_weight);
            printf("\nIn how many weeks do you want to achieve this goal? ");
            scanf("%d", &goal_time);

            // Calculate the number of calories needed per day to achieve the goal
            float calories_needed = 7700 * goal_weight / goal_time;
            // Add 500 calories to the calculated calories needed to gain weight a little faster
            calories_needed += 500;

            printf("\nTo reach your goal of gaining %.2f lbs in %d weeks,", goal_weight, goal_time);
            printf("\nyou need to consume %.2f calories per day.\n", calories_needed);
        }
        else if(strcmp(goal, "lose weight") == 0) {
            printf("\nHow much weight do you want to lose (lbs)? ");
            scanf("%f", &goal_weight);
            printf("\nIn how many weeks do you want to achieve this goal? ");
            scanf("%d", &goal_time);

            // Calculate the number of calories needed per day to achieve the goal
            float calories_needed = 7700 * goal_weight / goal_time;
            // Subtract 500 calories from the calculated calories needed to lose weight a little faster
            calories_needed -= 500;

            printf("\nTo reach your goal of losing %.2f lbs in %d weeks,", goal_weight, goal_time);
            printf("\nyou need to consume %.2f calories per day.\n", calories_needed);
        }
        else if(strcmp(goal, "maintain weight") == 0) {
            printf("\nHow many calories do you want to consume per day? ");
            scanf("%f", &goal_weight);

            printf("\nTo maintain your current weight, you need to consume %.2f calories per day.\n", goal_weight);
        }
        else {
            printf("\nInvalid goal.\n");
        }
    }

    printf("\nThanks for using the Fitness Tracker!\n");

    return 0;
}