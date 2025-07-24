//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_RESUME_LENGTH 10000
#define MAX_KEYWORDS 8

char* keywords[MAX_KEYWORDS] = {"C", "C++", "Java", "Python", "HTML", "CSS", "JavaScript", "MySQL"};

void parseResume(char* resume) {
    // Convert the entire resume to lowercase
    for (int i = 0; i < strlen(resume); i++) {
        resume[i] = tolower(resume[i]);
    }
    
    // Split the resume into individual words
    char* word = strtok(resume, " ,.-_");
    bool found_keywords[MAX_KEYWORDS] = {false}; // Initialize to false
    while (word != NULL) {
        // Check if the word matches any of the keywords
        for (int i = 0; i < MAX_KEYWORDS; i++) {
            if (strcmp(word, keywords[i]) == 0) {
                found_keywords[i] = true;
            }
        }
        word = strtok(NULL, " ,.-_");
    }
    
    // Print the results
    printf("\nKeywords found in resume:\n");
    bool found_any = false;
    for (int i = 0; i < MAX_KEYWORDS; i++) {
        if (found_keywords[i]) {
            printf("- %s\n", keywords[i]);
            found_any = true;
        }
    }
    if (!found_any) {
        printf("None\n");
    }
}

int main() {
    char resume[MAX_RESUME_LENGTH];
    printf("Enter your resume: ");
    fgets(resume, MAX_RESUME_LENGTH, stdin);
    parseResume(resume);
    
    return 0;
}