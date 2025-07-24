//FormAI DATASET v1.0 Category: Weather simulation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Declare variables for temperature and conditions
    int temperature = 0;
    char conditions[10];

    // Set srand seed as current time
    srand(time(NULL));

    // Generate random temperature and corresponding condition
    temperature = rand() % 51 + 50; // Temperature between 50 and 100 degrees Fahrenheit
    int condition_num = rand() % 5; // Number between 0 and 4
    switch (condition_num) {
        case 0:
            strcpy(conditions, "sunny");
            break;
        case 1:
            strcpy(conditions, "cloudy");
            break;
        case 2:
            strcpy(conditions, "rainy");
            break;
        case 3:
            strcpy(conditions, "stormy");
            break;
        case 4:
            strcpy(conditions, "snowy");
            break;
    }

    // Print out the temperature and conditions
    printf("The temperature is a delightful %d degrees Fahrenheit and it's %s outside!\n", temperature, conditions);

    return 0;
}