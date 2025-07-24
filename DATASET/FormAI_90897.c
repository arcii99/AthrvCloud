//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    int steps;
    bool slept_enough; // true if user slept enough, false if not
    float weight;
} day;

void track(day *d) {
    // Prompt user to input information
    printf("How many steps did you take today? ");
    scanf("%d", &(*d).steps);
    printf("Did you sleep enough last night (Y/N)? ");
    char response;
    scanf(" %c", &response);
    (*d).slept_enough = (response == 'Y' || response == 'y');
    printf("What is your weight today (lbs)? ");
    scanf("%f", &(*d).weight);
    printf("\n");
}

void print_report(day *d) {
    // Print daily report
    printf("Daily Report:\n");
    printf("Steps taken: %d\n", (*d).steps);
    printf("Slept enough: %s\n", (*d).slept_enough ? "Yes" : "No");
    printf("Weight: %0.1f lbs\n\n", (*d).weight);
}

int main() {
    int days;
    printf("How many days would you like to track? ");
    scanf("%d", &days);

    day *tracker = malloc(days * sizeof(day)); // allocate memory

    for (int i = 0; i < days; i++) {
        printf("Day %d:\n", i + 1);
        track(&tracker[i]); // pass memory address of tracker[i]
        print_report(&tracker[i]);
    }

    free(tracker); // free allocated memory

    return 0;
}