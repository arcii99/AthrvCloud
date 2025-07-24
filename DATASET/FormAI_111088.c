//FormAI DATASET v1.0 Category: Log analysis ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    char log_file[] = "example.log"; // Change this to your log file location
    
    FILE *file = fopen(log_file, "r");
    
    if(file == NULL)
    {
        printf("ERROR: Unable to open file: %s\n", log_file);
        return 1;
    }
    
    printf("Analyzing log file: %s\n\n", log_file);
    
    char line[1024];
    int total_lines = 0;
    int invalid_lines = 0;
    int successful_requests = 0;
    int failed_requests = 0;
    
    while(fgets(line, 1024, file))
    {
        total_lines++;
        
        if(line[0] != '[')
        {
            printf("Invalid log format (does not start with [): %s\n", line);
            invalid_lines++;
        }
        else
        {
            int status_code = -1;
            sscanf(line, "[%*[^]]] %*s %d", &status_code);
            
            if(status_code <= 0)
            {
                printf("Invalid HTTP status code: %s\n", line);
                invalid_lines++;
            }
            else if(status_code >= 400 && status_code <= 499)
            {
                printf("FAILED REQUEST: %s", line);
                failed_requests++;
            }
            else if(status_code >= 200 && status_code <= 299)
            {
                successful_requests++;
            }
            else
            {
                printf("Unknown HTTP status code: %s\n", line);
                invalid_lines++;
            }
        }
    }
    
    fclose(file);
    
    printf("\nSUMMARY\n");
    printf("-------\n");
    printf("Total lines: %d\n", total_lines);
    printf("Invalid lines: %d\n", invalid_lines);
    printf("Successful requests: %d\n", successful_requests);
    printf("Failed requests: %d\n", failed_requests);
    
    return 0;
}