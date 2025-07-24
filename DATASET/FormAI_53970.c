//FormAI DATASET v1.0 Category: Resume Parsing System ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define MAX_RESUMES 100

// Define the structure for a resume
typedef struct {
    char name[MAX_FIELD_LENGTH];
    char email[MAX_FIELD_LENGTH];
    char phone[MAX_FIELD_LENGTH];
    char skills[MAX_FIELD_LENGTH];
    char experience[MAX_FIELD_LENGTH];
    char education[MAX_FIELD_LENGTH];
} Resume;

// Define the function to parse a resume
void parse_resume(char *filename, Resume *resume) {
    // Open the file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    // Read the file line by line
    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        // Check if the line contains name
        if (strstr(line, "Name:")) {
            sscanf(line, "%*s %s", resume->name);
        }
        // Check if the line contains email
        if (strstr(line, "Email:")) {
            sscanf(line, "%*s %s", resume->email);
        }
        // Check if the line contains phone
        if (strstr(line, "Phone:")) {
            sscanf(line, "%*s %s", resume->phone);
        }
        // Check if the line contains skills
        if (strstr(line, "Skills:")) {
            sscanf(line, "%*s %[^\n]", resume->skills);
        }
        // Check if the line contains experience
        if (strstr(line, "Experience:")) {
            sscanf(line, "%*s %[^\n]", resume->experience);
        }
        // Check if the line contains education
        if (strstr(line, "Education:")) {
            sscanf(line, "%*s %[^\n]", resume->education);
        }
    }

    // Close the file
    fclose(fp);
}

int main() {
    // Define an array of resumes
    Resume resumes[MAX_RESUMES];

    // Parse each resume and add it to the array
    int num_resumes = 0;
    parse_resume("resume1.txt", &resumes[num_resumes++]);
    parse_resume("resume2.txt", &resumes[num_resumes++]);
    parse_resume("resume3.txt", &resumes[num_resumes++]);

    // Print the details of each resume
    for (int i = 0; i < num_resumes; i++) {
        printf("Resume %d:\n", i+1);
        printf("Name: %s\n", resumes[i].name);
        printf("Email: %s\n", resumes[i].email);
        printf("Phone: %s\n", resumes[i].phone);
        printf("Skills: %s\n", resumes[i].skills);
        printf("Experience: %s\n", resumes[i].experience);
        printf("Education: %s\n", resumes[i].education);
        printf("\n");
    }

    return 0;
}