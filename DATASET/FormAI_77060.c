//FormAI DATASET v1.0 Category: System event logger ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *fptr;
    fptr = fopen("system_log.txt", "a");
    if (fptr == NULL) {
        printf("Error opening file!");
        exit(1);
    }
    time_t current_time;
    char* c_time_string;

    current_time = time(NULL);
    c_time_string = ctime(&current_time);

    fprintf(fptr, "System event occurred at %s", c_time_string);

    fclose(fptr);
    return 0;
}