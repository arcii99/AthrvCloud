//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: energetic
#include <stdio.h>

// Define the size of our arrays
#define MAX_ENTRIES 10

// Define the structure for our entry
typedef struct {
    int date;
    int steps;
    float weight;
} entry_t;

// Define the structure for our tracker
typedef struct {
    char name[50];
    entry_t entries[MAX_ENTRIES];
    int num_entries;
} tracker_t;

int main() {
    // Initialize our tracker
    tracker_t my_tracker;
    strcpy(my_tracker.name, "My Fitness Tracker");
    my_tracker.num_entries = 0;

    // Define our menu options
    int option = 0;
    do {
        printf("Welcome to %s\n", my_tracker.name);
        printf("Please choose an option:\n");
        printf("1 - Add Entry\n");
        printf("2 - View Entries\n");
        printf("3 - Exit\n");
        scanf("%d", &option);

        switch(option) {
            case 1:
                // Add an entry
                if (my_tracker.num_entries < MAX_ENTRIES) {
                    entry_t new_entry;
                    printf("Enter the date in YYYYMMDD format: ");
                    scanf("%d", &new_entry.date);
                    printf("Enter the number of steps: ");
                    scanf("%d", &new_entry.steps);
                    printf("Enter your weight in kilograms: ");
                    scanf("%f", &new_entry.weight);
                    my_tracker.entries[my_tracker.num_entries] = new_entry;
                    my_tracker.num_entries++;
                    printf("Entry added successfully.\n");
                } else {
                    printf("You have reached the maximum number of entries.\n");
                }
                break;
            case 2:
                // View entries
                printf("Date\t\tSteps\tWeight\n");
                for (int i = 0; i < my_tracker.num_entries; i++) {
                    printf("%08d\t%d\t%.2f\n", my_tracker.entries[i].date, my_tracker.entries[i].steps, my_tracker.entries[i].weight);
                }
                break;
            case 3:
                // Exit program
                printf("Thanks for using %s. Goodbye!\n", my_tracker.name);
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }
    } while(option != 3);

    return 0;
}