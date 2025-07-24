//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_SIZE 1000
#define MAX_BUFFER_SIZE 100

// Function to extract keywords from the resume
void extractKeywords(char *resume, char *keywords[], int *keywordCount) {
    char *token;
    const char delim[2] = " ";

    // Get the first token
    token = strtok(resume, delim);

    while (token != NULL) {
        // Check if the token is a keyword
        for (int i = 0; i < *keywordCount; i++) {
            if (strcmp(token, keywords[i]) == 0) {
                // Do something with the keyword
                printf("Found keyword: %s\n", token);
            }
        }

        // Get the next token
        token = strtok(NULL, delim);
    }
}

int main() {
    char resume[MAX_RESUME_SIZE];
    char *keywords[] = {"C", "Python", "Java", "JavaScript", "PHP", "HTML", "CSS"};
    int keywordCount = sizeof(keywords) / sizeof(keywords[0]);

    // Load the resume from a file
    FILE *fp;
    fp = fopen("resume.txt", "r");
    
    if (fp == NULL) {
        perror("Error opening file");
        return 1;
    }
    
    char buffer[MAX_BUFFER_SIZE];
    while (fgets(buffer, MAX_BUFFER_SIZE, fp)) {
        strcat(resume, buffer);
    }

    fclose(fp);

    // Extract the keywords from the resume
    extractKeywords(resume, keywords, &keywordCount);

    return 0;
}