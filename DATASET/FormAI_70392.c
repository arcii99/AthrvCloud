//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Structure for storing information about a resume
struct Resume {
    char name[50];
    char email[50];
    char education[100];
    char experience[200];
};

// Function to parse a resume and store its information in a Resume struct
void parseResume(char *resumeText, struct Resume *resume) {
    char *resumeCopy = strdup(resumeText); // Make a writable copy of the resume
    char *token = strtok(resumeCopy, "\n"); // Split text into lines
    int lineNum = 1; // Keep track of which line we're on

    while (token != NULL) {
        // Switch based on which line we're on
        switch (lineNum) {
            case 1:
                strcpy(resume->name, token);
                break;
            case 3:
                strcpy(resume->email, token);
                break;
            case 5:
                strcpy(resume->education, token);
                break;
            case 7:
                strcpy(resume->experience, token);
                break;
            default:
                break;
        }

        token = strtok(NULL, "\n"); // Move to the next line
        lineNum++; // Increment the line number
    }

    free(resumeCopy); // Free the copy
}

int main() {
    char resumeText[] = "John Doe\n123 Main St\njohndoe@example.com\nBS Computer Science, XYZ University\nSoftware Developer, ABC Corp";
    struct Resume resume;

    parseResume(resumeText, &resume);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}