//FormAI DATASET v1.0 Category: Fitness Tracker ; Style: romantic
#include <stdio.h>
#include <string.h>

int main() {
    const int MINUTES_IN_HOUR = 60;
    const int SECONDS_IN_MINUTE = 60;

    int minutes = 0;
    int seconds = 0;

    printf("Let's start tracking our fitness journey together, my love! \n\n");

    printf("Please enter the number of minutes you worked out today: ");
    scanf("%d", &minutes);

    printf("And how many seconds did you spend on exercise? ");
    scanf("%d", &seconds);

    int total_seconds = (minutes * MINUTES_IN_HOUR * SECONDS_IN_MINUTE) + (seconds);

    printf("\n\nYou've spent %d minutes and %d seconds on exercise today. That's amazing! \n", minutes, seconds);

    printf("Let me calculate your total workout time in seconds, hold my hand...\n");
    printf("...Converting to seconds...\n\n");
    printf("Your total workout time today is: %d seconds! \n\n", total_seconds);

    printf("I'm so proud of you for staying committed to our fitness goals together. Let's keep this up! \n");

    return 0;
}