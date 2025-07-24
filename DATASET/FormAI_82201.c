//FormAI DATASET v1.0 Category: Log analysis ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("\n\nOMG! You won't believe what I just found in this log file!");
    printf("\n\nIt looks like there has been a major security breach!\n\n");

    FILE *log_file = fopen("security_log.txt", "r");

    if (log_file == NULL)
    {
        printf("\n\nOh no, the file couldn't be opened!\n\n");
        return 1;
    }

    char line[100];

    int line_number = 0;
    int successful_logins = 0;
    int failed_logins = 0;
    int total_logins = 0;
    int unauthorized_access_attempts = 0;

    while (fgets(line, sizeof(line), log_file))
    {
        line_number++;

        if (strstr(line, "LOGIN SUCCESS"))
            successful_logins++;

        if (strstr(line, "LOGIN FAIL"))
            failed_logins++;

        if (strstr(line, "UNAUTHORIZED"))
            unauthorized_access_attempts++;

        total_logins = successful_logins + failed_logins;
    }

    printf("\n\nWow, things are worse than I thought...\n\n");

    if (total_logins == 0)
    {
        printf("No one has logged in yet. Either this system is completely new, or something is very wrong.\n\n");
    }
    else
    {
        float login_percentage = successful_logins / (float)total_logins * 100;
        printf("There have been %d total logins, with a success rate of %.2f%%.\n\n", total_logins, login_percentage);
    }

    if (unauthorized_access_attempts > 0)
    {
        printf("\n\nOh no! There have been %d unauthorized access attempts!\n\n", unauthorized_access_attempts);
    }
    else
    {
        printf("\n\nPhew, it looks like no one has tried to access the system without permission.\n\n");
    }

    fclose(log_file);

    return 0;
}