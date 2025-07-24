//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JOBS 1000
#define MAX_KEYWORDS 10

// Job Structure
struct Job {
    int id;
    char title[50];
    char company[50];
    char location[50];
    char skills[100];
};

// Keyword Structure
struct Keyword {
    char word[20];
    int count;
};

int main() {
    // Initialize job array and keyword array
    struct Job jobs[MAX_JOBS];
    struct Keyword keywords[MAX_KEYWORDS];
    int jobCount = 0;
    int keywordCount = 0;

    // Read input file
    FILE *file = fopen("resume.txt", "r");
    if (file == NULL) {
        printf("Error opening file.");
        exit(1);
    }

    // Parse each line of the input file
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " ");
        int jobFlag = 0;
        int keywordFlag = 0;

        while (token != NULL) {

            // Check if the token is a job field
            if (strcmp(token, "Title:") == 0) {
                jobFlag = 1;
                keywordFlag = 0;
                strcpy(jobs[jobCount].title, strtok(NULL, "\n"));
            } else if (strcmp(token, "Company:") == 0) {
                strcpy(jobs[jobCount].company, strtok(NULL, "\n"));
            } else if (strcmp(token, "Location:") == 0) {
                strcpy(jobs[jobCount].location, strtok(NULL, "\n"));
            } else if (strcmp(token, "Skills:") == 0) {
                strcpy(jobs[jobCount].skills, strtok(NULL, "\n"));
                jobCount++;

            // Check if the token is a keyword
            } else {
                for (int i = 0; i < keywordCount; i++) {
                    if (strcmp(token, keywords[i].word) == 0) {
                        keywords[i].count++;
                        keywordFlag = 1;
                        jobFlag = 0;
                        break;
                    }
                }
                if (jobFlag == 0 && keywordFlag == 0) {
                    strcpy(keywords[keywordCount].word, token);
                    keywords[keywordCount].count = 1;
                    keywordCount++;
                }
            }
            token = strtok(NULL, " ");
        }
    }

    // Print job information
    printf("JOBS:\n");
    for (int i = 0; i < jobCount; i++) {
        printf("Job #%d: %s\n", jobs[i].id, jobs[i].title);
        printf("Company: %s\n", jobs[i].company);
        printf("Location: %s\n", jobs[i].location);
        printf("Skills: %s\n\n", jobs[i].skills);
    }

    // Print keyword information
    printf("KEYWORDS:\n");
    for (int i = 0; i < keywordCount; i++) {
        printf("%s: %d\n", keywords[i].word, keywords[i].count);
    }

    // Close file
    fclose(file);

    return 0;
}