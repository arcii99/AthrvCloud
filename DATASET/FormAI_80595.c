//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: portable
#include<stdio.h>
#include<stdlib.h>

#define MAX_ENTRIES 100 // Max number of entries that can be stored 

struct Entry {
    float weight;
    float height;
    float bmi;
};

struct FitnessTracker {
    char name[50];
    int age;
    struct Entry entries[MAX_ENTRIES];
    int count;
};

// function to calculate BMI
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

// function to add new entry to fitness tracker
void addEntry(struct FitnessTracker *tracker, float weight, float height) {
    struct Entry new_entry;
    new_entry.weight = weight;
    new_entry.height = height;
    new_entry.bmi = calculateBMI(weight, height);

    tracker->entries[tracker->count] = new_entry;
    tracker->count++;
}

// function to display all entries in fitness tracker
void displayEntries(struct FitnessTracker tracker) {
    printf("\nName: %s\nAge: %d\n", tracker.name, tracker.age);
    printf("Weight\tHeight\tBMI\n");
    for(int i=0; i<tracker.count; i++) {
        printf("%.2f\t%.2f\t%.2f\n", tracker.entries[i].weight, tracker.entries[i].height, tracker.entries[i].bmi);
    }
    printf("\n");
}

int main() {
    // create a new fitness tracker
    struct FitnessTracker my_tracker;
    my_tracker.count = 0;

    // add few entries to the tracker
    addEntry(&my_tracker, 75.0, 1.75);
    addEntry(&my_tracker, 85.0, 1.80);
    addEntry(&my_tracker, 70.0, 1.65);

    // display all entries in the tracker
    displayEntries(my_tracker);

    return 0;
}