//FormAI DATASET v1.0 Category: Text processing ; Style: mathematical
#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int count = 0;
    double numArray[100];

    printf("Enter a string of numbers separated by spaces: ");
    fgets(input, 100, stdin);

    // Split the input string into an array of numbers
    char *token = strtok(input, " ");
    while (token != NULL) {
        numArray[count] = atof(token);
        count++;
        token = strtok(NULL, " ");
    }

    double sum = 0.0;
    double min = numArray[0];
    double max = numArray[0];
    for (int i = 0; i < count; i++) {
        sum += numArray[i];
        if (numArray[i] < min) {
            min = numArray[i];
        }
        if (numArray[i] > max) {
            max = numArray[i];
        }
    }

    double mean = sum / count;

    double varSum = 0.0;
    for (int i = 0; i < count; i++) {
        varSum += (numArray[i] - mean) * (numArray[i] - mean);
    }
    double variance = varSum / count;

    double stdDev = sqrt(variance);

    printf("Count: %d\n", count);
    printf("Sum: %lf\n", sum);
    printf("Mean: %lf\n", mean);
    printf("Minimum: %lf\n", min);
    printf("Maximum: %lf\n", max);
    printf("Variance: %lf\n", variance);
    printf("Standard Deviation: %lf\n", stdDev);

    return 0;
}