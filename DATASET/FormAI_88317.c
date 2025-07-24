//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

struct Resume {
    char name[50];
    char phone[15];
    char email[50];
    char skills[100];
};

void parseResumeData(char *fileName, struct Resume *resume) {
    FILE *fp;
    char buffer[BUFFER_SIZE];
    char *token;
    const char delim[3] = "\t\n";

    // Open file
    fp = fopen(fileName, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Parse file data
    while (fgets(buffer, BUFFER_SIZE, fp) != NULL) {
        token = strtok(buffer, delim);
        // Check if token is valid
        if (token != NULL) {
            // Parse name field
            if (strcmp(token, "Name") == 0) {
                token = strtok(NULL, delim);
                if (token != NULL) {
                    strcpy(resume->name, token);
                }
            }
            // Parse phone field
            else if (strcmp(token, "Phone") == 0) {
                token = strtok(NULL, delim);
                if (token != NULL) {
                    strcpy(resume->phone, token);
                }
            }
            // Parse email field
            else if (strcmp(token, "Email") == 0) {
                token = strtok(NULL, delim);
                if (token != NULL) {
                    strcpy(resume->email, token);
                }
            }
            // Parse skills field
            else if (strcmp(token, "Skills") == 0) {
                int index = 0;
                while ((token = strtok(NULL, ",")) != NULL && index < 100) {
                    strcpy(resume->skills + strlen(resume->skills), token);
                    index++;
                }
            }
        }
    }

    fclose(fp);
}

void printResume(struct Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Phone: %s\n", resume.phone);
    printf("Email: %s\n", resume.email);
    printf("Skills: %s\n", resume.skills);
}

int main() {
    struct Resume resume;
    memset(&resume, 0, sizeof(resume));

    parseResumeData("resume.txt", &resume);

    printResume(resume);

    return 0;
}