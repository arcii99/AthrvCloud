//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    printf("Welcome to the CPU Usage Monitor Program!!\n");
    printf("This program helps you monitor the CPU usage on your computer with a Happy twist!\n");

    int cpuUsage[10];
    int totalUsage = 0;
    int maxValue = 0;
    int minValue = 100;
    int modeValue = 0;
    int modeFreq = 0;
    int i = 0;

    for (i = 0; i < 10; i++) {
        cpuUsage[i] = rand() % 101;
        totalUsage += cpuUsage[i];

        // Find max, min and mode in the array
        if (cpuUsage[i] > maxValue) {
            maxValue = cpuUsage[i];
        }

        if (cpuUsage[i] < minValue) {
            minValue = cpuUsage[i];
        }

        int frequency = 0;
        int j = 0;

        for (j = 0; j < 10; j++) {
            if (cpuUsage[i] == cpuUsage[j]) {
                frequency++;
            }
        }

        if (frequency > modeFreq) {
            modeFreq = frequency;
            modeValue = cpuUsage[i];
        }
    }

    // Calculate the average CPU usage
    float avgUsage = (float)totalUsage / 10.0;

    printf("Your CPU usage for the last 10 minutes is:\n");

    for (i = 0; i < 10; i++) {
        printf("%d%%, ", cpuUsage[i]);
    }

    printf("\n");
    printf("The average CPU usage is: %.2f%%\n", avgUsage);
    printf("The maximum CPU usage is: %d%%\n", maxValue);
    printf("The minimum CPU usage is: %d%%\n", minValue);
    printf("The most common CPU usage is: %d%%, which appeared %d times.\n", modeValue, modeFreq);

    if (avgUsage <= 30) {
        printf("That's great! Your CPU usage is low and you're saving energy.\n");
    }
    else if (avgUsage > 30 && avgUsage <= 60) {
        printf("Good job! Your CPU usage is moderate, keep up the good work.\n");
    }
    else {
        printf("Uh oh, your CPU usage is high. Consider closing some applications or processes to reduce it.\n");
    }

    return 0;
}