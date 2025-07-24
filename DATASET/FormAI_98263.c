//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1000
#define MAX_CHARS_PER_LINE 1000
#define MAX_RESUMES 100

typedef struct {
    char name[50];
    char skills[500];
    char experience[50];
} Resume;

int count_lines(FILE *fp);
void parse_resumes(Resume *resumes, FILE *fp);
void print_resume(Resume resume);

int main() {
    FILE *fp;
    Resume resumes[MAX_RESUMES];

    fp = fopen("resumes.txt", "r");
    if (fp == NULL) {
        printf("Error: failed to open file.\n");
        exit(1);
    }

    int num_lines = count_lines(fp);
    if (num_lines < 2) {
        printf("Error: file contains invalid number of lines.\n");
        exit(1);
    }

    rewind(fp);  // Return to beginning of file

    parse_resumes(resumes, fp);

    fclose(fp);

    printf("Parsed %d resumes:\n", num_lines/2);
    for (int i = 0; i < num_lines/2; i++) {
        print_resume(resumes[i]);
    }

    return 0;
}

// Count the number of lines in a file
int count_lines(FILE *fp) {
    int count = 0;
    char buffer[MAX_CHARS_PER_LINE];

    while (fgets(buffer, MAX_CHARS_PER_LINE, fp)) {
        count++;
    }

    return count;
}

// Parse resumes from file
void parse_resumes(Resume *resumes, FILE *fp) {
    char buffer[MAX_CHARS_PER_LINE];
    int resume_index = 0;

    while(fgets(buffer, MAX_CHARS_PER_LINE, fp)) {
        Resume resume;

        // Read name
        strcpy(resume.name, buffer);
        resume.name[strlen(resume.name) - 1] = '\0';  // Remove newline character

        // Read skills
        fgets(buffer, MAX_CHARS_PER_LINE, fp);
        strcpy(resume.skills, buffer);
        resume.skills[strlen(resume.skills) - 1] = '\0';

        // Read experience
        fgets(buffer, MAX_CHARS_PER_LINE, fp);
        strcpy(resume.experience, buffer);
        resume.experience[strlen(resume.experience) - 1] = '\0';

        resumes[resume_index] = resume;
        resume_index++;
    }
}

// Print resume details
void print_resume(Resume resume) {
    printf("Name: %s\n", resume.name);
    printf("Skills: %s\n", resume.skills);
    printf("Experience: %s\n", resume.experience);
    printf("\n");
}