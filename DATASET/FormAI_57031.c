//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_RESUMES 100
#define MAX_SKILLS 10
#define MAX_LENGTH 256

typedef struct {
    char name[MAX_LENGTH];
    char email[MAX_LENGTH];
    char phone[MAX_LENGTH];
    char skills[MAX_SKILLS][MAX_LENGTH];
    int num_skills;
} Resume;

void parse_skills(char *line, Resume *resume) {
    char *token;
    token = strtok(line, ",");
    int count = 0;
    while (token != NULL && count < MAX_SKILLS) {
        strcpy(resume->skills[count], token);
        count++;
        token = strtok(NULL, ",");
    }
    resume->num_skills = count;
}

void read_resume(char *filename, Resume *resume) {
    FILE *fp;
    char line[MAX_LENGTH];
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    while (fgets(line, MAX_LENGTH, fp)) {
        if (strncmp(line, "Name:", 5) == 0) {
            sscanf(line + 6, "%[^\n]", resume->name);
        } else if (strncmp(line, "Email:", 6) == 0) {
            sscanf(line + 7, "%[^\n]", resume->email);
        } else if (strncmp(line, "Phone:", 6) == 0) {
            sscanf(line + 7, "%[^\n]", resume->phone);
        } else if (strncmp(line, "Skills:", 7) == 0) {
            parse_skills(line + 8, resume);
        }
    }
    fclose(fp);
}

void print_resume(Resume resume) {
    int i;
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Skills: ");
    for (i = 0; i < resume.num_skills; i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%s", resume.skills[i]);
    }
    printf("\n");
}

int main() {
    Resume resumes[MAX_RESUMES];
    int num_resumes = 0;
    char input[MAX_LENGTH];
    printf("Enter resume filename (or q to quit):\n");
    while (fgets(input, MAX_LENGTH, stdin) != NULL && input[0] != 'q') {
        input[strcspn(input, "\n")] = 0; // remove newline character
        read_resume(input, &resumes[num_resumes]);
        num_resumes++;
        if (num_resumes >= MAX_RESUMES) {
            printf("Maximum number of resumes reached.\n");
            break;
        }
        printf("Enter resume filename (or q to quit):\n");
    }
    printf("Parsed %d resumes.\n", num_resumes);
    printf("Enter a skill to search for:\n");
    fgets(input, MAX_LENGTH, stdin);
    input[strcspn(input, "\n")] = 0; // remove newline character
    int i, j;
    printf("Matching resumes:\n");
    for (i = 0; i < num_resumes; i++) {
        for (j = 0; j < resumes[i].num_skills; j++) {
            if (strcasecmp(input, resumes[i].skills[j]) == 0) {
                print_resume(resumes[i]);
                break;
            }
        }
    }
    return 0;
}