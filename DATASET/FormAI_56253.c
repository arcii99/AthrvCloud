//FormAI DATASET v1.0 Category: Log analysis ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 10000
#define MAX_LINE_LENGTH 100

int main()
{
    FILE *file = fopen("example.log", "r");
    if (file == NULL)
    {
        printf("Failed to open file\n");
        return 1;
    }

    char lines[MAX_LINES][MAX_LINE_LENGTH];
    int num_lines = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        strncpy(lines[num_lines], line, MAX_LINE_LENGTH);
        num_lines++;
        if (num_lines >= MAX_LINES)
        {
            break;
        }
    }

    fclose(file);

    char *keywords[] = {"hack", "malware", "virus", "exploit", "payload", "payload2"};
    int num_keywords = 6;

    int keyword_counts[MAX_LINES];
    memset(keyword_counts, 0, sizeof(keyword_counts));

    for (int i = 0; i < num_lines; i++)
    {
        for (int j = 0; j < num_keywords; j++)
        {
            char *keyword = keywords[j];
            if (strstr(lines[i], keyword))
            {
                keyword_counts[i]++;
            }
        }
    }

    int num_suspicious_lines = 0;
    int suspicious_lines[MAX_LINES];
    memset(suspicious_lines, 0, sizeof(suspicious_lines));

    for (int i = 0; i < num_lines; i++)
    {
        if (keyword_counts[i] > 0)
        {
            suspicious_lines[num_suspicious_lines++] = i;
        }
    }

    printf("%d suspicious lines found:\n", num_suspicious_lines);
    for (int i = 0; i < num_suspicious_lines; i++)
    {
        int line_num = suspicious_lines[i];
        printf("%d: %s", line_num+1, lines[line_num]);
    }

    if (num_suspicious_lines > 0)
    {
        printf("Warning: possible security breach detected!\n");
        printf("Please contact your IT administrator immediately.\n");
    }
    else
    {
        printf("No suspicious activity detected.\n");
    }

    return 0;
}