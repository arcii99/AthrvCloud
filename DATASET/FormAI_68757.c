//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_RESUME_LENGTH 10000
#define MAX_NAME_LENGTH 50
#define MAX_SKILL_LENGTH 100
#define MAX_EXPERIENCE_LENGTH 200

typedef struct {
    char name[MAX_NAME_LENGTH];
    char email[MAX_NAME_LENGTH];
    char phone[MAX_NAME_LENGTH];
    char skills[MAX_SKILL_LENGTH];
    char experience[MAX_EXPERIENCE_LENGTH];
} Resume;

void parse_resume(char *resume_text, Resume *resume) {
    char *line = strtok(resume_text, "\n");
    while (line) {
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", resume->name);
        } else if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", resume->email);
        } else if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", resume->phone);
        } else if (strstr(line, "Skills:")) {
            sscanf(line, "Skills: %[^\n]", resume->skills);
        } else if (strstr(line, "Experience:")) {
            sscanf(line, "Experience: %[^\n]", resume->experience);
        }
        line = strtok(NULL, "\n");
    }
}

void print_resume(Resume *resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Skills: %s\n", resume->skills);
    printf("Experience: %s\n", resume->experience);
}

int main() {
    char resume_text[MAX_RESUME_LENGTH] = "Name: Emily Smith\nEmail: emsmith@email.com\nPhone: 555-1234\nSkills: ";
    strcat(resume_text, "Python, C++, Java\nExperience: 2 years as a software developer");
    Resume my_resume;
    parse_resume(resume_text, &my_resume);
    print_resume(&my_resume);
    return 0;
}