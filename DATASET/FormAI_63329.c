//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char address[100];
    char email[50];
    char phone_number[15];
    char education[200];
    char experience[500];
    char skills[500];
};

void printResume(struct Resume r) {
    printf("Name: %s\n", r.name);
    printf("Address: %s\n", r.address);
    printf("Email: %s\n", r.email);
    printf("Phone Number: %s\n", r.phone_number);
    printf("Education: %s\n", r.education);
    printf("Experience: %s\n", r.experience);
    printf("Skills: %s\n", r.skills);
}

int main() {
    struct Resume r;
    char resume_string[1500];

    printf("Enter your resume text:\n");
    fgets(resume_string, 1500, stdin);

    char *token = strtok(resume_string, "\n");

    while (token != NULL) {
        if (strstr(token, "Name: ") != NULL) {
            strcpy(r.name, token + 6);
        } else if (strstr(token, "Address: ") != NULL) {
            strcpy(r.address, token + 9);
        } else if (strstr(token, "Email: ") != NULL) {
            strcpy(r.email, token + 7);
        } else if (strstr(token, "Phone Number: ") != NULL) {
            strcpy(r.phone_number, token + 14);
        } else if (strstr(token, "Education: ") != NULL) {
            strcpy(r.education, token + 11);
        } else if (strstr(token, "Experience: ") != NULL) {
            strcpy(r.experience, token + 12);
        } else if (strstr(token, "Skills: ") != NULL) {
            strcpy(r.skills, token + 8);
        }
        token = strtok(NULL, "\n");
    }

    printf("\nParsed Resume:\n");
    printResume(r);

    return 0;
}