//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold resume information
typedef struct Resume {
    char name[50];
    char email[100];
    char phone[20];
    char address[200];
    char education[200];
    char work_experience[200];
    char skills[200];
} Resume;

// Function to parse resume and fill out the Resume structure
void parse_resume(char *resume_text, Resume *resume) {
    char *line;
    char *token;

    line = strtok(resume_text, "\n");

    while (line != NULL) {
        // Check if line starts with "Name:"
        if (strstr(line, "Name:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->name, token);
        }
        // Check if line starts with "Email:"
        if (strstr(line, "Email:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->email, token);    
        }
        // Check if line starts with "Phone:"
        if (strstr(line, "Phone:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->phone, token);
        }
        // Check if line starts with "Address:"
        if (strstr(line, "Address:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->address, token);
        }
        // Check if line starts with "Education:"
        if (strstr(line, "Education:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->education, token);
        }
        // Check if line starts with "Work Experience:"
        if (strstr(line, "Work Experience:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->work_experience, token);
        }
        // Check if line starts with "Skills:"
        if (strstr(line, "Skills:") != NULL) {
            token = strtok(line, " ");
            token = strtok(NULL, "\n");
            strcpy(resume->skills, token);
        }

        line = strtok(NULL, "\n");
    }
}

int main(void) {
    char resume_text[] = "Name: John Doe\nEmail: john.doe@gmail.com\nPhone: (555) 555-5555\nAddress: 123 Main St, Anytown USA\nEducation: Bachelor's Degree in Computer Science, AnyUniversity\nWork Experience: Software Engineer at AnyCompany for 3 years\nSkills: C++, Java, Python\n";
    Resume resume;

    parse_resume(resume_text, &resume);

    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Address: %s\n", resume.address);
    printf("Education: %s\n", resume.education);
    printf("Work Experience: %s\n", resume.work_experience);
    printf("Skills: %s\n", resume.skills);

    return 0;
}