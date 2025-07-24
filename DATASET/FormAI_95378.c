//FormAI DATASET v1.0 Category: Log analysis ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *file;
    char line[100];
    int num_of_lines = 0;
    int num_of_errors = 0;
    int num_of_warnings = 0;
    
    // Check if the file exists
    if ((file = fopen("log.txt", "r")) == NULL) {
        printf("Error opening file.\n");
        return 1;   
    }
    
    // Read each line of the file
    while (fgets(line, sizeof(line), file)) {
        num_of_lines++;
        
        // Count the number of errors
        if (strstr(line, "ERROR") != NULL) {
            num_of_errors++;
        }
        
        // Count the number of warnings
        if (strstr(line, "WARNING") != NULL) {
            num_of_warnings++;
        }
    }
    
    // Close the file
    fclose(file);
    
    // Print the results
    printf("Number of lines: %d\n", num_of_lines);
    printf("Number of errors: %d\n", num_of_errors);
    printf("Number of warnings: %d\n", num_of_warnings);
    
    return 0;
}