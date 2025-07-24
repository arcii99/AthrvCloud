//FormAI DATASET v1.0 Category: Log analysis ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    printf("///////////////////////////////////////////////////////////////\n");
    printf("///            Welcome to the Mind-Bending Log Analysis      ///\n");
    printf("///////////////////////////////////////////////////////////////\n");

    // Create a file pointer and open the log file
    FILE *fp = fopen("log.txt", "r");

    // Check if the file was opened successfully
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Initialize variables to count log data
    int total = 0, errors = 0, warnings = 0, info = 0, debug = 0, critical = 0;
    char line[256];

    // Read the file line by line
    while (fgets(line, sizeof(line), fp)) {

        // Check the severity level of each log entry
        if (strstr(line, "ERROR") != NULL) {
            errors++;
        } else if (strstr(line, "WARNING") != NULL) {
            warnings++;
        } else if (strstr(line, "INFO") != NULL) {
            info++;
        } else if (strstr(line, "DEBUG") != NULL) {
            debug++;
        } else if (strstr(line, "CRITICAL") != NULL) {
            critical++;
        }

        total++; // Increment the total number of log entries
    }

    // Close the file
    fclose(fp);

    // Print out the results of the log analysis
    printf("Total number of log entries: %d\n", total);
    printf("Number of error entries: %d\n", errors);
    printf("Number of warning entries: %d\n", warnings);
    printf("Number of info entries: %d\n", info);
    printf("Number of debug entries: %d\n", debug);
    printf("Number of critical entries: %d\n", critical);

    // Calculate the percentage of each severity level
    double p_errors = ((double)errors / total) * 100;
    double p_warnings = ((double)warnings / total) * 100;
    double p_info = ((double)info / total) * 100;
    double p_debug = ((double)debug / total) * 100;
    double p_critical = ((double)critical / total) * 100;

    // Print out the percentage of each severity level
    printf("Percentage of error entries: %.2f%%\n", p_errors);
    printf("Percentage of warning entries: %.2f%%\n", p_warnings);
    printf("Percentage of info entries: %.2f%%\n", p_info);
    printf("Percentage of debug entries: %.2f%%\n", p_debug);
    printf("Percentage of critical entries: %.2f%%\n", p_critical);

    printf("\n///////////////////////////////////////////////////////////////\n");
    printf("///            Thank you for using our program!             ///\n");
    printf("///////////////////////////////////////////////////////////////\n");

    // End the program
    return 0;
}