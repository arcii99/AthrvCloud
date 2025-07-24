//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    char email[50];
    float experience;
    char education[50];
} Resume;

int main() {
    Resume resumeList[10]; // Assuming we have 10 resumes to parse

    printf("=== Welcome to the Resume Parsing System ===\n");

    // Getting input from the user
    for (int i = 0; i < 10; i++) {
        printf("Enter Name: ");
        scanf("%s", resumeList[i].name);

        printf("Enter Email: ");
        scanf("%s", resumeList[i].email);

        printf("Enter Experience (in years): ");
        scanf("%f", &resumeList[i].experience);

        // Flushing the stdin buffer to avoid errors
        while(getchar() != '\n');

        printf("Enter Education: ");
        scanf("%s", resumeList[i].education);

        printf("\n");
    }

    // Parsing Resumes
    printf("*** Parsing Resumes ***\n");
    for (int i = 0; i < 10; i++) {
        printf("Resuming Parsing for %s...\n", resumeList[i].name);

        if (resumeList[i].experience >= 5) {
            printf("Congratulations! %s is shortlisted for further rounds.\n\n", resumeList[i].name);
        } else {
            printf("Unfortunately, %s is not eligible for further rounds.\n\n", resumeList[i].name);
        }
    }

    return 0;
}