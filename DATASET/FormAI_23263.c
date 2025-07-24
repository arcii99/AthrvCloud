//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char* name;
    char* email;
    char* phone_number;
    char* university;
    char* degree;
    char* skills[10];
} Resume;

void parse_resume(char* input, Resume* resume) {
    char* token = strtok(input, "\n");
    while (token) {
        char* keyword = strtok(token, ":");
        char* value = strtok(NULL, ":");
        if (strcmp(keyword, "Name") == 0) {
            resume->name = value;
        } else if (strcmp(keyword, "Email") == 0) {
            resume->email = value;
        } else if (strcmp(keyword, "Phone Number") == 0) {
            resume->phone_number = value;
        } else if (strcmp(keyword, "University") == 0) {
            resume->university = value;
        } else if (strcmp(keyword, "Degree") == 0) {
            resume->degree = value;
        } else if (strcmp(keyword, "Skills") == 0) {
            char* skill = strtok(value, ",");
            int i = 0;
            while (skill) {
                resume->skills[i] = skill;
                skill = strtok(NULL, ",");
                i++;
            }
        }
        token = strtok(NULL, "\n");
    }
}

void print_resume(Resume* resume) {
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone Number: %s\n", resume->phone_number);
    printf("University: %s\n", resume->university);
    printf("Degree: %s\n", resume->degree);
    printf("Skills: ");
    int i = 0;
    while (resume->skills[i]) {
        printf("%s, ", resume->skills[i]);
        i++;
    }
    printf("\n");
}

int main() {
    char input[] = "Name: John Doe\nEmail: jdoe@email.com\nPhone Number: 123-456-7890\nUniversity: ABC University\nDegree: Bachelor of Science\nSkills: C++,Java,Python";
    Resume resume;
    memset(&resume, 0, sizeof(Resume));
    parse_resume(input, &resume);
    printf("Resume parsed successfully!\n");
    print_resume(&resume);
    return 0;
}