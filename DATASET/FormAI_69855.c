//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: safe
#include <stdio.h>
#include <stdbool.h>

struct User
{
    char name[50];
    int age;
    float height;
    float weight;
};

struct Exercise
{
    char name[50];
    float duration;
    float calories_burned;
};

struct FitnessTracker
{
    struct User user;
    int num_exercises;
    struct Exercise exercises[10];
};

void display_user_info(struct User user)
{
    printf("\nUser Name: %s\n", user.name);
    printf("Age: %d\n", user.age);
    printf("Height: %.2f\n", user.height);
    printf("Weight: %.2f\n\n", user.weight);
}

void display_exercise_info(struct Exercise exercise)
{
    printf("\nExercise Name: %s\n", exercise.name);
    printf("Duration: %.2f minutes\n", exercise.duration);
    printf("Calories burned: %.2f\n\n", exercise.calories_burned);
}

void display_all_exercises(struct FitnessTracker tracker)
{
    printf("\nUser: %s\n", tracker.user.name);
    printf("Exercises completed: %d\n", tracker.num_exercises);

    for (int i = 0; i < tracker.num_exercises; i++)
    {
        display_exercise_info(tracker.exercises[i]);
    }
}

bool add_exercise(struct FitnessTracker *tracker, struct Exercise exercise)
{
    if (tracker->num_exercises >= 10)
    {
        printf("Cannot add more exercises to this user's fitness tracker.\n");
        return false;
    }
    else
    {
        tracker->exercises[tracker->num_exercises] = exercise;
        tracker->num_exercises++;
        printf("Successfully added exercise to %s's fitness tracker.\n", tracker->user.name);
        return true;
    }
}

void display_menu()
{
    printf("Please select an option:\n");
    printf("1. Display user information\n");
    printf("2. Display all exercise information\n");
    printf("3. Add an exercise\n");
    printf("4. Quit\n");
}

int main()
{
    struct User user = {"John Doe", 30, 180.5, 75.0};
    struct FitnessTracker tracker = {user, 0};

    bool quit = false;
    while (!quit)
    {
        display_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            display_user_info(user);
            break;
        case 2:
            display_all_exercises(tracker);
            break;
        case 3:
            struct Exercise exercise;
            printf("Enter exercise name: ");
            scanf("%s", exercise.name);
            printf("Enter duration (in minutes): ");
            scanf("%f", &exercise.duration);
            printf("Enter calories burned: ");
            scanf("%f", &exercise.calories_burned);

            add_exercise(&tracker, exercise);
            break;
        case 4:
            quit = true;
            break;
        default:
            printf("Invalid option, please try again.\n");
            break;
        }
    }

    return 0;
}