//FormAI DATASET v1.0 Category: Log analysis ; Style: Cryptic
#include <stdio.h>

int main() {
    FILE *log; /* log file */
    char *line = NULL; /* variable to store the current line being read */
    size_t len = 0; /* length of the current line */
    ssize_t read; /* number of characters read in the current line */
    int count = 0; /* counter for the number of lines read */
    
    log = fopen("/var/log/system.log", "r"); /* open the system log file for reading */

    if (log == NULL) { /* error handling if log file cannot be opened */
        printf("Could not open system log file.");
        return 1; /* exit program with error code */
    }

    printf("Reading system log...\n");

    while ((read = getline(&line, &len, log)) != -1) { /* start reading the log file line by line */
        if (strstr(line, "error")) { /* if the current line contains the word "error", print it out */
            printf("Error found in log: %s", line);
            count++; /* increment the error counter */
        }
    }

    printf("Finished reading system log. Found %d errors.", count);

    fclose(log); /* close the log file */

    return 0;
}