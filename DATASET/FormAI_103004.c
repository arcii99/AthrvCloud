//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
    char education[100];
    char work_experience[300];
};

int main() {

    // Create an array of Resumes
    struct Resume resumes[10];

    // Add some Resume data
    strcpy(resumes[0].name, "John Doe");
    strcpy(resumes[0].email, "john.doe@gmail.com");
    strcpy(resumes[0].phone, "(555) 555-5555");
    strcpy(resumes[0].skills, "C++, Java, Python");
    strcpy(resumes[0].education, "Bachelor's degree in Computer Science");
    strcpy(resumes[0].work_experience, "Software Developer at ABC Inc. for 2 years");

    strcpy(resumes[1].name, "Jane Smith");
    strcpy(resumes[1].email, "jane.smith@yahoo.com");
    strcpy(resumes[1].phone, "(555) 555-1234");
    strcpy(resumes[1].skills, "HTML, CSS, JavaScript");
    strcpy(resumes[1].education, "Associate's degree in Web Development");
    strcpy(resumes[1].work_experience, "Web Designer at XYZ Corp. for 1 year");

    // Parse each Resume and print out the data
    for (int i = 0; i < 2; i++) {
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Education: %s\n", resumes[i].education);
        printf("Work Experience: %s\n", resumes[i].work_experience);
        printf("\n");
    }

    return 0;
}