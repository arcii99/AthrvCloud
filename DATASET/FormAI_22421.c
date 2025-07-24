//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <string.h>

// Struct for storing parsed resume information
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char education[100];
    char experience[200];
} resume;

// Function to parse resume information from a file
void parseResume(char* filename) {
    FILE* file = fopen(filename, "r");

    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), file)) {
        // Check for name
        if (strstr(line, "Name:") != NULL) {
            strtok(line, ":");
            strcpy(resume.name, strtok(NULL, ":"));
            continue;
        }

        // Check for email
        if (strstr(line, "Email:") != NULL) {
            strtok(line, ":");
            strcpy(resume.email, strtok(NULL, ":"));
            continue;
        }

        // Check for phone number
        if (strstr(line, "Phone:") != NULL) {
            strtok(line, ":");
            strcpy(resume.phone, strtok(NULL, ":"));
            continue;
        }

        // Check for education
        if (strstr(line, "Education:") != NULL) {
            strtok(line, ":");
            strcpy(resume.education, strtok(NULL, ":"));
            continue;
        }

        // Check for experience
        if (strstr(line, "Experience:") != NULL) {
            strtok(line, ":");
            strcpy(resume.experience, strtok(NULL, ":"));
            continue;
        }
    }

    fclose(file);
}

int main() {
    // Parse resume information from file
    parseResume("resume.txt");

    // Print parsed resume information
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);
    printf("Education: %s\n", resume.education);
    printf("Experience: %s\n", resume.experience);

    return 0;
}