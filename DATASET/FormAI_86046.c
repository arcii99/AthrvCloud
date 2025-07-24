//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>

struct Resume {
    char name[50];
    char address[100];
    char phone[20];
    char email[50];
    char skills[200];
    char experience[500];
    char education[200];
};

int main() {
    struct Resume resume;
    char input[1000];
    char *token;

    printf("Please enter your resume details:\n\n");

    // prompt user for their name
    printf("Name: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.name, input);

    // prompt user for their address
    printf("Address: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.address, input);

    // prompt user for their phone number
    printf("Phone: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.phone, input);

    // prompt user for their email address
    printf("Email: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.email, input);

    // prompt user for their skills
    printf("Skills: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.skills, input);

    // prompt user for their work experience
    printf("Work Experience: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.experience, input);

    // prompt user for their education
    printf("Education: ");
    fgets(input, sizeof(input), stdin);
    strcpy(resume.education, input);

    // tokenize and print out the resume details
    printf("\n\nYour Resume:\n\n");

    token = strtok(resume.name, " \n");
    while (token != NULL) {
        printf("Name: %s\n", token);
        token = strtok(NULL, " \n");
    }

    printf("Address: %s", resume.address);
    printf("Phone: %s", resume.phone);
    printf("Email: %s", resume.email);
    printf("Skills: %s", resume.skills);
    printf("Work Experience: %s", resume.experience);
    printf("Education: %s", resume.education);

    return 0;
}