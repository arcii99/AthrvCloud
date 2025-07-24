//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char experience[1000];
} Resume;

// function to parse resume
Resume* parseResume(char* filename) {
    // open file for reading
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: could not open file %s.\n", filename);
        return NULL;
    }

    // allocate memory for Resume struct
    Resume* resume = (Resume*) malloc(sizeof(Resume));

    // read file line by line and extract relevant fields
    char line[1000];
    while (fgets(line, sizeof(line), file)) {
        // extract name
        if (strstr(line, "Name:") != NULL) {
            strtok(line, ":");
            strcpy(resume->name, strtok(NULL, "\n"));
        }

        // extract email
        if (strstr(line, "Email:") != NULL) {
            strtok(line, ":");
            strcpy(resume->email, strtok(NULL, "\n"));
        }

        // extract phone number
        if (strstr(line, "Phone:") != NULL) {
            strtok(line, ":");
            strcpy(resume->phone, strtok(NULL, "\n"));
        }

        // extract experience
        if (strstr(line, "Experience:") != NULL) {
            strcpy(resume->experience, "");
            while (fgets(line, sizeof(line), file)) {
                if (strcmp(line, "\n") == 0) break;
                strcat(resume->experience, line);
            }
        }
    }

    // close file
    fclose(file);

    return resume;
}

int main() {
    // parse resume and print fields
    Resume* resume = parseResume("resume.txt");
    if (resume != NULL) {
        printf("Name: %s\n", resume->name);
        printf("Email: %s\n", resume->email);
        printf("Phone: %s\n", resume->phone);
        printf("Experience: %s\n", resume->experience);
    }

    // free allocated memory
    free(resume);

    return 0;
}