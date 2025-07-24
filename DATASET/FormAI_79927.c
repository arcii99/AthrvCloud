//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    char email[50];
    char phone[15];
    char skills[100];
    char education[100];
    char experience[200];
} Resume;

void parseResume(Resume *resume, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) { // check if file exists
        printf("Error: File not found.\n");
        exit(EXIT_FAILURE);
    }
    char line[200];
    while (fgets(line, sizeof(line), file)) {
        char *key = strtok(line, ":"); // get key
        char *val = strtok(NULL, ""); // get value
        if (key && val) { // if key-value pair exists
            // remove newline character from value
            val[strcspn(val, "\n")] = 0;
            if (strcmp(key, "Name") == 0) {
                strcpy(resume->name, val);
            } else if (strcmp(key, "Email") == 0) {
                strcpy(resume->email, val);
            } else if (strcmp(key, "Phone") == 0) {
                strcpy(resume->phone, val);
            } else if (strcmp(key, "Skills") == 0) {
                strcpy(resume->skills, val);
            } else if (strcmp(key, "Education") == 0) {
                strcpy(resume->education, val);
            } else if (strcmp(key, "Experience") == 0) {
                strcpy(resume->experience, val);
            }
        }
    }
    fclose(file);
}

int main() {
    Resume resume;
    parseResume(&resume, "resume.txt");
    printf("Name: %s\nEmail: %s\nPhone: %s\nSkills: %s\nEducation: %s\nExperience: %s\n",
           resume.name, resume.email, resume.phone, resume.skills, resume.education, resume.experience);
    return 0;
}