//FormAI DATASET v1.0 Category: Temperature monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 50.0
#define MIN_TEMP -10.0

int main() {
    float curr_temp, avg_temp = 0.0;
    int temp_count = 0;
    char c;

    srand(time(NULL)); // seed the random number generator with the current time

    while (1) { // infinite loop to monitor temperature
        printf("Press 'q' to quit. Press any other key to continue. ");
        scanf("%c", &c);

        if (c == 'q' || c == 'Q') {
            break; // Exit loop if user enters 'q' or 'Q'
        }

        curr_temp = (float)rand()/(float)(RAND_MAX) * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;
        printf("Current temperature: %.2f\n", curr_temp);

        avg_temp = (avg_temp * (float)temp_count + curr_temp) / (float)(temp_count + 1);
        temp_count++;

        if (temp_count % 5 == 0) { // Calculate and print average temperature every 5 readings
            printf("Average temperature over last 5 readings: %.2f\n", avg_temp);
            avg_temp = 0.0;
            temp_count = 0;
        }
    }

    printf("Temperature monitor program terminated.\n");
    return 0;
}