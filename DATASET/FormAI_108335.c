//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function declarations
void printMainMenu();
void printExerciseMenu();
void addExercise(int id, char name[], char muscle[], int sets, int reps);
void removeExercise(int id);
void viewExercises();
void viewMuscleGroups();
void trackWorkout();

// Struct to hold exercise data
struct Exercise {
    int id;
    char name[50];
    char muscle_group[25];
    int sets;
    int reps;
} exercise;

// Arrays to hold exercise and muscle data
struct Exercise exercises[50];
char muscle_groups[10][25] = {"Chest", "Back", "Legs", "Arms", "Shoulders", "Abs", "Cardio", "Full Body", "Yoga", "Stretching"};

// Variable to keep track of number of exercises
int num_exercises = 0;

int main() {
    int choice;

    do {
        // Print main menu and get user choice
        printMainMenu();
        scanf("%d", &choice);

        // Determine which menu option to execute based on user choice
        switch(choice) {
            case 1:
                // Exercise menu
                printExerciseMenu();
                break;
            case 2:
                // View exercises
                viewExercises();
                break;
            case 3:
                // View muscle groups
                viewMuscleGroups();
                break;
            case 4:
                // Track workout
                trackWorkout();
                break;
            case 5:
                // Exit program
                printf("Exiting program...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);
}

// Function to print main menu options
void printMainMenu() {
    printf("Welcome to the C Fitness Tracker\n");
    printf("=================================\n");
    printf("1. Exercise Menu\n");
    printf("2. View Exercises\n");
    printf("3. View Muscle Groups\n");
    printf("4. Track Workout\n");
    printf("5. Exit Program\n");
    printf("Enter your choice: ");
}

// Function to print exercise menu options
void printExerciseMenu() {
    int choice;

    do {
        printf("Exercise Menu\n");
        printf("=============\n");
        printf("1. Add Exercise\n");
        printf("2. Remove Exercise\n");
        printf("3. Return to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Add exercise
                printf("Enter exercise name: ");
                scanf("%s", exercise.name);
                printf("Enter muscle group: ");
                scanf("%s", exercise.muscle_group);
                printf("Enter number of sets: ");
                scanf("%d", &exercise.sets);
                printf("Enter number of reps: ");
                scanf("%d", &exercise.reps);
                addExercise(num_exercises, exercise.name, exercise.muscle_group, exercise.sets, exercise.reps);
                num_exercises++;
                break;
            case 2:
                // Remove exercise
                int id;
                printf("Enter exercise ID to remove: ");
                scanf("%d", &id);
                removeExercise(id);
                break;
            case 3:
                // Return to main menu
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);
}

// Function to add exercise to array
void addExercise(int id, char name[], char muscle[], int sets, int reps) {
    struct Exercise new_exercise;
    new_exercise.id = id;
    strcpy(new_exercise.name, name);
    strcpy(new_exercise.muscle_group, muscle);
    new_exercise.sets = sets;
    new_exercise.reps = reps;
    exercises[num_exercises] = new_exercise;
    printf("Exercise added successfully.\n");
}

// Function to remove exercise from array
void removeExercise(int id) {
    for(int i = 0; i < num_exercises; i++) {
        if(exercises[i].id == id) {
            for(int j = i; j < num_exercises - 1; j++) {
                exercises[j] = exercises[j+1];
            }
            num_exercises--;
            printf("Exercise removed successfully.\n");
            return;
        }
    }
    printf("Exercise with ID %d not found.\n", id);
}

// Function to print all exercises in array
void viewExercises() {
    if(num_exercises == 0) {
        printf("No exercises added yet.\n");
        return;
    }
    printf("Exercise List\n");
    printf("=============\n");
    printf("%-5s %-25s %-15s %-5s %-5s\n", "ID", "Name", "Muscle Group", "Sets", "Reps");
    for(int i = 0; i < num_exercises; i++) {
        printf("%-5d %-25s %-15s %-5d %-5d\n", exercises[i].id, exercises[i].name, exercises[i].muscle_group, exercises[i].sets, exercises[i].reps);
    }
}

// Function to print all muscle groups
void viewMuscleGroups() {
    printf("Muscle Groups\n");
    printf("=============\n");
    for(int i = 0; i < 10; i++) {
        printf("%s\n", muscle_groups[i]);
    }
}

// Function to track a workout
void trackWorkout() {
    int num_exercises;
    printf("Enter number of exercises to track: ");
    scanf("%d", &num_exercises);
    int exercise_ids[num_exercises];
    for(int i = 0; i < num_exercises; i++) {
        printf("Enter exercise ID for exercise %d: ", i+1);
        scanf("%d", &exercise_ids[i]);
    }
    printf("Workout tracked successfully.\n");
}