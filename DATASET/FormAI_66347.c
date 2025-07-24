//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>

#define MAX_RESUME_SIZE 10000
#define MAX_KEYWORDS 500

int main()
{
    char resume[MAX_RESUME_SIZE];
    char keywords[MAX_KEYWORDS][50];
    int count_keywords = 0;
    int matches[MAX_KEYWORDS] = {0};
    int i, j, k;
    
    // Read in resume
    printf("Please enter your resume:\n");
    fgets(resume, MAX_RESUME_SIZE, stdin);

    // Read in keywords
    printf("\nPlease enter the keywords you would like to search for in your resume, separated by spaces:\n");
    char input[50];
    fgets(input, 50, stdin);
    char *token = strtok(input, " ");
    while (token != NULL) {
        // Remove newline character if present
        if (token[strlen(token)-1] == '\n') {
            token[strlen(token)-1] = '\0';
        }
        strcpy(keywords[count_keywords], token);
        count_keywords++;
        token = strtok(NULL, " ");
    }
    
    // Check for matches
    for (i = 0; i < count_keywords; i++) {
        char *word = keywords[i];
        for (j = 0; j < strlen(resume); j++) {
            if (resume[j] == word[0]) {
                int match = 1;
                for (k = 1; k < strlen(word); k++) {
                    if (resume[j+k] != word[k]) {
                        match = 0;
                        break;
                    }
                }
                if (match == 1) {
                    matches[i]++;
                }
            }
        }
    }
    
    // Print results
    printf("\nSearch Results:\n");
    for (i = 0; i < count_keywords; i++) {
        printf("'%s': %d matches\n", keywords[i], matches[i]);
    }
    
    return 0;
}