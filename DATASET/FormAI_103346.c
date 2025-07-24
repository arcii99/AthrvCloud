//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGS 50
#define MAX_WORDS 10
#define MAX_WORD_LENGTH 20

int analyze_logs(char logs[][MAX_WORD_LENGTH], int num_logs);

int main()
{
    // Initialize array of logs
    char logs[MAX_LOGS][MAX_WORD_LENGTH];

    printf("Enter up to %d logs, each with up to %d words:\n", MAX_LOGS, MAX_WORDS);

    int num_logs = 0;
    while (num_logs < MAX_LOGS)
    {
        char line[MAX_WORDS * MAX_WORD_LENGTH];
        if (fgets(line, sizeof(line), stdin) == NULL || line[0] == '\n')
        {
            break;
        }

        int num_words = 0;
        char *word = strtok(line, " \n");
        while (word != NULL && num_words < MAX_WORDS)
        {
            strcpy(logs[num_logs], word);
            word = strtok(NULL, " \n");
            num_words++;
        }

        num_logs++;
    }

    int result = analyze_logs(logs, num_logs);

    if (result > 0) {
        printf("Intrusion detected.\n");
    } else {
        printf("No intrusion detected.\n");
    }

    return 0;
}

int analyze_logs(char logs[][MAX_WORD_LENGTH], int num_logs)
{
    int result = 0;

    // Check for suspicious keywords
    char *suspicious_keywords[] = {"hack", "password", "admin", "root", "network", "security", "virus", NULL};
    for (int i = 0; suspicious_keywords[i] != NULL; i++)
    {
        for (int j = 0; j < num_logs; j++)
        {
            if (strcmp(logs[j], suspicious_keywords[i]) == 0)
            {
                result++;
            }
        }
    }

    // Check for repeated IPs
    char *ip_addresses[MAX_LOGS];
    int ip_counts[MAX_LOGS] = {0};
    int num_ips = 0;
    for (int i = 0; i < num_logs; i++)
    {
        char *word = strchr(logs[i], '.');
        if (word != NULL && strchr(word + 1, '.') != NULL)
        {
            int match_index = -1;
            for (int j = 0; j < num_ips; j++)
            {
                if (strcmp(ip_addresses[j], logs[i]) == 0)
                {
                    match_index = j;
                }
            }

            if (match_index == -1)
            {
                ip_addresses[num_ips] = logs[i];
                ip_counts[num_ips] = 1;
                num_ips++;
            }
            else
            {
                ip_counts[match_index]++;
            }
        }
    }

    for (int i = 0; i < num_ips; i++)
    {
        if (ip_counts[i] > 5)
        {
            result++;
        }
    }

    return result;
}