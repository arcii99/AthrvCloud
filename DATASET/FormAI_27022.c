//FormAI DATASET v1.0 Category: Temperature monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int temp, sum = 0, count = 0;
    float average;
    char choice;

    printf("Welcome to the Temperature Monitor!\n");

    do {
        time_t current_time;
        struct tm* time_info;
        char time_string[9];

        time(&current_time);
        time_info = localtime(&current_time);

        strftime(time_string, sizeof(time_string), "%H:%M:%S", time_info);

        printf("\nEnter the current temperature: ");
        scanf("%d", &temp);

        sum += temp;
        count++;
        average = (float)sum / count;

        printf("Temperature recorded at %s is %d Celsius\n", time_string, temp);
        printf("The average temperature is %.2f Celsius\n", average);

        printf("\nDo you want to record another temperature? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using Temperature Monitor!");
    return 0;
}