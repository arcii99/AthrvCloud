//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define MAX_EXERCISE_NAME_LENGTH 50
#define MAX_HISTORY_ENTRIES 1000

// Exercise struct to represent each exercise
typedef struct {
    char name[MAX_EXERCISE_NAME_LENGTH];
    int calories_per_hour;
} exercise_t;

// History struct to represent each entry in the user's workout history
typedef struct {
    time_t timestamp;
    int duration_in_minutes;
    int calories_burned;
} history_entry_t;

// Global variables
exercise_t exercises[3] = {{"Running", 600}, {"Weight Lifting", 400}, {"Yoga", 200}};
history_entry_t history[MAX_HISTORY_ENTRIES];
int num_history_entries = 0;
pthread_mutex_t history_lock = PTHREAD_MUTEX_INITIALIZER;

// Function to add an entry to the user's workout history
void add_history_entry(int exercise_idx, int duration_in_minutes) {
    pthread_mutex_lock(&history_lock);
    
    time_t now;
    time(&now);
    
    int calories_burned = exercises[exercise_idx].calories_per_hour * duration_in_minutes / 60;
    history_entry_t new_entry = {now, duration_in_minutes, calories_burned};
    
    history[num_history_entries++] = new_entry;
    
    pthread_mutex_unlock(&history_lock);
}

// Function to calculate the user's total calories burned for a given day
int calculate_calories_burned_for_day(time_t day) {
    int total_calories = 0;
    
    pthread_mutex_lock(&history_lock);
    
    for (int i = 0; i < num_history_entries; i++) {
        if (history[i].timestamp >= day && history[i].timestamp < day + 24*60*60) {  // Check if entry is for the given day
            total_calories += history[i].calories_burned;
        }
    }
    
    pthread_mutex_unlock(&history_lock);
    
    return total_calories;
}

// Asynchronous function to print the user's total calories burned for the current day every 5 seconds
void* print_calories_burned(void* arg) {
    time_t current_day = time(NULL) / (24*60*60) * (24*60*60);  // Get start of current day
    
    while (true) {
        int calories_burned = calculate_calories_burned_for_day(current_day);
        
        printf("Total calories burned for day starting at %s: %d\n", ctime(&current_day), calories_burned);
        
        sleep(5);
    }
    
    return NULL;
}

int main() {
    // Start print_calories_burned thread
    pthread_t print_calories_thread;
    pthread_create(&print_calories_thread, NULL, print_calories_burned, NULL);
    
    // Main loop to prompt user for exercises and durations
    while (true) {
        char input[MAX_EXERCISE_NAME_LENGTH];
        printf("Enter an exercise (Running, Weight Lifting, or Yoga), or q to quit: ");
        fgets(input, MAX_EXERCISE_NAME_LENGTH, stdin);
        input[strcspn(input, "\n")] = 0;  // Remove trailing newline from input
        
        if (strcmp(input, "q") == 0) {
            break;
        }
        
        int exercise_idx = -1;
        for (int i = 0; i < 3; i++) {
            if (strcmp(input, exercises[i].name) == 0) {
                exercise_idx = i;
                break;
            }
        }
        
        if (exercise_idx == -1) {
            printf("Invalid exercise!\n");
            continue;
        }
        
        int duration_in_minutes;
        printf("Enter duration (in minutes): ");
        scanf("%d", &duration_in_minutes);
        getchar();  // Get rid of newline character left in buffer from scanf
        
        add_history_entry(exercise_idx, duration_in_minutes);
    }
    
    // Wait for print_calories_burned thread to finish before exiting program
    pthread_join(print_calories_thread, NULL);
    
    return 0;
}