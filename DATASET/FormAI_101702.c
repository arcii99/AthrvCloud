//FormAI DATASET v1.0 Category: Temperature monitor ; Style: unmistakable
#include <stdio.h>

int main() {
    float temp;
    int count = 0;
    float total = 0;
    float average;

    printf("Welcome to the C Temperature Monitor Example Program\n");

    while (count < 10) {

        printf("Enter temperature reading %d: ", (count + 1));
        scanf("%f", &temp);

        if (temp < -273.15) {
            printf("Invalid temperature: temperature cannot be below -273.15°C\n");
            continue;
        }
        else {
            total += temp;
            count++;
        }
    }

    average = total / 10.0;
    printf("The average temperature reading is %.2f°C\n", average);

    if (average > 25) {
        printf("Warning: the average temperature is above 25°C\n");
    }
    else {
        printf("The temperature is within normal range.\n");
    }

    return 0;
}