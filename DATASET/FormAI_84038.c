//FormAI DATASET v1.0 Category: Smart home automation ; Style: unmistakable
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

int main() {
    int temperature = 0;
    int currentMonth = 0;
    bool isSummer = false;
    bool isWinter = false;
    time_t currentTime;
    struct tm* timeInfo;
    
    time(&currentTime);
    timeInfo = localtime(&currentTime);
    currentMonth = timeInfo->tm_mon + 1;

    if (currentMonth >= 6 && currentMonth <= 8) {
        isSummer = true;
    } else if (currentMonth >= 12 || currentMonth <= 2) {
        isWinter = true;
    }

    if (isSummer) {
        temperature = 20; // Set summer temperature to 20 degrees Celsius
        printf("Smart home system: It's summer! Setting temperature to %dC.\n", temperature);
    } else if (isWinter) {
        temperature = 25; // Set winter temperature to 25 degrees Celsius
        printf("Smart home system: It's winter! Setting temperature to %dC.\n", temperature);
    } else {
        temperature = 22; // Set default temperature to 22 degrees Celsius
        printf("Smart home system: It's not summer or winter. Setting temperature to %dC.\n", temperature);
    }

    return 0;
}