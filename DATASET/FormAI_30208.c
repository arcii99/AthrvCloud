//FormAI DATASET v1.0 Category: Text Summarizer ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 1000
#define MAX_SUMMARY 100

char* summarizer(char* input){
    char* summary = (char*) malloc(MAX_SUMMARY * sizeof(char));
    if (!summary) exit(1);
    // Check if input is valid
    if (!input){
        printf("Error: No input detected.\n");
        exit(1);
    }
    // Check if input is within range
    if (strlen(input) > MAX_INPUT){
        printf("Error: Input exceeds maximum character limit.");
        exit(1);
    }
    // Check for malicious code
    if (strchr(input, ';') || strstr(input, "system")){
        printf("Error: Possible malicious code detected.");
        exit(1);
    }
    // Summarize input
    strncpy(summary, input, MAX_SUMMARY);
    if (strlen(input) > MAX_SUMMARY){
        summary[MAX_SUMMARY-3] = '.';
        summary[MAX_SUMMARY-2] = '.';
        summary[MAX_SUMMARY-1] = '.';
        summary[MAX_SUMMARY] = '\0';
    }
    return summary;
}

int main(){
    char input[MAX_INPUT];
    char* summary;
    printf("Enter text to summarize:\n");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character
    summary = summarizer(input);
    printf("Summary: %s\n", summary);
    free(summary);
    return 0;
}