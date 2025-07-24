//FormAI DATASET v1.0 Category: Temperature monitor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int temp, minTemp = 100, maxTemp = 0;
    int count = 1, sum = 0;
    float avgTemp;

    printf("Welcome to the Medieval Temperature Monitor!\n\n");
    printf("Please enter temperatures to monitor, or -999 to quit:\n");

    do {
        printf("\nTemperature reading %d: ", count);
        scanf("%d", &temp);

        if(temp == -999)
            break;

        if(temp < -50 || temp > 50) {
            printf("Invalid temperature! Please enter a value between -50 and 50.\n");
            continue;
        }

        sum += temp;

        if(temp < minTemp)
            minTemp = temp;

        if(temp > maxTemp)
            maxTemp = temp;

        avgTemp = (float) sum / count;

        printf("Current temperature: %d | Min temperature: %d | Max temperature: %d | Avg temperature: %.2f\n", temp, minTemp, maxTemp, avgTemp);

        count++;
    } while(1);

    printf("\n\nThank you for using the Medieval Temperature Monitor!");

    return 0;
}