//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Define maximum string length for file paths and text strings
#define MAX_PATH_LENGTH 256
#define MAX_TEXT_LENGTH 1024

// Define structure to hold resume data
typedef struct {
    char name[MAX_TEXT_LENGTH];
    char email[MAX_TEXT_LENGTH];
    char phone[MAX_TEXT_LENGTH];
    char summary[MAX_TEXT_LENGTH];
    char skills[MAX_TEXT_LENGTH];
    char experience[MAX_TEXT_LENGTH];
    char education[MAX_TEXT_LENGTH];
} Resume;

// Define function to parse resume data from a text file
bool parse_resume(char* file_path, Resume* r) {
    // Initialize variables
    bool success = false;
    char line[MAX_TEXT_LENGTH];
    FILE* file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", file_path);
        return false;
    }

    // Loop through each line of the file and parse relevant data
    while (fgets(line, MAX_TEXT_LENGTH, file) != NULL) {
        // Parse name
        if (strstr(line, "Name:")) {
            sscanf(line, "Name: %[^\n]", r->name);
        }
        // Parse email
        if (strstr(line, "Email:")) {
            sscanf(line, "Email: %[^\n]", r->email);
        }
        // Parse phone number
        if (strstr(line, "Phone:")) {
            sscanf(line, "Phone: %[^\n]", r->phone);
        }
        // Parse summary
        if (strstr(line, "Summary:")) {
            char summary[MAX_TEXT_LENGTH] = "";
            while (fgets(line, MAX_TEXT_LENGTH, file) != NULL && !strstr(line, "---")) {
                strcat(summary, line);
            }
            strcpy(r->summary, summary);
        }
        // Parse skills
        if (strstr(line, "Skills:")) {
            char skills[MAX_TEXT_LENGTH] = "";
            while (fgets(line, MAX_TEXT_LENGTH, file) != NULL && !strstr(line, "---")) {
                strcat(skills, line);
            }
            strcpy(r->skills, skills);
        }
        // Parse experience
        if (strstr(line, "Experience:")) {
            char experience[MAX_TEXT_LENGTH] = "";
            while (fgets(line, MAX_TEXT_LENGTH, file) != NULL && !strstr(line, "---")) {
                strcat(experience, line);
            }
            strcpy(r->experience, experience);
        }
        // Parse education
        if (strstr(line, "Education:")) {
            char education[MAX_TEXT_LENGTH] = "";
            while (fgets(line, MAX_TEXT_LENGTH, file) != NULL && !strstr(line, "---")) {
                strcat(education, line);
            }
            strcpy(r->education, education);
        }
    }

    // Close file and set success flag
    fclose(file);
    success = true;
    return success;
}

int main() {
    // Initialize variables
    char file_path[MAX_PATH_LENGTH] = "";
    Resume r;

    // Prompt user for file path
    printf("Enter path of resume text file: ");
    fgets(file_path, MAX_PATH_LENGTH, stdin);
    file_path[strcspn(file_path, "\n")] = '\0';

    // Parse resume data from file
    bool success = parse_resume(file_path, &r);
    if (success) {
        // Print parsed resume data
        printf("Resume Parsed Successfully!\n");
        printf("============================\n");
        printf("Name: %s\n", r.name);
        printf("Email: %s\n", r.email);
        printf("Phone: %s\n", r.phone);
        printf("Summary: %s\n", r.summary);
        printf("Skills: %s\n", r.skills);
        printf("Experience: %s\n", r.experience);
        printf("Education: %s\n", r.education);
    } else {
        printf("Resume Parsing Failed!\n");
    }

    return 0;
}