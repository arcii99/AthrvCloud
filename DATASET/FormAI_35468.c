//FormAI DATASET v1.0 Category: Temperature monitor ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TEMP 50.0 // maximum temperature limit
#define MIN_TEMP 0.0 // minimum temperature limit
#define TEMP_THRESHOLD 40.0 // temperature threshold
#define BUFFER_SIZE 1024 // buffer size for file read/write operations

int main() {
    float temperature;
    char tempStr[BUFFER_SIZE] = {0};
    FILE *tempFile = NULL;
    time_t currentTime;

    while (1) {
        // generate random temperature within the acceptable range
        temperature = (float) rand() / RAND_MAX * (MAX_TEMP - MIN_TEMP) + MIN_TEMP;

        // open the temperature file for writing 
        tempFile = fopen("temperature.txt", "w");
        if (tempFile == NULL) {
            printf("Error: could not open temperature file for writing\n");
            return -1;
        }

        // write the temperature to the file
        sprintf(tempStr, "%.2f", temperature);
        fwrite(tempStr, sizeof(char), strlen(tempStr), tempFile);

        // close the temperature file
        fclose(tempFile);

        // check if temperature exceeds the threshold
        if (temperature >= TEMP_THRESHOLD) {
            // log the time and temperature to the console
            time(&currentTime);
            printf("High temperature alert! %s: %.2f\n", ctime(&currentTime), temperature);
        }

        // sleep for 5 seconds
        sleep(5);
    }

    return 0;
}