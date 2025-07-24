//FormAI DATASET v1.0 Category: Log analysis ; Style: high level of detail
#include <stdio.h>
#include <string.h>

#define MAX_LINE_LEN 1000
#define MAX_LOG_LINES 1000

int main()
{
    // Open the log file
    FILE *log_file = fopen("log.txt", "r");
    if(!log_file)
    {
        printf("Error: Could not open log.txt file!\n");
        return 1;
    }

    // Declare an array to store each line of the log file
    char log_lines[MAX_LOG_LINES][MAX_LINE_LEN];
    memset(log_lines, 0, sizeof(log_lines));

    // Read each line of the log file into the array
    char buffer[MAX_LINE_LEN];
    int current_line = 0;
    while(fgets(buffer, MAX_LINE_LEN, log_file))
    {
        strcpy(log_lines[current_line], buffer);
        current_line++;
    }

    // Close the log file
    fclose(log_file);

    // Search for a keyword in the log file and print all corresponding lines
    char keyword[] = "error";
    for(int i = 0; i < MAX_LOG_LINES; i++)
    {
        if(strstr(log_lines[i], keyword))
        {
            printf("%s", log_lines[i]);
        }
    }

    return 0;
}