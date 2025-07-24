//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int prob, day;
    srand(time(0)); // initialize random seed
    
    printf("Welcome to the Alien Invasion Probability Calculator!\n\n");
    printf("What is the current day of the week? (1 = Monday, 7 = Sunday):\n");
    scanf("%d", &day);
    
    // calculate probability based on day of the week
    switch(day) {
        case 1: prob = rand() % 10 + 1; break; // Monday
        case 2: prob = rand() % 20 + 1; break; // Tuesday
        case 3: prob = rand() % 30 + 1; break; // Wednesday
        case 4: prob = rand() % 40 + 1; break; // Thursday
        case 5: prob = rand() % 50 + 1; break; // Friday
        case 6: prob = rand() % 75 + 1; break; // Saturday
        case 7: prob = rand() % 100 + 1; break; // Sunday
        default: prob = 0;
    }
    
    printf("\nCalculating probability...\n\n");
    printf("The probability of an alien invasion today is: %d%%\n", prob);
    
    return 0;
}