//FormAI DATASET v1.0 Category: Log analysis ; Style: random
#include<stdio.h>
#include<string.h>

//function to count occurrences of a specific string
int countSubstring(char* string, char* substring) {
    int count = 0;
    char* pos = string;
    while((pos = strstr(pos, substring)) != NULL) {
        count++;
        pos += strlen(substring);
    }
    return count;
}

int main() {
    FILE *log_file;
    log_file = fopen("example.log", "r");

    if(log_file == NULL) {
        printf("Error opening log file");
        return 1;
    }

    char line[256];
    int total_requests = 0, success_requests = 0, error_requests = 0, warning_requests = 0;

    // loop through log file line by line
    while(fgets(line, sizeof(line), log_file)) {
        // count total number of requests
        total_requests++;

        // check if request is successful or not
        if(strstr(line, "HTTP/1.1\" 200")) {
            success_requests++;
        } else if(strstr(line, "HTTP/1.1\" 4") || strstr(line, "HTTP/1.1\" 5")) {
            error_requests++;
            // check for specific error message
            if(strstr(line, "Connection timed out")) {
                printf("Error: Connection timed out\n");
            }
        } else if(strstr(line, "HTTP/1.1\" 3")) {
            warning_requests++;
            // check for specific warning message
            if(strstr(line, "Redirecting to")) {
                printf("Warning: Redirecting to new page\n");
            }
        }
    }

    // print log analysis report
    printf("Total Requests: %d\n", total_requests);
    printf("Successful Requests: %d\n", success_requests);
    printf("Error Requests: %d\n", error_requests);
    printf("Warning Requests: %d\n", warning_requests);

    // count number of occurrences of a specific string in log file
    char* searchTerm = "admin";
    fseek(log_file, 0L, SEEK_SET);
    int count = 0;
    while(fgets(line, sizeof(line), log_file)) {
        count += countSubstring(line, searchTerm);
    }
    printf("Number of times %s is mentioned in log file: %d\n", searchTerm, count);

    fclose(log_file);
    return 0;
}