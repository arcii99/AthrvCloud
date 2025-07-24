//FormAI DATASET v1.0 Category: Temperature monitor ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

int main() {
    float temp;
    int numDays, validDays = 0;
    float totalTemp = 0;
    float avgTemp;
    printf("Enter the number of days to monitor: ");
    scanf("%d", &numDays);
    if (numDays < 1) {
        printf("Invalid number of days. Program Exiting..");
        exit(1);
    }
    printf("\n");
    //Loop to monitor temperature for each day
    for (int i = 1; i <= numDays; i++) {
        printf("Enter the temperature for Day %d: ", i);
        scanf("%f", &temp);
        if (temp >= -100.0 && temp <= 100.0) {
            validDays++;
            totalTemp += temp;
        } else {
            printf("Invalid temperature input. Try again for Day %d.\n\n", i);
            i--;
        }
    }
    avgTemp = totalTemp / validDays;
    printf("\nTemperature data for the past %d day(s):\n", numDays);
    printf("---------------------------------------------\n");
    printf("Day\tTemperature (C)\n");
    for (int i = 1; i <= numDays; i++) {
        printf("%d\t%.2f\n", i, temp);
    }
    printf("---------------------------------------------\n");
    printf("Average Temperature for the past %d day(s): %.2f\n", validDays, avgTemp);
    return 0;
}