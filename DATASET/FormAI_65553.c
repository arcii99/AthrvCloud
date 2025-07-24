//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int current_year, target_year, age, target_age, time_travel, new_age;
    
    // Welcome message and current year prompt
    printf("Welcome to Time Travel Simulator!\n");
    printf("What is the current year?\n");
    scanf("%d", &current_year);
    
    // Age prompt
    printf("What is your current age?\n");
    scanf("%d", &age);
    
    // Target year prompt
    printf("What year would you like to travel to?\n");
    scanf("%d", &target_year);
    
    // Age at target year prompt
    printf("How old would you like to be in %d?\n", target_year);
    scanf("%d", &target_age);
    
    // Calculate time travel and new age
    time_travel = target_year - current_year;
    new_age = target_age - age;
    
    if (new_age >= 0) {
        printf("You need to wait %d years to time travel to %d.\n", time_travel, target_year);
        printf("You will be %d years old in %d.\n", target_age, target_year);
    } else {
        printf("You can time travel to %d now!\n", target_year);
        printf("You will be %d years old in %d.\n", target_age, target_year);
    }
    
    return 0;
}