//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main()
{
    char buffer[BUFFER_SIZE];
    int count = 0;
    FILE *fp;

    fp = fopen("logfile.txt", "r");

    if (fp == NULL)
    {
        printf("Error opening file");
        exit(1);
    }

    printf("Checking for Intrusions...\n");

    while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
    {
        if (strstr(buffer, "Invalid user") != NULL)
        {
            count++;
            printf("Intrusion detected on line %d\n", count);
        }
    }

    if (count > 0)
    {
        printf("%d intrusions detected. Taking action...\n", count);
        // Code to take action goes here
    }
    else
    {
        printf("No intrusions detected\n");
    }

    fclose(fp);

    return 0;
}