//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: Claude Shannon
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Define structure for storing resume information
struct Resume {
    char name[50];
    char email[50];
    char phone[20];
    char skills[200];
    char experience[500];
};

// Function to parse information from resume
void parseResume(char *filePath) {
    // Open file containing resume
    FILE *file = fopen(filePath, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    // Create instance of Resume structure
    struct Resume resume;

    // Loop through each line in file, parsing relevant information
    char line[500];
    while (fgets(line, sizeof(line), file)) {
        // Check if line contains email address
        if (strstr(line, "@") != NULL) {
            strcpy(resume.email, line);
        }
        // Check if line contains phone number
        else if (strstr(line, "phone") != NULL || strstr(line, "Phone") != NULL) {
            strcpy(resume.phone, line);
        }
        // Check if line contains skills
        else if (strstr(line, "Skills") != NULL || strstr(line, "skills") != NULL) {
            strcpy(resume.skills, line);
        }
        // Check if line contains experience information
        else if (strstr(line, "Experience") != NULL || strstr(line, "experience") != NULL) {
            // Read next 3 lines to get experience information
            fgets(line, sizeof(line), file);
            strcpy(resume.experience, line);
            fgets(line, sizeof(line), file);
            strcat(resume.experience, line);
            fgets(line, sizeof(line), file);
            strcat(resume.experience, line);
        }
        // Assume line contains name
        else {
            strcpy(resume.name, line);
        }
    }

    // Close file
    fclose(file);

    // Print parsed information
    printf("Name: %sEmail: %sPhone: %sSkills: %sExperience: %s\n", 
           resume.name, resume.email, resume.phone, resume.skills, resume.experience);
}

// Main function for running program
int main() {
    // Call function to parse resume
    parseResume("example_resume.txt");

    return 0;
}