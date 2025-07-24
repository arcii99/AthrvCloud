//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define struct for resume
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[500];
    char education[200];
    char experience[500];
} Resume;

int main() {

    // Declare resume struct and read file
    Resume resume;
    FILE *fp;
    fp = fopen("resume.txt", "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: File does not exist.");
        exit(1);
    }

    // Parse resume information
    char line[200];
    int count = 0;
    while (fgets(line, sizeof(line), fp)) {
        if (count == 0) {
            strcpy(resume.name, line);
        } else if (count == 1) {
            strcpy(resume.email, line);
        } else if (count == 2) {
            strcpy(resume.phone, line);
        } else if (count == 3) {
            strcpy(resume.skills, line);
        } else if (count == 4) {
            strcpy(resume.education, line);
        } else if (count == 5) {
            strcpy(resume.experience, line);
        }
        count++;
    }

    // Close file
    fclose(fp);

    // Print resume information
    printf("Resume Information:\n\n");
    printf("Name: %s", resume.name);
    printf("Email: %s", resume.email);
    printf("Phone: %s", resume.phone);
    printf("Skills: %s", resume.skills);
    printf("Education: %s", resume.education);
    printf("Experience: %s", resume.experience);

    return 0;
}