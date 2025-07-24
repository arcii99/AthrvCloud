//FormAI DATASET v1.0 Category: Temperature monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_TEMP 10
#define MAX_TEMP 100

int main() {
    int temp;
    char input[10];
    time_t now;

    while(1) {
        printf("Enter current temperature in Celsius or 'exit' to stop monitoring: ");
        fgets(input, 10, stdin);

        if(strcmp(input, "exit\n") == 0) {
            printf("Exiting temperature monitor...\n");
            break;
        }

        temp = atoi(input);

        if(temp < MIN_TEMP || temp > MAX_TEMP) {
            printf("Invalid input, temperature must be between %d and %d Celsius.\n", MIN_TEMP, MAX_TEMP);
            continue;
        }

        now = time(NULL);

        printf("Temperature at %s is %d Celsius.\n", ctime(&now), temp);
    }

    return 0;
}