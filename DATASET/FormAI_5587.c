//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    char address[50];
    char phone_num[15];
    char email[30];
    char skills[100];
    char experience[150];
    char education[100];
} Resume;

void print_resume(Resume r) {
    printf("\nName: %s\nAddress: %s\nPhone Number: %s\nEmail: %s\nSkills: %s\nExperience: %s\nEducation: %s\n", 
           r.name, r.address, r.phone_num, r.email, r.skills, r.experience, r.education);
}

int main() {
    char resume_str[] = "John Doe\n123 Main St\n555-555-5555\njohndoe@gmail.com\nJava, C++, Python\n5 years experience\nB.S. in Computer Science";
    Resume r;
    char *token;
    token = strtok(resume_str, "\n");
    strcpy(r.name, token);
    token = strtok(NULL, "\n");
    strcpy(r.address, token);
    token = strtok(NULL, "\n");
    strcpy(r.phone_num, token);
    token = strtok(NULL, "\n");
    strcpy(r.email, token);
    token = strtok(NULL, "\n");
    strcpy(r.skills, token);
    token = strtok(NULL, "\n");
    strcpy(r.experience, token);
    token = strtok(NULL, "\n");
    strcpy(r.education, token);
    print_resume(r);
    return 0;
}