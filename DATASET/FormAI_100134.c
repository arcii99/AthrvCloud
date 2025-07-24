//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data structure to store information about a resume
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char work_experience[500];
    char skills[500];
};

// Function to parse a resume and populate the data structure
void parse_resume(struct Resume *resume, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    char line[1000];
    while (fgets(line, 1000, file) != NULL) {
        if (strstr(line, "NAME:")) {
            strtok(line, " ");  // Skip "NAME:"
            strcpy(resume->name, strtok(NULL, "\n"));
        } else if (strstr(line, "EMAIL:")) {
            strtok(line, " ");  // Skip "EMAIL:"
            strcpy(resume->email, strtok(NULL, "\n"));
        } else if (strstr(line, "PHONE:")) {
            strtok(line, " ");  // Skip "PHONE:"
            strcpy(resume->phone, strtok(NULL, "\n"));
        } else if (strstr(line, "EDUCATION:")) {
            strtok(line, " ");  // Skip "EDUCATION:"
            strcpy(resume->education, strtok(NULL, "\n"));
        } else if (strstr(line, "WORK EXPERIENCE:")) {
            strtok(line, " ");  // Skip "WORK EXPERIENCE:"
            strcpy(resume->work_experience, strtok(NULL, "\n"));
        } else if (strstr(line, "SKILLS:")) {
            strtok(line, " ");  // Skip "SKILLS:"
            strcpy(resume->skills, strtok(NULL, "\n"));
        }
    }

    fclose(file);
}

// Function to print out the resume
void print_resume(struct Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Work Experience: %s\n", resume->work_experience);
    printf("Skills: %s\n", resume->skills);
}

int main() {
    struct Resume resume;
    parse_resume(&resume, "resume.txt");
    print_resume(&resume);
    return 0;
}