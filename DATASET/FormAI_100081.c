//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void delay(unsigned int mseconds) {
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main() {
    int year, month, day, hour;
    printf("Welcome to the Alien Invasion Probability Calculator!\n");
    delay(2000);

    printf("Please enter the current date and time:\n");
    printf("Year (yyyy): ");
    scanf("%d", &year);

    printf("Month (mm): ");
    scanf("%d", &month);

    printf("Day (dd): ");
    scanf("%d", &day);

    printf("Hour (00-23): ");
    scanf("%d", &hour);

    printf("Calculating probability...\n");
    delay(3000);

    srand(time(NULL));
    int probability = rand() % 101;
    printf("Probability of an alien invasion on %02d/%02d/%04d at %02d:00 is %d%%\n", month, day, year, hour, probability);
    delay(2000);

    if (probability > 75) {
        printf("WARNING: High risk of alien invasion in your area! Please take necessary precautions.\n");
    } else if (probability > 50) {
        printf("CAUTION: Moderate risk of alien invasion in your area. Please stay vigilant.\n");
    } else {
        printf("No immediate danger of an alien invasion in your area. Have a nice day!\n");
    }

    return 0;
}