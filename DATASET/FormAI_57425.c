//FormAI DATASET v1.0 Category: Text Summarizer ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000 // Maximum number of lines that can be read from input file
#define MAX_SUMMARY_LEN 1000 // Maximum length of the summary

int main(int argc, char *argv[]) {
    
    // Check if filename is provided as input
    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        return 0;
    }

    // Open input file to be summarized
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    // Read input file line by line
    char lines[MAX_LINES][1000];
    int line_count = 0;
    while (fgets(lines[line_count], 1000, fp) != NULL && line_count < MAX_LINES) {
        line_count++;
    }

    // Initialize summary and summary length
    char summary[MAX_SUMMARY_LEN] = "";
    int summary_len = 0;

    // Extract keywords from input
    char *keywords[] = { "important", "critical", "urgent", "essential", "vital" };
    int keyword_count = sizeof(keywords) / sizeof(keywords[0]);

    // Loop through all lines to check for keywords and append to summary
    for (int i = 0; i < line_count && summary_len < MAX_SUMMARY_LEN; i++) {
        for (int j = 0; j < keyword_count; j++) {
            if (strstr(lines[i], keywords[j]) != NULL) {
                strcat(summary, lines[i]);
                summary_len += strlen(lines[i]);
                break;
            }
        }
    }

    // Print summary
    printf("%s\n", summary);

    // Clean up and exit
    fclose(fp);
    return 0;
}