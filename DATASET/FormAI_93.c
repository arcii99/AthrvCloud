//FormAI DATASET v1.0 Category: Temperature monitor ; Style: accurate
#include<stdio.h>

int main() {
    float temp = 0;
    int count = 0;
    float sum = 0;
    float avg = 0;

    printf("Enter the number of temperature readings: ");
    scanf("%d", &count);

    /* Input the temperatures and calculate the average */
    for (int i = 1; i <= count; i++) {
        printf("Enter temperature reading %d: ", i);
        scanf("%f", &temp);
        sum += temp;
    }

    /* Calculates the average temperature of all readings */
    avg = sum / count;

    /* Display the average temperature */
    printf("The average temperature is %.2f degree Celsius.\n", avg);

    /* Checks temperature conditions */
    if (avg < 0) {
        printf("It's freezing!\n");
    } else if (avg >= 0 && avg < 10) {
        printf("It's very cold outside.\n");
    } else if (avg >= 10 && avg < 20) {
        printf("It's chilly outside.\n");
    } else if (avg >= 20 && avg < 30) {
        printf("It's warm outside.\n");
    } else if (avg >= 30) {
        printf("It's hot outside.\n");
    }

    return 0;
}