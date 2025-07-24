//FormAI DATASET v1.0 Category: Automated Fortune Teller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initialize random generator

    // Define arrays of possible fortunes
    const char fortune1[] = "Your future is looking bright.";
    const char fortune2[] = "The stars predict a successful year ahead.";
    const char fortune3[] = "Good news is on the horizon.";
    const char fortune4[] = "You will experience unexpected challenges, but will overcome them.";
    const char fortune5[] = "Take caution in decisions you make in the near future.";
    const char fortune6[] = "Your hard work will pay off soon.";
    const char fortune7[] = "A major life change is on the horizon.";
    const char fortune8[] = "Now is the time to take risks and leave your comfort zone.";

    // Generate a random number between 1 and 8
    int random_num = rand() % 8 + 1;

    // Use switch statement to print appropriate fortune
    switch (random_num) {
        case 1:
            printf("%s\n", fortune1);
            break;
        case 2:
            printf("%s\n", fortune2);
            break;
        case 3:
            printf("%s\n", fortune3);
            break;
        case 4:
            printf("%s\n", fortune4);
            break;
        case 5:
            printf("%s\n", fortune5);
            break;
        case 6:
            printf("%s\n", fortune6);
            break;
        case 7:
            printf("%s\n", fortune7);
            break;
        case 8:
            printf("%s\n", fortune8);
            break;
        default:
            printf("Error: Invalid number generated.");
            break;
    }

    return 0;
}