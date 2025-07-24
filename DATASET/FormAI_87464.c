//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct exercise {
    char name[50];
    int sets;
    int reps;
};

struct workout {
    char date[15];
    struct exercise exercises[10];
};

struct fitness_tracker {
    struct workout workouts[365];
};

// function to add a new workout to the tracker
void add_workout(struct fitness_tracker *tracker, char date[15], struct exercise exercises[10]) {
    int index;

    // find the first empty slot in the tracker
    for (int i = 0; i < 365; i++) {
        if (tracker->workouts[i].date[0] == '\0') {
            index = i;
            break;
        }
    }

    // copy the date and exercises into the new workout
    for (int i = 0; i < 15; i++) {
        tracker->workouts[index].date[i] = date[i];
    }
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 50; j++) {
            tracker->workouts[index].exercises[i].name[j] = exercises[i].name[j];
        }
        tracker->workouts[index].exercises[i].sets = exercises[i].sets;
        tracker->workouts[index].exercises[i].reps = exercises[i].reps;
    }
}

// function to print a workout
void print_workout(struct workout workout) {
    printf("%s: \n", workout.date);
    for (int i = 0; i < 10; i++) {
        if (workout.exercises[i].name[0] == '\0') {
            break;
        }
        printf("%s - %d sets of %d reps\n", workout.exercises[i].name, workout.exercises[i].sets, workout.exercises[i].reps);
    }
}

// function to print all workouts in a tracker
void print_tracker(struct fitness_tracker *tracker) {
    for (int i = 0; i < 365; i++) {
        if (tracker->workouts[i].date[0] != '\0') {
            print_workout(tracker->workouts[i]);
        }
    }
}

int main() {
    struct fitness_tracker tracker;

    // add some example workouts
    struct exercise workout1_exercises[10] = {
        {"Pushups", 3, 10},
        {"Squats", 3, 12},
        {"Lunges", 3, 12},
        {"Bench press", 3, 8},
        {"Leg press", 3, 10},
        {"Deadlifts", 3, 8},
        {"Situps", 3, 15},
        {"Planks", 3, 30},
        {"Lat pulldowns", 3, 10},
        {"Shoulder press", 3, 8},
    };
    add_workout(&tracker, "2022-05-01", workout1_exercises);

    struct exercise workout2_exercises[10] = {
        {"Bicep curls", 4, 10},
        {"Tricep extensions", 4, 12},
        {"Chest flys", 3, 10},
        {"Leg curls", 3, 12},
        {"Leg extensions", 3, 12},
        {"Calf raises", 3, 15},
        {"Hanging leg raises", 3, 12},
        {"Bent over rows", 3, 10},
        {"Shoulder flys", 3, 12},
    };
    add_workout(&tracker, "2022-05-02", workout2_exercises);

    struct exercise workout3_exercises[10] = {
        {"Pushups", 4, 15},
        {"Lunges", 4, 10},
        {"Bench press", 3, 10},
        {"Leg press", 3, 12},
        {"Deadlifts", 3, 8},
        {"Situps", 3, 20},
        {"Planks", 3, 45},
        {"Lat pulldowns", 3, 12},
        {"Shoulder press", 3, 10},
    };
    add_workout(&tracker, "2022-05-03", workout3_exercises);

    // print all the workouts in the tracker
    print_tracker(&tracker);

    return 0;
}