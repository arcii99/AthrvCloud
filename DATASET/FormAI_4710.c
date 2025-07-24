//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed for random number generator
    int exercises_completed = 0;
    int calories_burned = 0;
    int heart_rate = 0;
    int steps_taken = 0;
    int sleep_hours = 0;
    int water_intake = 0;
    int meals_eaten = 0;

    while (1) { // infinite loop to simulate tracking throughout the day
        int paranoid_check = rand() % 10; // generates random number to simulate paranoid checking

        if (paranoid_check == 7) { // 10% chance of paranoid checking
            int choice = rand() % 7; // generates random number to simulate choice of tracking item

            switch(choice) {
                case 0:
                    printf("Exercises completed today: %d\n", exercises_completed);
                    break;
                case 1:
                    printf("Calories burned today: %d\n", calories_burned);
                    break;
                case 2:
                    printf("Heart rate: %d\n", heart_rate);
                    break;
                case 3:
                    printf("Steps taken today: %d\n", steps_taken);
                    break;
                case 4:
                    printf("Hours of sleep last night: %d\n", sleep_hours);
                    break;
                case 5:
                    printf("Water intake for today: %d\n", water_intake);
                    break;
                case 6:
                    printf("Meals eaten today: %d\n", meals_eaten);
                    break;
                default:
                    break;
            }
        }

        // simulated tracking
        exercises_completed += rand() % 2;
        calories_burned += rand() % 200;
        heart_rate = rand() % 100 + 60;
        steps_taken += rand() % 2000;
        sleep_hours = rand() % 9;
        water_intake += rand() % 16;
        meals_eaten += rand() % 4;

        // delay to simulate tracking throughout the day
        for (int i = 0; i < 100000000; i++) {}

        system("cls"); // clear screen for paranoid check
    }

    return 0;
}