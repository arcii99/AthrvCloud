//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024

void checkForIntrusion(char *line)
{
    char *suspiciousWords[] = {"root", "sudo", "hack", "password", "backdoor", "trojan", "malware", "virus"};
    int i;
    for (i = 0; i < sizeof(suspiciousWords) / sizeof(char *); i++)
    {
        if (strstr(line, suspiciousWords[i]))
        {
            printf("Intrusion detected: suspicious word '%s' found in input\n", suspiciousWords[i]);
            exit(0);
        }
    }
}

int main()
{
    FILE *inputFile;
    char line[MAX_LINE_LENGTH];

    printf("Starting Intrusion Detection System...\n");

    inputFile = fopen("input.log", "r");
    if (inputFile == NULL)
    {
        printf("Error: Unable to open input file\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE_LENGTH, inputFile))
    {
        checkForIntrusion(line);
    }

    printf("No intrusions found, system is secure\n");

    return 0;
}