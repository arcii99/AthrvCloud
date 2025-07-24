//FormAI DATASET v1.0 Category: System event logger ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void logEvent(char* event) {
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);

    c_time_string = ctime(&current_time);

    printf("[%s]: %s\n", c_time_string, event);
}

int main() {
    logEvent("Program launched");

    int num1 = 5;
    int num2 = 10;
    int sum = num1 + num2;
    char eventString[50];

    sprintf(eventString, "The sum of %d and %d is %d", num1, num2, sum);
    logEvent(eventString);

    FILE* fptr;

    fptr = fopen("example.txt", "w");

    if (fptr == NULL) {
        logEvent("Failed to create file");
        return 1;
    }

    fprintf(fptr, "This is an example file.\n");

    logEvent("Created file: example.txt");

    fclose(fptr);

    logEvent("File closed");

    return 0;
}