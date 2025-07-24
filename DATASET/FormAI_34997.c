//FormAI DATASET v1.0 Category: Log analysis ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *log_file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int count_401 = 0, count_500 = 0, count_200 = 0;

    log_file = fopen("example_logs.log", "r");

    if (log_file == NULL)
    {
        perror("Error opening log file!");
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, log_file)) != -1)
    {
        char *status_code = strtok(line, " ");

        /* Count status codes */
        if (strcmp(status_code, "401") == 0)
            count_401++;
        else if (strcmp(status_code, "500") == 0)
            count_500++;
        else if (strcmp(status_code, "200") == 0)
            count_200++;
    }

    /* Print results */
    printf("Total 401 errors: %d\n", count_401);
    printf("Total 500 errors: %d\n", count_500);
    printf("Total successful requests: %d\n", count_200);

    /* Clean up */
    fclose(log_file);
    if (line)
        free(line);

    return 0;
}