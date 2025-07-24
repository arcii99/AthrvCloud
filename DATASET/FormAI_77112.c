//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: distributed
#include<stdio.h>

//Function to calculate Body Mass Index
float calculate_bmi(float weight, float height){
    return weight/(height*height);
}

//Function to calculate the calories burnt during exercise
float calculate_calories_burnt(float weight, float time){
    return weight*time*4.0;
}

//Main function that acts as Client
int main(){
    float weight;
    float height;
    float time;
    
    //Taking input from user
    printf("Enter your weight in kgs: ");
    scanf("%f", &weight);
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    printf("Enter the time spent on exercise in hours: ");
    scanf("%f", &time);
    
    //Calculating BMI
    float bmi = calculate_bmi(weight, height);
    printf("Your BMI is: %.2f\n", bmi);
    
    //Calculating Calories burnt
    float calories_burnt = calculate_calories_burnt(weight, time);
    printf("You have burnt %.2f calories during your exercise\n", calories_burnt);

    return 0;
}