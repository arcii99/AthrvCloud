//FormAI DATASET v1.0 Category: Log analysis ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>

int main() {
    char* filename = "logfile.txt";
    FILE* file = fopen(filename, "r");
    
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    char* line = NULL;
    size_t len = 0;
    ssize_t read;
    int numErrors = 0;
    int numSuccesses = 0;
    
    while ((read = getline(&line, &len, file)) != -1) {
        char* status = strtok(line, " ");
        char* message = strtok(NULL, "\n");
        
        if (strcmp(status, "Error") == 0) {
            numErrors++;
        }
        else {
            numSuccesses++;
        }
        
        if (strstr(message, "shape shift") != NULL) {
            if (strstr(message, "feline") != NULL) {
                printf("A feline shape shift was logged.\n");
            }
            else if (strstr(message, "canine") != NULL) {
                printf("A canine shape shift was logged.\n");
            }
            else {
                printf("A non-feline, non-canine shape shift was logged.\n");
            }
        }
    }
    
    fclose(file);
    if (line) free(line);
    
    printf("The log file contains %d errors and %d successes.\n", numErrors, numSuccesses);

    return 0;
}