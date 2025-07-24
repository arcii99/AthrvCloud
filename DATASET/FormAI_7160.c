//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the user struct 
typedef struct {
    char name[50];
    int age;
    float weight;
    float height;
} User;

// Function signatures 
float calculateBMI(User user);
void printUserInfo(User user);
void addFitnessData(User* user, float weight, float height);

// Main function 
int main() {

    // Declare and initialize the user 
    User user1 = {"John", 30, 80.0, 1.75};
    
    // Print the user's information 
    printUserInfo(user1);
    
    // Add fitness data to the user 
    addFitnessData(&user1, 78.0, 1.75);
    addFitnessData(&user1, 76.0, 1.76);
    addFitnessData(&user1, 75.5, 1.78);
    addFitnessData(&user1, 74.0, 1.77);
    addFitnessData(&user1, 73.5, 1.79);
    
    // Print the updated user's information 
    printUserInfo(user1);
    
    return 0;
}

// Function to calculate the user's BMI 
float calculateBMI(User user) {
    return user.weight / (user.height * user.height);
}

// Function to print the user's information 
void printUserInfo(User user) {
    printf("Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Weight: %.2f kg\n", user.weight);
    printf("Height: %.2f m\n", user.height);
    printf("BMI: %.2f\n\n", calculateBMI(user));
}

// Function to add fitness data to the user 
void addFitnessData(User* user, float weight, float height) {
    user->weight = weight;
    user->height = height;
}