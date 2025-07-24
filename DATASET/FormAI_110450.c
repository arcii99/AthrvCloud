//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int calories_burned_today = 0;
    int steps_today = 0;
    float distance_today = 0.0;

    // get current time and date
    time_t current_time = time(NULL);
    struct tm *tm_ptr = localtime(&current_time);
    printf("Welcome to your C Fitness Tracker!\n\n");
    printf("Today is %d/%d/%d\n\n", tm_ptr->tm_mon + 1, tm_ptr->tm_mday, tm_ptr->tm_year + 1900);

    int choice;

    do {
        printf("What would you like to do?\n\n");
        printf("1. Log your exercise for the day\n");
        printf("2. View your daily stats\n");
        printf("3. Exit\n\n");

        printf("Enter choice (1, 2, or 3): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // prompt user for exercise info
                int exercise_choice;
                printf("\nWhat did you do for exercise today?\n");
                printf("1. Running\n");
                printf("2. Biking\n");
                printf("3. Swimming\n");
                printf("4. Other\n\n");
                printf("Enter choice (1-4): ");
                scanf("%d", &exercise_choice);

                // prompt user for how long they exercised
                int exercise_time;
                printf("\nHow long did you exercise for (in minutes)? ");
                scanf("%d", &exercise_time);

                // calculate calories burned based on exercise and time
                int calories_burned;
                switch(exercise_choice) {
                    case 1:
                        // running burns about 10 calories per minute per 100 pounds of body weight
                        printf("\nHow much do you weigh (in pounds)? ");
                        float weight;
                        scanf("%f", &weight);
                        calories_burned = (int) (exercise_time * (10.0 * weight / 100.0));
                        break;
                    case 2:
                        // biking burns about 8 calories per minute per 100 pounds of body weight
                        printf("\nHow much do you weigh (in pounds)? ");
                        scanf("%f", &weight);
                        calories_burned = (int) (exercise_time * (8.0 * weight / 100.0));
                        break;
                    case 3:
                        // swimming burns about 12 calories per minute per 100 pounds of body weight
                        printf("\nHow much do you weigh (in pounds)? ");
                        scanf("%f", &weight);
                        calories_burned = (int) (exercise_time * (12.0 * weight / 100.0));
                        break;
                    default:
                        // assume other exercise burns about 7 calories per minute per 100 pounds of body weight
                        printf("\nHow much do you weigh (in pounds)? ");
                        scanf("%f", &weight);
                        calories_burned = (int) (exercise_time * (7.0 * weight / 100.0));
                }

                // update daily stats
                calories_burned_today += calories_burned;
                steps_today += (int) (exercise_time * 100.0 / 5.0);
                distance_today += (float) steps_today / 2000.0;

                printf("\nYou burned %d calories!\n\n", calories_burned);
                break;
            case 2:
                // display daily stats
                printf("\nToday's stats:\n");
                printf("Calories burned: %d\n", calories_burned_today);
                printf("Steps: %d\n", steps_today);
                printf("Distance: %.2f miles\n\n", distance_today);
                break;
            case 3:
                // exit program
                printf("\nThank you for using your C Fitness Tracker!\n");
                return 0;
            default:
                printf("\nInvalid option. Please try again.\n\n");
        }
    } while (choice != 3);

    return 0;
}