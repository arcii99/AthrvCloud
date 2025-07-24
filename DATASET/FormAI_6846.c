//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORKOUTS 10
#define MAX_EXERCISES 5

typedef struct {
    char name[20];
    int reps;
    int sets;
    int weight;
} Exercise;

typedef struct {
    char date[12];
    Exercise exercises[MAX_EXERCISES];
    int numExercises;
} Workout;

typedef struct {
    char name[30];
    Workout workouts[MAX_WORKOUTS];
    int numWorkouts;
    int totalWeightLifted;
} User;

void addExercise(User* u, int workoutIndex) {
    Exercise exercise;
    printf("\nExercise Name: ");
    scanf("%s", exercise.name);
    printf("Repetitions: ");
    scanf("%d", &exercise.reps);
    printf("Sets: ");
    scanf("%d", &exercise.sets);
    printf("Weight (lbs): ");
    scanf("%d", &exercise.weight);

    u->workouts[workoutIndex].exercises[u->workouts[workoutIndex].numExercises++] = exercise;
}

void addWorkout(User* u) {
    Workout workout;
    printf("\nWorkout Date (mm/dd/yyyy): ");
    scanf("%s", workout.date);

    char addMoreExercises = 'y';
    while (addMoreExercises == 'y' && workout.numExercises < MAX_EXERCISES) {
        addExercise(u, u->numWorkouts);
        printf("\nAdd another exercise? (y/n): ");
        scanf(" %c", &addMoreExercises);
    }

    u->workouts[u->numWorkouts++] = workout;
}

void removeWorkout(User* u) {
    int workoutIndex;
    printf("\nEnter the index of the workout you would like to remove: ");
    scanf("%d", &workoutIndex);

    u->numWorkouts--;
    u->totalWeightLifted -= getTotalWeightLiftedInWorkout(&u->workouts[workoutIndex]);

    for (int i = workoutIndex; i < u->numWorkouts; i++) {
        u->workouts[i] = u->workouts[i + 1];
    }
}

int getTotalWeightLiftedInWorkout(Workout* w) {
    int totalWeightLifted = 0;
    for (int i = 0; i < w->numExercises; i++) {
        totalWeightLifted += w->exercises[i].sets * w->exercises[i].reps * w->exercises[i].weight;
    }
    return totalWeightLifted;
}

void displayWorkouts(User* u) {
    printf("\nWorkouts:\n");
    for (int i = 0; i < u->numWorkouts; i++) {
        printf("\n%d. Date: %s\n", i, u->workouts[i].date);
        printf("Exercises:\n");
        for (int j = 0; j < u->workouts[i].numExercises; j++) {
            printf("%d. %s\n", j + 1, u->workouts[i].exercises[j].name);
            printf("Reps: %d, Sets: %d, Weight: %dlbs\n", u->workouts[i].exercises[j].reps,
                   u->workouts[i].exercises[j].sets, u->workouts[i].exercises[j].weight);
        }
        printf("Total weight lifted: %dlbs\n", getTotalWeightLiftedInWorkout(&u->workouts[i]));
    }
}

void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Add Workout\n");
    printf("2. Remove Workout\n");
    printf("3. Display Workouts\n");
    printf("4. Exit\n");
}

void loadUser(User* u) {
    // TODO: Load user data from file
}

void saveUser(User* u) {
    // TODO: Save user data to file
}

int main() {
    User user;
    user.totalWeightLifted = 0;
    user.numWorkouts = 0;

    srand(time(0));
    int randomWorkoutIndex = rand() % 3;
    char* randomWorkoutDates[3] = {"02/21/2022", "02/22/2022", "02/23/2022"};
    Workout randomWorkouts[3];
    Exercise randomExercises[4] = {
        {"Bench Press", 8, 3, 135},
        {"Squats", 10, 4, 185},
        {"Deadlifts", 6, 3, 225},
        {"Pullups", 10, 3, 0}
    };

    for (int i = 0; i < 3; i++) {
        randomWorkouts[i].numExercises = 4;
        for (int j = 0; j < 4; j++) {
            randomWorkouts[i].exercises[j] = randomExercises[j];
        }
        strcpy(randomWorkouts[i].date, randomWorkoutDates[i]);
        user.workouts[i] = randomWorkouts[i];
    }
    user.numWorkouts = 3;
    user.totalWeightLifted = getTotalWeightLiftedInWorkout(&randomWorkouts[randomWorkoutIndex]);

    int menuChoice;
    do {
        displayMenu();
        printf("\nEnter your choice: ");
        scanf("%d", &menuChoice);
        switch (menuChoice) {
            case 1:
                addWorkout(&user);
                user.totalWeightLifted += getTotalWeightLiftedInWorkout(&user.workouts[user.numWorkouts - 1]);
                break;
            case 2:
                removeWorkout(&user);
                break;
            case 3:
                displayWorkouts(&user);
                break;
            case 4:
                saveUser(&user);
                printf("\nGoodbye!\n");
                exit(0);
            default:
                printf("\nInvalid input, please try again.\n");
        }
    } while (menuChoice != 4);

    return 0;
}