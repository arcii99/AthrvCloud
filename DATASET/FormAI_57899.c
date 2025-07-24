//FormAI DATASET v1.0 Category: Temperature monitor ; Style: Dennis Ritchie
#include <stdio.h>

int main() {
    float temp[7], sum = 0, avg;

    printf("Enter temperature readings for the past 7 days:\n");

    for(int i = 0; i < 7; i++) {
        printf("Day %d: ", i+1);
        scanf("%f", &temp[i]);

        sum += temp[i];
    }

    avg = sum / 7.0;

    printf("\nTemperature Readings:\n");

    for(int i = 0; i < 7; i++) {
        printf("Day %d: %.2f C\n", i+1, temp[i]);
    }

    printf("\nAverage Temperature: %.2f C\n", avg);

    int above_avg = 0;
    int max_day = 0;
    float max_temp = temp[0];

    for(int i = 0; i < 7; i++) {
        if(temp[i] > avg) {
            above_avg++;
        }

        if(temp[i] > max_temp) {
            max_temp = temp[i];
            max_day = i+1;
        }
    }

    printf("\n%d days had above average temperature.", above_avg);
    printf("\nMaximum recorded temperature was %.2f C on Day %d.", max_temp, max_day);

    return 0;
}