//FormAI DATASET v1.0 Category: Log analysis ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 100

void analyze_logs(FILE* fp)
{
    char line[MAX_LINE_LENGTH];
    int total_requests = 0;
    int successful_requests = 0;
    int unsuccessful_requests = 0;
    int server_error_requests = 0;
    int client_error_requests = 0;
    
    while (fgets(line, MAX_LINE_LENGTH, fp))
    {
        total_requests++;
        char* status_code = strtok(line, " ");
        if (status_code != NULL)
        {
            int code = atoi(status_code);
            if (code >= 200 && code < 300) 
            {
                successful_requests++;
            }
            else if (code >= 400 && code < 500) 
            {
                client_error_requests++;
            }
            else if (code >= 500 && code < 600) 
            {
                server_error_requests++;
            }
            else 
            {
                unsuccessful_requests++;
            }
        }
    }
    
    printf("Total requests: %d\n", total_requests);
    printf("Successful requests: %d\n", successful_requests);
    printf("Unsuccessful requests: %d\n", unsuccessful_requests);
    printf("Client error requests: %d\n", client_error_requests);
    printf("Server error requests: %d\n", server_error_requests);
}

int main()
{
    FILE* fp = fopen("access.log", "r");
    if (fp != NULL)
    {
        analyze_logs(fp);
        fclose(fp);
    }
    else
    {
        fprintf(stderr, "Error opening log file");
        return 1;
    }
    
    return 0;
}