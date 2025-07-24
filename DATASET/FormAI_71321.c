//FormAI DATASET v1.0 Category: Temperature monitor ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_TEMP 100 /* Maximum Temperature Value */
#define MIN_TEMP 0 /* Minimum Temperature Value */
#define MAX_THRESHOLD 80 /* Temperature Threshold limit */
#define WAIT_TIME 2 /* Time interval between each reading */

int main() {

    int current_temp;
    srand(time(NULL)); /* Seed for random generator */

    printf("Starting Temperature Monitor\n");

    while(1) { /* Infinite Loop */

        /* Generate random temperature between 0 and 100 */
        current_temp = (rand() % (MAX_TEMP - MIN_TEMP + 1)) + MIN_TEMP;

        /* Print current temperature */
        printf("\nCurrent Temperature: %dC\n", current_temp);

        /* Check if temperature exceeds threshold limit */
        if(current_temp > MAX_THRESHOLD) {
            printf("WARNING: Temperature Exceeds Threshold Limit!");
            /* Code to notify system administrator goes here */
        }

        /* Wait for a few seconds before taking next temperature reading */
        sleep(WAIT_TIME);
    }

    return 0;
}