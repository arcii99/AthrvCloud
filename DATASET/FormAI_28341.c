//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fitness_tracker {
    char name[50];
    int age;
    float weight;
    float height;
    float bmi;
    int calories_burnt;
    int steps_walked;
};

void calculate_bmi(struct fitness_tracker* tracker) {
    float height_in_meters = tracker->height / 100;
    tracker->bmi = tracker->weight / (height_in_meters * height_in_meters);
}

void log_calories_burnt(struct fitness_tracker* tracker, int calories) {
    tracker->calories_burnt += calories;
}

void log_steps_walked(struct fitness_tracker* tracker, int steps) {
    tracker->steps_walked += steps;
}

void display_fitness_data(struct fitness_tracker* tracker) {
    printf("Name: %s\nAge: %d\nWeight: %.2f kg\nHeight: %.2f cm\nBMI: %.2f\nCalories Burnt: %d\nSteps Walked: %d\n", 
        tracker->name, tracker->age, tracker->weight, tracker->height, tracker->bmi, tracker->calories_burnt, tracker->steps_walked);
}

int main() {
    struct fitness_tracker user;
    user.age = 26;
    user.weight = 60.0;
    user.height = 170.0;
    strcpy(user.name, "John Doe");
    
    calculate_bmi(&user);
    display_fitness_data(&user);
    
    log_calories_burnt(&user, 500);
    log_steps_walked(&user, 1000);
    
    display_fitness_data(&user);

    return 0;
}