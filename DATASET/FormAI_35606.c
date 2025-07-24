//FormAI DATASET v1.0 Category: Temperature monitor ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_TEMP 100
#define MIN_TEMP 0
#define WAIT_TIME 5

int main() {

    int celsius = 0;
    int alarm = 0;

    while (1) {
        printf("Enter current temperature in Celsius: \n");
        scanf("%d", &celsius);

        if (celsius > MAX_TEMP || celsius < MIN_TEMP) {
            printf("Invalid temperature entered.\n");
            continue;
        }

        if (celsius >= 80 && celsius <= 99) {
            printf("The temperature is normal. No action required.\n");
        } else if (celsius > 60 && celsius < 80) {
            printf("The temperature is too low. Please adjust.\n");
        } else if (celsius < 40 || celsius > 99) {
            printf("Warning! Temperature out of range.\n");
            alarm = 1;
        } else if (celsius >= 40 && celsius < 60) {
            printf("Warning! Temperature below recommended range.\n");
            alarm = 1;
        } else if (celsius >= 99) {
            printf("Warning! Temperature above recommended range.\n");
            alarm = 1;
        }

        if (alarm) {
            printf("Sending automatic email notification to HVAC technician.\n");
            //code to send email notification
            alarm = 0;
        }

        sleep(WAIT_TIME);
    }

    return 0;
}