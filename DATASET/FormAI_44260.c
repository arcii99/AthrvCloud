//FormAI DATASET v1.0 Category: Log analysis ; Style: genious
#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *file;
    char line[100];
    int count = 0;

    // Open Log file
    file = fopen("log.txt", "r");

    if (file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    printf("Number of Warning messages in the log file:\n");

    while (fgets(line, 100, file))
    {
        // Check for Warning messages
        if (strstr(line, "Warning") != NULL)
        {
            printf("%s", line);
            count++;
        }
    }

    printf("\nTotal number of Warning messages: %d", count);

    fclose(file);
    return 0;
}