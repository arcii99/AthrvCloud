//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Alan Touring
// Alan Turing Style C Temperature Monitor Example Program

#include <stdio.h>

int main() {
    int temp, previousTemp, minTemp, maxTemp, numOfReadings = 0;
    float avgTemp = 0.0;

    printf("Welcome to the Temperature Monitor!\n\n");

    do {
        printf("Enter the current temperature in Celsius: ");
        fflush(stdout);
        scanf("%d", &temp);

        if (numOfReadings == 0) {
            minTemp = temp;
            maxTemp = temp;
        } else {
            if (temp < minTemp) {
                minTemp = temp;
            }
            if (temp > maxTemp) {
                maxTemp = temp;
            }
        }

        avgTemp += temp;
        previousTemp = temp;
        numOfReadings++;

        printf("\nThe current temperature is %d C\n", temp);
        printf("The minimum temperature so far is %d C\n", minTemp);
        printf("The maximum temperature so far is %d C\n", maxTemp);
        printf("The average temperature so far is %.2f C\n\n", avgTemp / numOfReadings);

    } while (previousTemp != temp); // loop until a repeated temperature is entered

    printf("Thank you for using the Temperature Monitor! Goodbye.");

    return 0;
}