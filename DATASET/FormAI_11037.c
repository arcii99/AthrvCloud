//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to hold information about a resume
typedef struct {
    char name[50];
    char email[50];
    char phone[20];
    char education[50];
    char experience[100];
} Resume;

// Define a function to parse a resume given a file name
Resume* parse_resume(char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: file '%s' not found.\n", filename);
        exit(1);
    }

    // Allocate memory for the Resume struct
    Resume* resume = malloc(sizeof(Resume));

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Parse name
        if (strstr(line, "Name:")) {
            char* name = strtok(line + strlen("Name:"), "\n");
            strcpy(resume->name, name);
        }
        // Parse email
        else if (strstr(line, "Email:")) {
            char* email = strtok(line + strlen("Email:"), "\n");
            strcpy(resume->email, email);
        }
        // Parse phone number
        else if (strstr(line, "Phone:")) {
            char* phone = strtok(line + strlen("Phone:"), "\n");
            strcpy(resume->phone, phone);
        }
        // Parse education
        else if (strstr(line, "Education:")) {
            char* education = strtok(line + strlen("Education:"), "\n");
            strcpy(resume->education, education);
        }
        // Parse experience
        else if (strstr(line, "Experience:")) {
            char* experience = strtok(line + strlen("Experience:"), "\n");
            strcpy(resume->experience, experience);
        }
    }

    fclose(file);
    return resume;
}

int main() {
    // Parse a sample resume named "resume.txt"
    Resume* resume = parse_resume("resume.txt");

    // Print the parsed resume
    printf("Name: %s\n", resume->name);
    printf("Email: %s\n", resume->email);
    printf("Phone: %s\n", resume->phone);
    printf("Education: %s\n", resume->education);
    printf("Experience: %s\n", resume->experience);

    // Free memory allocated for the Resume struct
    free(resume);

    return 0;
}