//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure for holding resume information
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char skills[100][50];
    int num_skills;
    char education[100][50];
    int num_education;
    char experience[100][50];
    int num_experience;
} Resume;

// Function to parse resume
Resume parseResume(char *filename) {
    Resume resume;
    FILE *fp;
    char line[100];
    char *token;

    // Initialize Resume
    memset(&resume, 0, sizeof(resume));

    // Open file
    fp = fopen(filename, "r");

    // Read each line in file
    while (fgets(line, sizeof(line), fp)) {
        // Remove newline character
        line[strcspn(line, "\n")] = '\0';

        // Tokenize line
        token = strtok(line, ",");

        // Handle each field
        while (token != NULL) {
            if (strstr(token, "@") != NULL) {
                // Email field
                strcpy(resume.email, token);
            } else if (isdigit(token[0])) {
                // Phone field
                strcpy(resume.phone, token);
            } else if (strcmp(token, "Name") == 0) {
                // Name field
                token = strtok(NULL, ",");
                strcpy(resume.name, token);
            } else if (strcmp(token, "Skills") == 0) {
                // Skills field
                token = strtok(NULL, ",");
                while (token != NULL) {
                    strcpy(resume.skills[resume.num_skills], token);
                    resume.num_skills++;
                    token = strtok(NULL, ",");
                }
            } else if (strcmp(token, "Education") == 0) {
                // Education field
                token = strtok(NULL, ",");
                while (token != NULL) {
                    strcpy(resume.education[resume.num_education], token);
                    resume.num_education++;
                    token = strtok(NULL, ",");
                }
            } else if (strcmp(token, "Experience") == 0) {
                // Experience field
                token = strtok(NULL, ",");
                while (token != NULL) {
                    strcpy(resume.experience[resume.num_experience], token);
                    resume.num_experience++;
                    token = strtok(NULL, ",");
                }
            }
            token = strtok(NULL, ",");
        }
    }

    // Close file
    fclose(fp);

    // Return parsed resume
    return resume;
}

int main() {
    Resume resume;
    resume = parseResume("resume.txt");

    // Print parsed resume
    printf("Name: %s\n", resume.name);
    printf("Email: %s\n", resume.email);
    printf("Phone: %s\n", resume.phone);

    printf("Skills:\n");
    for (int i = 0; i < resume.num_skills; i++) {
        printf("- %s\n", resume.skills[i]);
    }

    printf("Education:\n");
    for (int i = 0; i < resume.num_education; i++) {
        printf("- %s\n", resume.education[i]);
    }

    printf("Experience:\n");
    for (int i = 0; i < resume.num_experience; i++) {
        printf("- %s\n", resume.experience[i]);
    }

    return 0;
}