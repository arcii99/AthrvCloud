//FormAI DATASET v1.0 Category: Time Travel Simulator ; Style: mathematical
#include <stdio.h>
#include <time.h>

#define YEAR 2021

int main() {
    int currentYear, targetYear, i;
    
    // Get current year
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    currentYear = t->tm_year + 1900;
    
    printf("Welcome to Time Travel Simulator!\n\n");
    
    // Get target year
    printf("Enter the year you want to travel to: ");
    scanf("%d", &targetYear);
    
    // Time travel simulation
    printf("Time travel engaged. Initiating simulation...\n\n");
    for (i = currentYear; i <= targetYear; i++) {
        printf("Year: %d\n", i);
        printf("Calculating time distortion...\n");
        if (i < YEAR) {
            printf("Time distortion factor: -%.2f%%\n", ((YEAR - i) * 100.0) / YEAR);
        } else if (i > YEAR) {
            printf("Time distortion factor: +%.2f%%\n", ((i - YEAR) * 100.0) / YEAR);
        } else {
            printf("No time distortion detected.\n");
        }
        printf("Time travel successful.\n\n");
    }
    
    printf("Simulation complete. Returning to present time...\n");
    
    return 0;
}