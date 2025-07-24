//FormAI DATASET v1.0 Category: Log analysis ; Style: cheerful
#include <stdio.h>

int main(){
    printf("Welcome to the cheerful C Log analysis example program!\n\n");
    
    // reading log file from a txt file
    FILE *log_file;
    char log_line[200];
    log_file = fopen("example_log.txt", "r");
    
    if (log_file == NULL) {
        printf("Oops, the log file cannot be opened!\n\n");
        return 1;
        
    } else {
        printf("The log file is successfully opened! Analyzing the logs now...\n\n");
    }
    
    int line_count = 0;
    int error_count = 0;
    while (fgets(log_line, 200, log_file)) {
        // increase the number of lines for each line read
        line_count++;
        
        // check if 'Error' exists in the log line
        if (strstr(log_line, "Error") != NULL) {
            printf("Oh no! An error is found in line %d: %s\n", line_count, log_line);
            
            // increase the number of errors found
            error_count++;
        }
    }
    
    if (error_count == 0) {
        printf("Great! No errors are found in the log file! :)\n");
    } else {
        printf("Uh-oh, there are %d errors found in the log file. Better take a look at them! :( \n", error_count);
    }
    
    // closing the file
    fclose(log_file);
    
    printf("\n");
    printf("That's all for the cheerful C Log analysis example program! Hope you have enjoyed it! :D\n");
    
    return 0;
}