//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

//Structure to store user details
struct User {
    char name[50];
    int age;
    double height;
    double weight;
};

//Function to input user details
void inputUserDetails(struct User* user) {
    printf("Please enter your name: ");
    scanf("%s", user->name);
    printf("Please enter your age: ");
    scanf("%d", &user->age);
    printf("Please enter your height (in meters): ");
    scanf("%lf", &user->height);
    printf("Please enter your weight (in kg): ");
    scanf("%lf", &user->weight);
}

//Function to calculate BMI (Body Mass Index)
double calculateBMI(struct User user) {
    return user.weight / (user.height*user.height);
}

int main() {
    struct User user;
    inputUserDetails(&user);
    
    double BMI = calculateBMI(user);
    
    printf("%s, based on your height and weight, your BMI is %.2lf\n", user.name, BMI);
    
    //Checking for BMI categories
    if(BMI < 18.5) {
        printf("You are underweight. You should consider talking to a dietician and starting a weight gain program.\n");
    } else if(BMI < 25) {
        printf("Congratulations! You are in the normal weight range. Keep up the good work!\n");
    } else if(BMI < 30) {
        printf("You are overweight. You should consider talking to a dietician and starting a weight loss program.\n");
    } else {
        printf("You are obese. You should consider talking to a dietician and starting a weight loss program.\n");
    }
    
    return 0;
}